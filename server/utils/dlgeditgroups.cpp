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


#include <QtGui/QInputDialog>
#include <QtGui/QMessageBox>
#include "dlgeditgroups.h"

DlgEditGroups::DlgEditGroups(QWidget *parent, Qt::WindowFlags f):
	QDialog(parent), testManager(0), ui(new Ui::DlgEditGroups)
{
	ui->setupUi(this);
}

DlgEditGroups::~DlgEditGroups()
{
	delete ui;
}

void DlgEditGroups::setTestManager(TestManager *testManager)
{
	ui->lvGroups->clear();
	this->testManager = testManager;
	ui->lvGroups->addItems(this->testManager->getGroupsList());
	if(ui->lvGroups->count() != 0)
		ui->lvGroups->sortItems();
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
			ui->lvGroups->addItem(newGroup);
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