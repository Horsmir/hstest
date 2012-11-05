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


#include <QtGui/QFontDialog>
#include "dlgeditfonts.h"

DlgEditFonts::DlgEditFonts(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), ui(new Ui::EditFontsDialog)
{
	ui->setupUi(this);
}

DlgEditFonts::~DlgEditFonts()
{
	delete ui;
}

void DlgEditFonts::setFonts(QFont fTask, QFont fQuest, QFont fAnsw)
{
	this->fTask = fTask;
	this->fQuest = fQuest;
	this->fAnsw = fAnsw;
	
	ui->btnTask->setFont(this->fTask);
	ui->btnTask->setText(this->fTask.family());
	
	ui->btnQuest->setFont(this->fQuest);
	ui->btnQuest->setText(this->fQuest.family());
	
	ui->btnAnsw->setFont(this->fAnsw);
	ui->btnAnsw->setText(this->fAnsw.family());
}

void DlgEditFonts::on_btnTask_clicked()
{
	bool ok;
	QFont newFont = QFontDialog::getFont(&ok, fTask, this, trUtf8("Выберите шрифт для задания"));
	if(ok)
	{
		fTask = newFont;
		ui->btnTask->setFont(fTask);
		ui->btnTask->setText(fTask.family());
	}
}

void DlgEditFonts::on_btnQuest_clicked()
{
	bool ok;
	QFont newFont = QFontDialog::getFont(&ok, fQuest, this, trUtf8("Выберите шрифт для вопроса"));
	if(ok)
	{
		fQuest = newFont;
		ui->btnQuest->setFont(fQuest);
		ui->btnQuest->setText(fQuest.family());
	}
}

void DlgEditFonts::on_btnAnsw_clicked()
{
	bool ok;
	QFont newFont = QFontDialog::getFont(&ok, fAnsw, this, trUtf8("Выберите шрифт для ответа"));
	if(ok)
	{
		fAnsw = newFont;
		ui->btnAnsw->setFont(fAnsw);
		ui->btnAnsw->setText(fAnsw.family());
	}
}

void DlgEditFonts::getFonts(QFont &fTask, QFont &fQuest, QFont &fAnsw)
{
	fTask = this->fTask;
	fQuest = this->fQuest;
	fAnsw = this->fAnsw;
}

#include "dlgeditfonts.moc"