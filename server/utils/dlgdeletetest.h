/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

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


#ifndef DLGDELETETEST_H
#define DLGDELETETEST_H

#include <QtGui/QDialog>
#include "ui_dlgdeletetest.h"
#include "testdb.h"

namespace Ui
{
	class DlgDeleteTest;
}

class DlgDeleteTest : public QDialog
{
	Q_OBJECT
	
public:
    explicit DlgDeleteTest(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~DlgDeleteTest();
	
	void setCategories(TestDB *categories);
	
	QString getCategory() const;
	QString getTest() const;
	
private slots:
	void setTest(const QString &cat);
	
private:
	Ui::DlgDeleteTest *ui;
	TestDB *categories;
};

#endif // DLGDELETETEST_H
