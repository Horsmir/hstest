/*
    Show HTML-report.
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


#include "reportview.h"

ReportView::ReportView(QWidget *parent, const QString &report_file):
	QDialog(parent), reportFileName(report_file)
{
	verticalLayout = new QVBoxLayout(this);
	textEdit = new QTextEdit(this);
	
	textEdit->setReadOnly(true);
	verticalLayout->addWidget(textEdit);
	
	setWindowTitle(trUtf8("Просмотр результатов"));
}

ReportView::~ReportView()
{

}

void ReportView::load()
{
	QFile file(reportFileName);
	if(!file.open(QFile::ReadOnly | QFile::Text))
		qDebug() << "not file open " << file.errorString() << endl;
	else
	{
		QByteArray data = file.readAll();
		QTextCodec *codec = Qt::codecForHtml(data);
		QString str = codec->toUnicode(data);
		if (Qt::mightBeRichText(str))
		{
			textEdit->setHtml(str);
		}
	}
}

#include "reportview.moc"