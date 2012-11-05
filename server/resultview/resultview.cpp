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


#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtGui/QFileDialog>
#include <QtGui/QPrinter>
#include <QtGui/QTextDocument>
#include "resultview.h"

ResultView::ResultView(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), ui(new Ui::Dialog)
{
	ui->setupUi(this);
	resize(650, 270);
	
	ui->tableStudents->setHorizontalHeaderLabels(initHeaderTable());
	
	QString appDirPath = QCoreApplication::applicationDirPath();
	QDir appDir(appDirPath);
	QString iconsPath;
#ifdef Q_OS_LINUX
	appDir.cdUp();
	iconsPath = appDir.absolutePath() + "/share/hstest/icons/";
#endif
#ifdef Q_OS_WIN32
	iconsPath = appDir.absolutePath() + "/icons/";
#endif
	magicNumber = 0xAAFF452C;
	students = new StudentDb(this);
#ifdef Q_OS_LINUX
	appDir.cdUp();
	studentDbFileName = appDir.absolutePath() + "/var/lib/hstest/students.tst";
#endif
#ifdef Q_OS_WIN32
	studentDbFileName = appDir.absolutePath() + "/data/students.tst";
#endif
	readStudentDb();
	
	selectDialog = new DlgSelect(this);
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
	
	QString header = trUtf8("<h2 align=\"center\">Резултат тестирования</h2><p></p>");
	QString html = "<html><body>" + header + "<table border=\"1\" align=\"center\" width=\"90%\" cellspacing=\"0\" cellpadding=\"4\"><tr>";
	QStringList headerTable = initHeaderTable();
	for(int i = 0; i < headerTable.count(); i++)
	{
		html += "<th>" + headerTable.at(i) + "</th>";
	}
	html += "</tr>";
	for(int i = 0; i < ui->tableStudents->rowCount(); i++)
	{
		html += "<tr>";
		for(int j = 0; j < ui->tableStudents->columnCount(); j++)
		{
			if(j == 0 || j == 3)
				html += "<td align=\"left\">" + ui->tableStudents->item(i, j)->text() + "</td>";
			else
				html += "<td align=\"center\">" + ui->tableStudents->item(i, j)->text() + "</td>";
		}
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
	ui->tableStudents->clear();
	ui->tableStudents->setHorizontalHeaderLabels(initHeaderTable());
	ui->tableStudents->setRowCount(result.count());
	
	for(int i = 0; i < result.count(); i++)
	{
		for(int j = 0; j < ui->tableStudents->columnCount(); j++)
		{
			QTableWidgetItem *item = new QTableWidgetItem(result.at(i).at(j));
			ui->tableStudents->setItem(i, j, item);
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