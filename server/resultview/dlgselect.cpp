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

DlgSelect::DlgSelect(QWidget *parent, Qt::WindowFlags f): QDialog(parent, f)
{
	verticalLayout = new QVBoxLayout(this);
	chbDate = new QCheckBox(trUtf8("По дате"), this);
	
	verticalLayout->addWidget(chbDate);
	
	horizontalLayout = new QHBoxLayout();
	label = new QLabel(trUtf8("От: "), this);
	
	deFrom = new QDateEdit(this);
	deFrom->setDate(QDate(2012, 1, 1));
	deFrom->setDisplayFormat("dd.MM.yyyy");
	
	deFrom->setCalendarPopup(true);
	
	label_2 = new QLabel(trUtf8("До: "), this);
	
	deTo = new QDateEdit(this);
	deTo->setDate(QDate(2013, 1, 1));
	deTo->setDisplayFormat("dd.MM.yyyy");
	deTo->setCalendarPopup(true);
	
	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	
	horizontalLayout->addWidget(label);
	horizontalLayout->addWidget(deFrom);
	horizontalLayout->addItem(horizontalSpacer);
	horizontalLayout->addWidget(label_2);
	horizontalLayout->addWidget(deTo);
	
	verticalLayout->addLayout(horizontalLayout);
	
	line = new QFrame(this);
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	
	verticalLayout->addWidget(line);
	
	chbGroup = new QCheckBox(trUtf8("По группе"), this);
	cbGroup = new QComboBox(this);
	
	line_2 = new QFrame(this);
	line_2->setFrameShape(QFrame::HLine);
	line_2->setFrameShadow(QFrame::Sunken);
	
	verticalLayout->addWidget(chbGroup);
	verticalLayout->addWidget(cbGroup);
	verticalLayout->addWidget(line_2);
	
	chbName = new QCheckBox(trUtf8("По имени"), this);
	leName = new QLineEdit(this);
	
	line_3 = new QFrame(this);
	line_3->setFrameShape(QFrame::HLine);
	line_3->setFrameShadow(QFrame::Sunken);
	
	verticalLayout->addWidget(chbName);
	verticalLayout->addWidget(leName);
	verticalLayout->addWidget(line_3);
	
	buttonBox = new QDialogButtonBox(this);
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	buttonBox->setCenterButtons(true);
	
	verticalLayout->addWidget(buttonBox);
	
	deFrom->setDisabled(true);
	deTo->setDisabled(true);
	cbGroup->setDisabled(true);
	leName->setDisabled(true);
	
	setWindowTitle(trUtf8("Выбор результатов"));
	
	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
	connect(chbDate, SIGNAL(stateChanged(int)), SLOT(on_chbDate_checked(int)));
	connect(chbGroup, SIGNAL(stateChanged(int)), SLOT(on_chbGroups_checked(int)));
	connect(chbName, SIGNAL(stateChanged(int)), SLOT(on_chbName_checked(int)));
}

DlgSelect::~DlgSelect()
{

}

QDate DlgSelect::getDateFrom() const
{
	return deFrom->date();
}

QDate DlgSelect::getDateTo() const
{
	return deTo->date();
}

QString DlgSelect::getGroupName() const
{
	return cbGroup->currentText();
}

QString DlgSelect::getStudentName() const
{
	return leName->text();
}

void DlgSelect::on_chbDate_checked(int on)
{
	if(on == Qt::Checked)
	{
		deFrom->setEnabled(true);
		deTo->setEnabled(true);
	}
	else
	{
		deFrom->setDisabled(true);
		deTo->setDisabled(true);
	}
}

void DlgSelect::on_chbGroups_checked(int on)
{
	if(on == Qt::Checked)
		cbGroup->setEnabled(true);
	else
		cbGroup->setDisabled(true);
}

void DlgSelect::on_chbName_checked(int on)
{
	if(on == Qt::Checked)
		leName->setEnabled(true);
	else
		leName->setDisabled(true);
}

void DlgSelect::getCheckeds(bool &chDate, bool &chGroup, bool &chName)
{
	chDate = chbDate->isChecked();
	chGroup = chbGroup->isChecked();
	chName = chbName->isChecked();
}

void DlgSelect::setGroups(QStringList groups)
{
	cbGroup->clear();
	groups.sort();
	cbGroup->addItems(groups);
}

#include "dlgselect.moc"