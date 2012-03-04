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


#ifndef REPORTVIEW_H
#define REPORTVIEW_H

#include <QtCore/QDebug>
#include <QtGui/QDialog>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTextEdit>
#include <QtCore/QFile>
#include <QtCore/QTextCodec>


class ReportView : public QDialog
{
	Q_OBJECT
	
public:
	explicit ReportView(QWidget *parent = 0, const QString &report_file = "report.html");
    virtual ~ReportView();
	
	void load();
	
private:
	QVBoxLayout *verticalLayout;
	QTextEdit *textEdit;
	QString reportFileName;
};

#endif // REPORTVIEW_H
