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


#include "dlgeditfonts.h"

DlgEditFonts::DlgEditFonts(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent)
{
	verticalLayout = new QVBoxLayout(this);
	formLayout = new QFormLayout();
	formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
	formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
	
	label = new QLabel(trUtf8("Задание:"), this);
	btnTask = new QPushButton(this);
	label_2 = new QLabel(trUtf8("Вопрос:"), this);
	btnQuest = new QPushButton(this);
	label_3 = new QLabel(trUtf8("Ответ:"), this);
	btnAnsw = new QPushButton(this);
	
	formLayout->setWidget(0, QFormLayout::LabelRole, label);
	formLayout->setWidget(0, QFormLayout::FieldRole, btnTask);
	formLayout->setWidget(1, QFormLayout::LabelRole, label_2);
	formLayout->setWidget(1, QFormLayout::FieldRole, btnQuest);
	formLayout->setWidget(2, QFormLayout::LabelRole, label_3);
	formLayout->setWidget(2, QFormLayout::FieldRole, btnAnsw);
	
	verticalLayout->addLayout(formLayout);
	
	buttonBox = new QDialogButtonBox(this);
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	buttonBox->setCenterButtons(true);
	
	verticalLayout->addWidget(buttonBox);
	
	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
	connect(btnTask, SIGNAL(clicked(bool)), SLOT(on_btnTask_clicked()));
	connect(btnQuest, SIGNAL(clicked(bool)), SLOT(on_btnQuest_clicked()));
	connect(btnAnsw, SIGNAL(clicked(bool)), SLOT(on_btnAnsw_clicked()));	
}

DlgEditFonts::~DlgEditFonts()
{

}

void DlgEditFonts::setFonts(QFont fTask, QFont fQuest, QFont fAnsw)
{
	this->fTask = fTask;
	this->fQuest = fQuest;
	this->fAnsw = fAnsw;
	
	btnTask->setFont(this->fTask);
	btnTask->setText(this->fTask.family());
	
	btnQuest->setFont(this->fQuest);
	btnQuest->setText(this->fQuest.family());
	
	btnAnsw->setFont(this->fAnsw);
	btnAnsw->setText(this->fAnsw.family());
}

void DlgEditFonts::on_btnTask_clicked()
{
	bool ok;
	QFont newFont = QFontDialog::getFont(&ok, fTask, this, trUtf8("Выберите шрифт для задания"));
	if(ok)
	{
		fTask = newFont;
		btnTask->setFont(fTask);
		btnTask->setText(fTask.family());
	}
}

void DlgEditFonts::on_btnQuest_clicked()
{
	bool ok;
	QFont newFont = QFontDialog::getFont(&ok, fQuest, this, trUtf8("Выберите шрифт для вопроса"));
	if(ok)
	{
		fQuest = newFont;
		btnQuest->setFont(fQuest);
		btnQuest->setText(fQuest.family());
	}
}

void DlgEditFonts::on_btnAnsw_clicked()
{
	bool ok;
	QFont newFont = QFontDialog::getFont(&ok, fAnsw, this, trUtf8("Выберите шрифт для ответа"));
	if(ok)
	{
		fAnsw = newFont;
		btnAnsw->setFont(fAnsw);
		btnAnsw->setText(fAnsw.family());
	}
}

void DlgEditFonts::getFonts(QFont &fTask, QFont &fQuest, QFont &fAnsw)
{
	fTask = this->fTask;
	fQuest = this->fQuest;
	fAnsw = this->fAnsw;
}

#include "dlgeditfonts.moc"