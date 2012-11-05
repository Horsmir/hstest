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


#ifndef DLGADDBINTEST_H
#define DLGADDBINTEST_H

#include <QtGui/QDialog>
#include "ui_dlgaddbintest.h"
#include "test.h"

namespace Ui
{
	class DlgAddBinTest;
}

class DlgAddBinTest : public QDialog
{
	Q_OBJECT
	
public:
	explicit DlgAddBinTest(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~DlgAddBinTest();
	
	void setTest(Test *test);
	void setCat(const QStringList &catList);
	void setMagicNumber(quint32 magicNumber);
	
	QString getCatName() const;
	QString getTestName() const;
	quint32 getNumVis() const;
	bool getVis() const;
	
private slots:
	void on_tbtnOpenFile_clicked();
	
private:
	Ui::DlgAddBinTest *ui;
	
	Test *test;
	quint32 magicNumber;
	
	void readTest(const QString &fileName);
};

#endif // DLGADDBINTEST_H
