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


#include "dlgedittest.h"
#include <QFile>

DlgEditTest::DlgEditTest(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), tests(0)
{
	verticalLayout = new QVBoxLayout(this);
	formLayout = new QFormLayout();
	formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
	formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
	
	cbCat = new QComboBox(this);
	label = new QLabel(trUtf8("Категория: "), this);
	cbTest = new QComboBox(this);
	label_2 = new QLabel(trUtf8("Тест: "), this);
	labelNumTasks = new QLabel(this);
	label_3 = new QLabel(trUtf8("Всего вопросов:"), this);
	sbNumVis = new QSpinBox(this);
	sbNumVis->setMaximum(1000);
	label_4 = new QLabel(trUtf8("Видимых вопросов:"), this);
	chbVis = new QCheckBox(trUtf8("Видимый для клиента"), this);
	buttonBox = new QDialogButtonBox(this);
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	buttonBox->setCenterButtons(true);
	
	formLayout->setWidget(1, QFormLayout::FieldRole, cbCat);
	formLayout->setWidget(1, QFormLayout::LabelRole, label);
	formLayout->setWidget(2, QFormLayout::FieldRole, cbTest);
	formLayout->setWidget(2, QFormLayout::LabelRole, label_2);
	formLayout->setWidget(3, QFormLayout::FieldRole, labelNumTasks);
	formLayout->setWidget(3, QFormLayout::LabelRole, label_3);
	formLayout->setWidget(4, QFormLayout::FieldRole, sbNumVis);
	formLayout->setWidget(4, QFormLayout::LabelRole, label_4);
	verticalLayout->addLayout(formLayout);
	verticalLayout->addWidget(chbVis);
	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	verticalLayout->addItem(verticalSpacer);
	verticalLayout->addWidget(buttonBox);
	
	setWindowTitle(trUtf8("Изменить тест"));
	
	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
	connect(cbCat, SIGNAL(currentIndexChanged(QString)), SLOT(setTest(QString)));
	connect(cbTest, SIGNAL(currentIndexChanged(QString)), SLOT(setParamTest(QString)));
}

DlgEditTest::~DlgEditTest()
{

}

QString DlgEditTest::getCategory() const
{
	return cbCat->currentText();
}

quint32 DlgEditTest::getNumVis() const
{
	return sbNumVis->value();
}

QString DlgEditTest::getTest() const
{
	return cbTest->currentText();
}

bool DlgEditTest::getVis() const
{
	return chbVis->isChecked();
}

void DlgEditTest::setTestManager(TestManager *tests)
{
	this->tests = tests;
	cbCat->clear();
	cbCat->addItems(tests->getCategoryList());
	cbCat->setCurrentIndex(0);
}

void DlgEditTest::setTest(const QString &cat)
{
	cbTest->clear();
	cbTest->addItems(tests->getTestListByCategory(cat, true));
	cbTest->setCurrentIndex(0);
	setParamTest(cbTest->currentText());
}

void DlgEditTest::setParamTest(const QString &test)
{
	QString cat = cbCat->currentText();
	Test currTest = tests->getTest(cat, test);
	labelNumTasks->setNum(currTest.getCount());
	sbNumVis->setValue(currTest.getNumVis());
	sbNumVis->setMaximum(currTest.getCount());
	chbVis->setChecked(currTest.getVis());
}

#include "dlgedittest.moc"