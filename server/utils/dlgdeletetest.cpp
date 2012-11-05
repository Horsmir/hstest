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


#include "dlgdeletetest.h"

DlgDeleteTest::DlgDeleteTest(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), categories(0), ui(new Ui::DlgDeleteTest)
{
	ui->setupUi(this);
}

DlgDeleteTest::~DlgDeleteTest()
{
	delete ui;
}

QString DlgDeleteTest::getCategory() const
{
	return ui->cbCat->currentText();
}

QString DlgDeleteTest::getTest() const
{
	return ui->cbTest->currentText();
}

void DlgDeleteTest::setCategories(TestDB *categories)
{
	this->categories = categories;
	ui->cbCat->clear();
	ui->cbCat->addItems(this->categories->getCategoryNameList());
	ui->cbCat->setCurrentIndex(0);
	setTest(ui->cbCat->currentText());
}

void DlgDeleteTest::setTest(const QString &cat)
{
	ui->cbTest->clear();
	ui->cbTest->addItems(categories->getTestNameListByCategory(cat, true));
	ui->cbTest->setCurrentIndex(0);
}

#include "dlgdeletetest.moc"