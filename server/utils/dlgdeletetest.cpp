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
	QDialog(parent)
{
	verticalLayout = new QVBoxLayout(this);
	label = new QLabel(trUtf8("Категория: "), this);
	cbCat = new QComboBox(this);
	label_2 = new QLabel(trUtf8("Тест: "), this);
	cbTest = new QComboBox(this);
	verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);
	buttonBox = new QDialogButtonBox(this);
	
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	buttonBox->setCenterButtons(true);
	
	verticalLayout->addWidget(label);
	verticalLayout->addWidget(cbCat);
	verticalLayout->addWidget(label_2);
	verticalLayout->addWidget(cbTest);
	verticalLayout->addItem(verticalSpacer);
	verticalLayout->addWidget(buttonBox);
	
	setWindowTitle(trUtf8("Удалить тест"));
	
	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
	connect(cbCat, SIGNAL(currentIndexChanged(QString)), SLOT(setTest(QString)));
}

DlgDeleteTest::~DlgDeleteTest()
{

}

QString DlgDeleteTest::getCategory() const
{
	return cbCat->currentText();
}

QString DlgDeleteTest::getTest() const
{
	return cbTest->currentText();
}

void DlgDeleteTest::setCategories(TestDB *categories)
{
	this->categories = categories;
	cbCat->clear();
	cbCat->addItems(this->categories->getCategoryNameList());
	cbCat->setCurrentIndex(0);
	setTest(cbCat->currentText());
}

void DlgDeleteTest::setTest(const QString &cat)
{
	cbTest->clear();
	cbTest->addItems(categories->getTestNameListByCategory(cat, true));
	cbTest->setCurrentIndex(0);
}

#include "dlgdeletetest.moc"