/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

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


#include "dlgaddtest.h"

DlgAddTest::DlgAddTest ( QWidget* parent, Qt::WindowFlags f ) : QDialog ( parent)
{
	verticalLayout = new QVBoxLayout(this);
	horizontalLayout = new QHBoxLayout();
	label = new QLabel(trUtf8("Файл: "), this);
	
	horizontalLayout->addWidget(label);
	
	leTestFileName = new QLineEdit(this);
	
	horizontalLayout->addWidget(leTestFileName);
	
	toolBtnFileOpen = new QToolButton(this);
	horizontalLayout->addWidget(toolBtnFileOpen);
	
	verticalLayout->addLayout(horizontalLayout);
	
	horizontalLayout_2 = new QHBoxLayout();
	label_2 = new QLabel(trUtf8("Количество отображаемых заданий: "), this);
	
	horizontalLayout_2->addWidget(label_2);
	
	leNumVis = new QLineEdit();
	horizontalLayout_2->addWidget(leNumVis);
	
	verticalLayout->addLayout(horizontalLayout_2);
	
	chbVis = new QCheckBox(trUtf8("Видимый для клиента."), this);
	verticalLayout->addWidget(chbVis);
	
	horizontalLayout_4 = new QHBoxLayout();
	label_3 = new QLabel(trUtf8("Категория: "), this);
	cbCats = new QComboBox(this);
	horizontalLayout_4->addWidget(label_3);
	horizontalLayout_4->addWidget(cbCats);
	
	verticalLayout->addLayout(horizontalLayout_4);
	
	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	
	verticalLayout->addItem(verticalSpacer);
	
	horizontalLayout_3 = new QHBoxLayout();
	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	horizontalLayout_3->addItem(horizontalSpacer);
	btnAdd = new QPushButton(trUtf8("Добавить"), this);
	horizontalLayout_3->addWidget(btnAdd);
	btnCancel = new QPushButton(trUtf8("Отмена"), this);
	horizontalLayout_3->addWidget(btnCancel);
	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	horizontalLayout_3->addItem(horizontalSpacer_2);
	
	verticalLayout->addLayout(horizontalLayout_3);
	
	connect(btnAdd, SIGNAL(clicked()), SLOT(accept()));
	connect(btnCancel, SIGNAL(clicked()), SLOT(reject()));
	connect(toolBtnFileOpen, SIGNAL(clicked(bool)), SLOT(on_toolBtnFileOpen_clicked()));
}

quint32 DlgAddTest::getNumVis() const
{
	return leNumVis->text().toUInt();
}

QString DlgAddTest::getTestTextFileName() const
{
	return leTestFileName->text();
}

bool DlgAddTest::getVis() const
{
	return chbVis->isChecked();
}

void DlgAddTest::on_toolBtnFileOpen_clicked()
{
	QFileDialog::Options options;
	options |= QFileDialog::DontUseNativeDialog;
	QString selectedFilter;
	QString fileName = QFileDialog::getOpenFileName(this, trUtf8("Открыть файл с тестом"), leTestFileName->text(), trUtf8("Текстовые файлы (*.txt);;Все файлы (*)"), &selectedFilter, options);
	if (!fileName.isEmpty())
		leTestFileName->setText(fileName);
}

void DlgAddTest::setCats ( const QStringList& cats )
{
	cbCats->addItems(cats);
	cbCats->setCurrentIndex(0);
}

QString DlgAddTest::getCat() const
{
	return cbCats->currentText();
}

#include "dlgaddtest.moc"