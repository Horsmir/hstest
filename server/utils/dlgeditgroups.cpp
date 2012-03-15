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


#include "dlgeditgroups.h"

DlgEditGroups::DlgEditGroups(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), testManager(0)
{
	verticalLayout_2 = new QVBoxLayout(this);
	label = new QLabel(trUtf8("Группы:"), this);
	
	verticalLayout_2->addWidget(label);
	
	horizontalLayout = new QHBoxLayout();
	lvGroups = new QListWidget(this);
	lvGroups->setFrameShape(QFrame::StyledPanel);
	lvGroups->setFrameShadow(QFrame::Sunken);
	lvGroups->setEditTriggers(QAbstractItemView::NoEditTriggers);
	
	horizontalLayout->addWidget(lvGroups);
	
	verticalLayout = new QVBoxLayout();
	btnAdd = new QPushButton(trUtf8("&Добавить"), this);
	
	verticalLayout->addWidget(btnAdd);
	
	btnDel = new QPushButton(trUtf8("&Удалить"), this);
	
	verticalLayout->addWidget(btnDel);
	
	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	
	verticalLayout->addItem(verticalSpacer);
	
	btnExit = new QPushButton(trUtf8("&Закрыть"), this);
	
	verticalLayout->addWidget(btnExit);
	
	horizontalLayout->addLayout(verticalLayout);
	
	verticalLayout_2->addLayout(horizontalLayout);
	
#ifndef QT_NO_SHORTCUT
	label->setBuddy(lvGroups);
#endif // QT_NO_SHORTCUT
	
	connect(btnExit, SIGNAL(clicked()), SLOT(close()));
	connect(btnAdd, SIGNAL(clicked(bool)), SLOT(on_btnAdd_clicked()));
	connect(btnDel, SIGNAL(clicked(bool)), SLOT(on_btnDel_clocked()));
}

DlgEditGroups::~DlgEditGroups()
{

}

void DlgEditGroups::setTestManager(TestManager *testManager)
{
	lvGroups->clear();
	this->testManager = testManager;
	lvGroups->addItems(this->testManager->getGroupsList());
	if(lvGroups->count() != 0)
		lvGroups->sortItems();
}

void DlgEditGroups::on_btnAdd_clicked()
{
	bool ok;
	int id = -1;
	QString newGroup = QInputDialog::getText(this, trUtf8("Добавить группу"), trUtf8("Группа:"), QLineEdit::Normal, "", &ok);
	if(ok && !newGroup.isEmpty())
	{
		if((id = testManager->getGroupsList().indexOf(newGroup)) == -1)
		{
			testManager->addGroup(newGroup);
			testManager->writeStudentDbToFile();
			lvGroups->addItem(newGroup);
		}
		else
		{
			QMessageBox::information(this, trUtf8("Новая группа"), trUtf8("Группа \"") + newGroup + trUtf8("\" уже существует!"));
		}
	}
}

void DlgEditGroups::on_btnDel_clocked()
{

}

#include "dlgeditgroups.moc"