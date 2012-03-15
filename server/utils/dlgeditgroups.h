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


#ifndef DLGEDITGROUPS_H
#define DLGEDITGROUPS_H

#include <QtGui/QDialog>
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QListWidget>
#include <QtGui/QInputDialog>
#include <QtGui/QMessageBox>
#include "testmanager.h"


class DlgEditGroups : public QDialog
{
	Q_OBJECT
	
public:
	explicit DlgEditGroups(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~DlgEditGroups();
	
	void setTestManager(TestManager *testManager);
	
private slots:
	void on_btnAdd_clicked();
	void on_btnDel_clocked();
	
private:
	QVBoxLayout *verticalLayout_2;
	QLabel *label;
	QHBoxLayout *horizontalLayout;
	QListWidget *lvGroups;
	QVBoxLayout *verticalLayout;
	QPushButton *btnAdd;
	QPushButton *btnDel;
	QSpacerItem *verticalSpacer;
	QPushButton *btnExit;
	
	TestManager *testManager;
};

#endif // DLGEDITGROUPS_H
