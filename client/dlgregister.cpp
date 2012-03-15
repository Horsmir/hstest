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

DlgRegister::DlgRegister(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent)
{
	verticalLayout_2 = new QVBoxLayout(this);
	horizontalLayout = new QHBoxLayout();
	label = new QLabel(trUtf8("Режим:"), this);
	cbMode = new QComboBox(this);
	cbMode->addItem(trUtf8("Тренировочный"));
	cbMode->addItem(trUtf8("Экзаменационный"));
	cbMode->setCurrentIndex(0);
	
	horizontalLayout->addWidget(label);
	horizontalLayout->addWidget(cbMode);
	
	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	horizontalLayout->addItem(horizontalSpacer);
	
	verticalLayout_2->addLayout(horizontalLayout);
	
	groupBox = new QGroupBox(this);
	verticalLayout = new QVBoxLayout(groupBox);
	label_2 = new QLabel(trUtf8("Введите имя и фамилию:"), groupBox);
	leFio = new QLineEdit(groupBox);
	
	label_3 = new QLabel(trUtf8("Выберите группу:"), groupBox);
	cbGroups = new QComboBox(groupBox);
	
	verticalLayout->addWidget(label_2);
	verticalLayout->addWidget(leFio);
	verticalLayout->addWidget(label_3);
	verticalLayout->addWidget(cbGroups);
	
	verticalLayout_2->addWidget(groupBox);
	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	verticalLayout_2->addItem(verticalSpacer);
	
	buttonBox = new QDialogButtonBox(this);
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	buttonBox->setCenterButtons(true);
	
	verticalLayout_2->addWidget(buttonBox);
	
#ifndef QT_NO_SHORTCUT
	label->setBuddy(cbMode);
	label_2->setBuddy(leFio);
	label_3->setBuddy(cbGroups);
#endif // QT_NO_SHORTCUT
	
	groupBox->setVisible(false);
	
	setWindowTitle(trUtf8("Выбор режима тестирования"));
	
	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
	connect(cbMode, SIGNAL(currentIndexChanged(int)), SLOT(on_cbMode_currentIndexChanged(int)));
	connect(leFio, SIGNAL(textChanged(QString)), SLOT(on_leFio_textChanged()));
}

DlgRegister::~DlgRegister()
{

}

QString DlgRegister::getGroupName() const
{
	return cbGroups->currentText();
}

QString DlgRegister::getStudentName() const
{
	return leFio->text();
}

int DlgRegister::getMode() const
{
	return cbMode->currentIndex();
}

void DlgRegister::on_cbMode_currentIndexChanged(int index)
{
	if(index == 0)
	{
		groupBox->setVisible(false);
		buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	}
	else if(index == 1)
	{
		groupBox->setVisible(true);
		if(leFio->text().isEmpty())
			buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
	}
}

void DlgRegister::on_leFio_textChanged()
{
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void DlgRegister::setGroups(QStringList groups)
{
	groups.sort();
	cbGroups->addItems(groups);
}

#include "dlgregister.moc"