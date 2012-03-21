/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Роман Браун <firdragon76@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "resultview.h"

ResultView::ResultView(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent)
{
	resize(650, 270);
	verticalLayout = new QVBoxLayout(this);
	horizontalLayout = new QHBoxLayout();
	btnSelect = new QPushButton(trUtf8("&Выбрать..."), this);
	btnShowAll = new QPushButton(trUtf8("&Показать все"), this);
	btnPrint = new QPushButton(trUtf8("Экспорт в PDF"), this);
	
	horizontalLayout->addWidget(btnSelect);
	horizontalLayout->addWidget(btnShowAll);
	horizontalLayout->addWidget(btnPrint);
	
	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	
	horizontalLayout->addItem(horizontalSpacer);
	
	btnExit = new QPushButton(trUtf8("&Закрыть"), this);
	
	horizontalLayout->addWidget(btnExit);
	
	verticalLayout->addLayout(horizontalLayout);
	
	tableStudents = new QTableWidget(this);
	tableStudents->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableStudents->setColumnCount(6);
	tableStudents->setHorizontalHeaderLabels(initHeaderTable());
	
	verticalLayout->addWidget(tableStudents);
	
	magicNumber = 0xAAFF452C;
	students = new StudentDb(this);
	studentDbFileName = "../../var/lib/hstest/students.tst";
	readStudentDb();
	
	selectDialog = new DlgSelect(this);
	
	QString appDirPath = QCoreApplication::applicationDirPath();
	QDir appDir(appDirPath);
	appDir.cdUp();
	QString iconsPath = appDir.absolutePath() + "/share/hstest/icons/";
	
	QIcon logo;
	logo.addPixmap(QPixmap(iconsPath + "hstestcfg.svg"));
	setWindowIcon(logo);
	setWindowTitle(trUtf8("Результаты тестирования"));
	
	connect(btnExit, SIGNAL(clicked()), SLOT(close()));
	connect(btnSelect, SIGNAL(clicked(bool)), SLOT(on_btnSelect_clicked()));
	connect(btnShowAll, SIGNAL(clicked(bool)), SLOT(on_btnShowAll_clicked()));
	connect(btnPrint, SIGNAL(clicked(bool)), SLOT(on_btnPrint_clicked()));
}

ResultView::~ResultView()
{

}

void ResultView::on_btnSelect_clicked()
{
	QDate dateFrom, dateTo;
	QString group, studentName;
	bool chDate = false, chGroups = false, chName = false;
	QList<QStringList> studView;
	
	selectDialog->setGroups(students->getGroups());
	if(selectDialog->exec() == QDialog::Accepted)
	{
		selectDialog->getCheckeds(chDate, chGroups, chName);
		dateFrom = selectDialog->getDateFrom();
		dateTo = selectDialog->getDateTo();
		group = selectDialog->getGroupName();
		studentName = selectDialog->getStudentName();
		
		studView = students->select(chDate, chGroups, chName, dateFrom, dateTo, group, studentName);
		showResult(studView);
	}
}

void ResultView::on_btnShowAll_clicked()
{
	QList<QStringList> studView;
	studView = students->select();
	showResult(studView);
}

void ResultView::on_btnPrint_clicked()
{
	QFileDialog::Options options;
	options |= QFileDialog::DontUseNativeDialog;
	QString selectedFilter;
	QString pdfFileName = QFileDialog::getSaveFileName(this, trUtf8("Экспорт в PDF"), "", trUtf8("PDF файлы (*.pdf);;Все файлы (*)"), &selectedFilter, options);
	if(pdfFileName.isEmpty())
		pdfFileName = "result.pdf";
	
	QPrinter printer;
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setOutputFileName(pdfFileName);
	
	QString html = "<html><body><table border=\"1\"><tr>";
	QStringList headerTable = initHeaderTable();
	for(int i = 0; i < headerTable.count(); i++)
	{
		html += "<th border=\"2\">" + headerTable.at(i) + "</th>";
	}
	html += "</tr>";
	for(int i = 0; i < tableStudents->rowCount(); i++)
	{
		html += "<tr>";
		for(int j = 0; j < tableStudents->columnCount(); j++)
			html += "<td border=\"1\">" + tableStudents->item(i, j)->text() + "</td>";
		html += "</tr>";
	}
	html += "</table></body></html>";
	
	QTextDocument doc;
	doc.setHtml(html);
	doc.print(&printer);
}

void ResultView::readStudentDb()
{
	QFile file(studentDbFileName);
	quint32 magic;
	quint16 streamVersion;
	StudentDb newStudentDb(this);
	
	if(!file.exists())
	{
		qDebug() << "ERROR: File " << studentDbFileName << " no exist.";
		return;
	}
	if(!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "ERROR: Cannot open file for reading: " << file.errorString();
		return;
	}
	
	QDataStream in(&file);
	in >> magic >> streamVersion;
	
	if(magic != magicNumber)
	{
		qDebug() << "ERROR: File is not recognized by this application";
		return;
	}
	else if(streamVersion > in.version())
	{
		qDebug() << "ERROR: File is from a more recent version of the application";
		return;
	}
	
	in >> newStudentDb;
	*students = newStudentDb;
}

void ResultView::showResult(QList< QStringList > result)
{
	tableStudents->clear();
	tableStudents->setHorizontalHeaderLabels(initHeaderTable());
	tableStudents->setRowCount(result.count());
	
	for(int i = 0; i < result.count(); i++)
	{
		for(int j = 0; j < tableStudents->columnCount(); j++)
		{
			QTableWidgetItem *item = new QTableWidgetItem(result.at(i).at(j));
			tableStudents->setItem(i, j, item);
		}
	}
}

QStringList ResultView::initHeaderTable()
{
	QStringList ret;
	ret << trUtf8("И. Ф. студента");
	ret << trUtf8("Группа");
	ret << trUtf8("Дата");
	ret << trUtf8("Тест");
	ret << trUtf8("Процент");
	ret << trUtf8("Оценка");
	return ret;
}

#include "resultview.moc"