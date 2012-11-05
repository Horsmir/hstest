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


#include "dlgselect.h"

DlgSelect::DlgSelect(QWidget *parent, Qt::WindowFlags f): QDialog(parent, f), ui(new Ui::SelectDialog)
{
	ui->setupUi(this);
	ui->deFrom->setDate(QDate::currentDate());
	ui->deTo->setDate(QDate(QDate::currentDate().year() + 1, 1, 1));
}

DlgSelect::~DlgSelect()
{
	delete ui;
}

QDate DlgSelect::getDateFrom() const
{
	return ui->deFrom->date();
}

QDate DlgSelect::getDateTo() const
{
	return ui->deTo->date();
}

QString DlgSelect::getGroupName() const
{
	return ui->cbGroup->currentText();
}

QString DlgSelect::getStudentName() const
{
	return ui->leName->text();
}

void DlgSelect::on_chbDate_stateChanged(int on)
{
	if(on == Qt::Checked)
	{
		ui->deFrom->setEnabled(true);
		ui->deTo->setEnabled(true);
	}
	else
	{
		ui->deFrom->setDisabled(true);
		ui->deTo->setDisabled(true);
	}
}

void DlgSelect::on_chbGroups_stateChanged(int on)
{
	if(on == Qt::Checked)
		ui->cbGroup->setEnabled(true);
	else
		ui->cbGroup->setDisabled(true);
}

void DlgSelect::on_chbName_stateChanged(int on)
{
	if(on == Qt::Checked)
		ui->leName->setEnabled(true);
	else
		ui->leName->setDisabled(true);
}

void DlgSelect::getCheckeds(bool &chDate, bool &chGroup, bool &chName)
{
	chDate = ui->chbDate->isChecked();
	chGroup = ui->chbGroup->isChecked();
	chName = ui->chbName->isChecked();
}

void DlgSelect::setGroups(QStringList groups)
{
	ui->cbGroup->clear();
	groups.sort();
	ui->cbGroup->addItems(groups);
}

#include "dlgselect.moc"