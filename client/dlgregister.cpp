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


#include "dlgregister.h"
#include <QtGui/QPushButton>

DlgRegister::DlgRegister(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), ui(new Ui::DlgRegister)
{
	ui->setupUi(this);
	ui->groupBox->hide();
}

DlgRegister::~DlgRegister()
{
	delete ui;
}

QString DlgRegister::getGroupName() const
{
	return ui->cbGroups->currentText();
}

QString DlgRegister::getStudentName() const
{
	return ui->leFio->text();
}

int DlgRegister::getMode() const
{
	return ui->cbMode->currentIndex();
}

void DlgRegister::on_cbMode_currentIndexChanged(int index)
{
	if(index == 0)
	{
		ui->groupBox->setVisible(false);
		ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	}
	else if(index == 1)
	{
		ui->groupBox->setVisible(true);
		if(ui->leFio->text().isEmpty())
			ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
	}
}

void DlgRegister::on_leFio_textChanged()
{
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void DlgRegister::setGroups(QStringList groups)
{
	ui->cbGroups->clear();
	groups.sort();
	ui->cbGroups->addItems(groups);
}

#include "dlgregister.moc"