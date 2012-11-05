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


#include <QtGui/QFileDialog>
#include "dlgaddtest.h"

DlgAddTest::DlgAddTest ( QWidget* parent, Qt::WindowFlags f ) : QDialog ( parent), ui(new Ui::DlgAddTest)
{
	ui->setupUi(this);
}

DlgAddTest::~DlgAddTest()
{
	delete ui;
}

quint32 DlgAddTest::getNumVis() const
{
	return ui->leNumVis->value();
}

QString DlgAddTest::getTestTextFileName() const
{
	return ui->leTestFileName->text();
}

bool DlgAddTest::getVis() const
{
	return ui->chbVis->isChecked();
}

void DlgAddTest::on_toolBtnFileOpen_clicked()
{
	QFileDialog::Options options;
	options |= QFileDialog::DontUseNativeDialog;
	QString selectedFilter;
	QString fileName = QFileDialog::getOpenFileName(this, trUtf8("Открыть файл с тестом"), ui->leTestFileName->text(), trUtf8("Текстовые файлы (*.txt);;Все файлы (*)"), &selectedFilter, options);
	if (!fileName.isEmpty())
		ui->leTestFileName->setText(fileName);
}

void DlgAddTest::setCats ( const QStringList& cats )
{
	ui->cbCats->addItems(cats);
	ui->cbCats->setCurrentIndex(0);
}

QString DlgAddTest::getCat() const
{
	return ui->cbCats->currentText();
}

void DlgAddTest::clear()
{
	ui->leTestFileName->clear();
	ui->leNumVis->clear();
	ui->chbVis->setCheckState(Qt::Unchecked);
	ui->cbCats->clear();
}

#include "dlgaddtest.moc"