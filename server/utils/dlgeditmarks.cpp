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

DlgEditMarks::DlgEditMarks(QWidget *parent, Qt::WindowFlags f): QDialog(parent, f)
{
	verticalLayout = new QVBoxLayout(this);
	label_6 = new QLabel(trUtf8("Установите необходимые значения в %"), this);
	
	verticalLayout->addWidget(label_6);
	
	horizontalLayout = new QHBoxLayout();
	label = new QLabel(trUtf8("2 балла: от 0,00 "), this);
	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	label_4 = new QLabel(trUtf8("до"), this);
	dsbPer2 = new QDoubleSpinBox(this);
	
	horizontalLayout->addWidget(label);
	horizontalLayout->addItem(horizontalSpacer);
	horizontalLayout->addWidget(label_4);
	horizontalLayout->addWidget(dsbPer2);
	
	horizontalLayout_2 = new QHBoxLayout();
	label_3 = new QLabel(trUtf8("3 балла: от "), this);
	labelPer2 = new QLabel(this);
	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	label_2 = new QLabel(trUtf8("до"), this);
	dsbPer3 = new QDoubleSpinBox(this);
	
	horizontalLayout_2->addWidget(label_3);
	horizontalLayout_2->addWidget(labelPer2);
	horizontalLayout_2->addItem(horizontalSpacer_2);
	horizontalLayout_2->addWidget(label_2);
	horizontalLayout_2->addWidget(dsbPer3);
	
	horizontalLayout_3 = new QHBoxLayout();
	label_5 = new QLabel(trUtf8("4 балла: от "), this);
	labelPer3 = new QLabel(this);
	horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	label_8 = new QLabel(trUtf8("до"), this);
	dsbPer4 = new QDoubleSpinBox(this);
	
	horizontalLayout_3->addWidget(label_5);
	horizontalLayout_3->addWidget(labelPer3);
	horizontalLayout_3->addItem(horizontalSpacer_3);
	horizontalLayout_3->addWidget(label_8);
	horizontalLayout_3->addWidget(dsbPer4);
	
	horizontalLayout_4 = new QHBoxLayout();
	label_9 = new QLabel(trUtf8("5 балла: от "), this);
	labelPer4 = new QLabel(this);
	label_11 = new QLabel(trUtf8("до 100"), this);
	horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	
	horizontalLayout_4->addWidget(label_9);
	horizontalLayout_4->addWidget(labelPer4);
	horizontalLayout_4->addWidget(label_11);
	horizontalLayout_4->addItem(horizontalSpacer_4);
	
	buttonBox = new QDialogButtonBox(this);
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	buttonBox->setCenterButtons(true);
	
	verticalLayout->addLayout(horizontalLayout);
	verticalLayout->addLayout(horizontalLayout_2);
	verticalLayout->addLayout(horizontalLayout_3);
	verticalLayout->addLayout(horizontalLayout_4);
	verticalLayout->addWidget(buttonBox);
	
	setWindowTitle(trUtf8("Шкала баллов"));
	
	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
	connect(dsbPer2, SIGNAL(valueChanged(QString)), SLOT(on_dsbPer2_changed(QString)));
	connect(dsbPer3, SIGNAL(valueChanged(QString)), SLOT(on_dsbPer3_changed(QString)));
	connect(dsbPer4, SIGNAL(valueChanged(QString)), SLOT(on_dsbPer4_changed(QString)));
}

DlgEditMarks::~DlgEditMarks()
{

}

void DlgEditMarks::setPercents(float per2, float per3, float per4)
{
	dsbPer2->setValue(per2);
	dsbPer3->setValue(per3);
	dsbPer4->setValue(per4);
}

void DlgEditMarks::getPercents(float &per2, float &per3, float &per4)
{
	per2 = dsbPer2->value();
	per3 = dsbPer3->value();
	per4 = dsbPer4->value();
}

void DlgEditMarks::on_dsbPer2_changed(const QString &text)
{
	labelPer2->setText(text);
}

void DlgEditMarks::on_dsbPer3_changed(const QString &text)
{
	labelPer3->setText(text);
}

void DlgEditMarks::on_dsbPer4_changed(const QString &text)
{
	labelPer4->setText(text);
}

#include "dlgeditmarks.moc"