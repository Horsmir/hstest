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


#include "dlgeditmarks.h"

DlgEditMarks::DlgEditMarks(QWidget *parent, Qt::WindowFlags f): QDialog(parent, f), ui(new Ui::DlgEditMarks)
{
	ui->setupUi(this);
}

DlgEditMarks::~DlgEditMarks()
{
	delete ui;
}

void DlgEditMarks::setPercents(float per2, float per3, float per4)
{
	ui->dsbPer2->setValue(per2);
	ui->dsbPer3->setValue(per3);
	ui->dsbPer4->setValue(per4);
}

void DlgEditMarks::getPercents(float &per2, float &per3, float &per4)
{
	per2 = ui->dsbPer2->value();
	per3 = ui->dsbPer3->value();
	per4 = ui->dsbPer4->value();
}

void DlgEditMarks::on_dsbPer2_changed(const QString &text)
{
	ui->labelPer2->setText(text);
}

void DlgEditMarks::on_dsbPer3_changed(const QString &text)
{
	ui->labelPer3->setText(text);
}

void DlgEditMarks::on_dsbPer4_changed(const QString &text)
{
	ui->labelPer4->setText(text);
}

#include "dlgeditmarks.moc"