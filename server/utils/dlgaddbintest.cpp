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


#include <QtGui/QFileDialog>
#include "dlgaddbintest.h"

DlgAddBinTest::DlgAddBinTest(QWidget *parent, Qt::WindowFlags f): QDialog(parent, f), ui(new Ui::DlgAddBinTest)
{
	ui->setupUi(this);
}

DlgAddBinTest::~DlgAddBinTest()
{
	delete ui;
}

void DlgAddBinTest::setCat(const QStringList &catList)
{
	ui->cbCat->clear();
	ui->cbCat->addItems(catList);
}

void DlgAddBinTest::setTest(Test *test)
{
	this->test = test;
}

QString DlgAddBinTest::getCatName() const
{
	return ui->cbCat->currentText();
}

void DlgAddBinTest::on_tbtnOpenFile_clicked()
{
	QFileDialog::Options options;
	options |= QFileDialog::DontUseNativeDialog;
	QString selectedFilter;
	QString fileName = QFileDialog::getOpenFileName(this, trUtf8("Открыть файл с тестом"), QDir::homePath(), trUtf8("Тестовые файлы (*.tst);;Все файлы (*)"), &selectedFilter, options);
	if(!fileName.isEmpty())
		readTest(fileName);
}

void DlgAddBinTest::readTest(const QString &fileName)
{
	quint32 magic;
	quint16 streamVersion;
	QFile file(fileName);
	
	if(!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Can not open file " << fileName << " for reading. Error: " << file.errorString();
		return;
	}
	
	QDataStream in(&file);
	in >> magic >> streamVersion;
	if(magic != magicNumber)
	{
		qDebug() << "File is not recognized by this application";
		return;
	}
	else if(streamVersion > in.version())
	{
		qDebug() << "File is from a more recent version of the" << "application";
		return;
	}
	
	in >> *test;
	
	ui->leTestFilePath->setText(fileName);
	ui->leTestName->setText(test->getName());
	ui->labelNumAll->setNum(test->getCount());
	ui->sbNumVis->setMaximum(test->getCount());
	ui->sbNumVis->setValue(test->getNumVis());
	if(test->checkVis())
		ui->checkBox->setCheckState(Qt::Checked);
	else
		ui->checkBox->setCheckState(Qt::Unchecked);
}

void DlgAddBinTest::setMagicNumber(quint32 magicNumber)
{
	this->magicNumber = magicNumber;
}

quint32 DlgAddBinTest::getNumVis() const
{
	return ui->sbNumVis->value();
}

QString DlgAddBinTest::getTestName() const
{
	return ui->leTestName->text();
}

bool DlgAddBinTest::getVis() const
{
	if(ui->checkBox->checkState() == Qt::Checked)
		return true;
	else
		return false;
}

#include "dlgaddbintest.moc"