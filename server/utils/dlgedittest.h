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


#ifndef DLGEDITTEST_H
#define DLGEDITTEST_H

#include <QtGui/QDialog>
#include "ui_dlgedittest.h"
#include "testmanager.h"

namespace Ui
{
	class DlgEditTest;
}

class DlgEditTest : public QDialog
{
	Q_OBJECT
	
public:
	explicit DlgEditTest(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~DlgEditTest();
	
	void setTestManager(TestManager *tests);
	
	QString getCategory() const;
	QString getTest() const;
	quint32 getNumVis() const;
	bool getVis() const;
	
	void clear();
	
private slots:
	void on_cbCat_currentIndexChanged(const QString &cat);
	void on_cbTest_currentIndexChanged(const QString &test);
	void on_btnEditTest_clicked();
	
private:
	Ui::DlgEditTest *ui;
	TestManager *tests;
};

#endif // DLGEDITTEST_H
