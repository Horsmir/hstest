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


#include <QtCore/QProcess>
#include <QtCore/QFile>
#include "dlgedittest.h"

DlgEditTest::DlgEditTest(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), tests(0), ui(new Ui::DlgEditTest)
{
	ui->setupUi(this);
}

DlgEditTest::~DlgEditTest()
{
	delete ui;
}

QString DlgEditTest::getCategory() const
{
	return ui->cbCat->currentText();
}

quint32 DlgEditTest::getNumVis() const
{
	return ui->sbNumVis->value();
}

QString DlgEditTest::getTest() const
{
	return ui->cbTest->currentText();
}

bool DlgEditTest::getVis() const
{
	return ui->chbVis->isChecked();
}

void DlgEditTest::setTestManager(TestManager *tests)
{
	this->tests = tests;
	ui->cbCat->clear();
	QStringList catsList = tests->getCategoryList();
	catsList.sort();
	ui->cbCat->addItems(catsList);
	ui->cbCat->setCurrentIndex(0);
}

void DlgEditTest::on_cbCat_currentIndexChanged(const QString &cat)
{
	ui->cbTest->clear();
	QStringList testsList = tests->getTestListByCategory(cat, true);
	testsList.sort();
	ui->cbTest->addItems(testsList);
	ui->cbTest->setCurrentIndex(0);
	on_cbTest_currentIndexChanged(ui->cbTest->currentText());
}

void DlgEditTest::on_cbTest_currentIndexChanged(const QString &test)
{
	QString cat = ui->cbCat->currentText();
	Test currTest = tests->getTest(cat, test);
	ui->labelNumTasks->setNum(currTest.getCount());
	ui->sbNumVis->clear();
	ui->sbNumVis->setMaximum(currTest.getCount());
	ui->sbNumVis->setValue(currTest.getNumVis());
	ui->chbVis->setChecked(currTest.getVis());
}

void DlgEditTest::on_btnEditTest_clicked()
{
	QProcess *proc = new QProcess(this);
	QStringList args;
	args << (tests->getTestDir() + "/" + tests->getTestFileName(ui->cbCat->currentText(), ui->cbTest->currentText()));
	
	proc->start("hstesteditor", args);
}

void DlgEditTest::clear()
{
	ui->cbCat->clear();
	ui->cbTest->clear();
	ui->sbNumVis->clear();
	ui->labelNumTasks->clear();
}

#include "dlgedittest.moc"