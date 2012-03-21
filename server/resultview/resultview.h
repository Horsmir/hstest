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


#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <QtCore/QDebug>
#include <QtCore/QCoreApplication>
#include <QtGui/QDialog>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtCore/QFile>
#include <QtGui/QPrinter>
#include <QtGui/QTextDocument>
#include <QtGui/QFileDialog>
#include <QtCore/QDir>
#include "studentdb.h"
#include "dlgselect.h"


class ResultView : public QDialog
{
	Q_OBJECT
	
public:
	explicit ResultView(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~ResultView();
	
	void showResult(QList<QStringList> result);
	
private slots:
	void on_btnSelect_clicked();
	void on_btnShowAll_clicked();
	void on_btnPrint_clicked();
	
private:
	QVBoxLayout *verticalLayout;
	QHBoxLayout *horizontalLayout;
	QPushButton *btnSelect;
	QPushButton *btnShowAll;
	QPushButton *btnPrint;
	QSpacerItem *horizontalSpacer;
	QPushButton *btnExit;
	QTableWidget *tableStudents;
	
	quint32 magicNumber;
	StudentDb *students;
	QString studentDbFileName;
	
	DlgSelect *selectDialog;
	
	void readStudentDb();
	QStringList initHeaderTable();
};

#endif // RESULTVIEW_H
