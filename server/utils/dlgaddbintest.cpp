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


#include "dlgaddbintest.h"

DlgAddBinTest::DlgAddBinTest(QWidget *parent, Qt::WindowFlags f): QDialog(parent, f)
{
	verticalLayout = new QVBoxLayout(this);
	label = new QLabel(trUtf8("Файл:"), this);
	horizontalLayout = new QHBoxLayout();
	leTestFilePath = new QLineEdit(this);
	tbtnOpenFile = new QPushButton(trUtf8("..."), this);
	label_5 = new QLabel(trUtf8("Категория:"), this);
	
	cbCat = new QComboBox(this);
	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(cbCat->sizePolicy().hasHeightForWidth());
	cbCat->setSizePolicy(sizePolicy);
	
	label_2 = new QLabel(trUtf8("Название теста:"), this);
	horizontalLayout_2 = new QHBoxLayout();
	label_3 = new QLabel(trUtf8("Количество заданий:"), this);
	
	labelNumAll = new QLabel("0", this);
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(labelNumAll->sizePolicy().hasHeightForWidth());
	labelNumAll->setSizePolicy(sizePolicy1);
	
	leTestName = new QLineEdit(this);
	horizontalLayout_3 = new QHBoxLayout();	
	label_4 = new QLabel(trUtf8("Количество отображаемых заданий:"), this);
	sbNumVis = new QSpinBox(this);
	sbNumVis->setMinimum(0);
	checkBox = new QCheckBox(trUtf8("Видимый для клиента"), this);
	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	
	buttonBox = new QDialogButtonBox(this);
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	buttonBox->setCenterButtons(true);
	
	verticalLayout->addWidget(label);
	horizontalLayout->addWidget(leTestFilePath);
	horizontalLayout->addWidget(tbtnOpenFile);
	verticalLayout->addLayout(horizontalLayout);
	verticalLayout->addWidget(label_5);
	verticalLayout->addWidget(cbCat);
	verticalLayout->addWidget(label_2);
	verticalLayout->addWidget(leTestName);
	horizontalLayout_2->addWidget(label_3);
	horizontalLayout_2->addWidget(labelNumAll);
	verticalLayout->addLayout(horizontalLayout_2);
	horizontalLayout_3->addWidget(label_4);
	horizontalLayout_3->addWidget(sbNumVis);
	verticalLayout->addLayout(horizontalLayout_3);
	verticalLayout->addWidget(checkBox);
	verticalLayout->addItem(verticalSpacer);
	verticalLayout->addWidget(buttonBox);
	
	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
	connect(tbtnOpenFile, SIGNAL(clicked(bool)), SLOT(on_tbtnOpenFile_clicked()));
}

DlgAddBinTest::~DlgAddBinTest()
{

}

void DlgAddBinTest::setCat(const QStringList &catList)
{
	cbCat->clear();
	cbCat->addItems(catList);
}

void DlgAddBinTest::setTest(Test *test)
{
	this->test = test;
}

QString DlgAddBinTest::getCatName() const
{
	return cbCat->currentText();
}

void DlgAddBinTest::on_tbtnOpenFile_clicked()
{
	QFileDialog::Options options;
	options |= QFileDialog::DontUseNativeDialog;
	QString selectedFilter;
	QString fileName = QFileDialog::getOpenFileName(this, trUtf8("Открыть файл с тестом"), QDir::homePath(), trUtf8("Тестовые файлы (*.tst);;Все файлы (*)"), &selectedFilter, options);
	if(!fileName.isEmpty())
		readTest(fileName);
}

void DlgAddBinTest::readTest(const QString &fileName)
{
	quint32 magic;
	quint16 streamVersion;
	QFile file(fileName);
	
	if(!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Can not open file " << fileName << " for reading. Error: " << file.errorString();
		return;
	}
	
	QDataStream in(&file);
	in >> magic >> streamVersion;
	if(magic != magicNumber)
	{
		qDebug() << "File is not recognized by this application";
		return;
	}
	else if(streamVersion > in.version())
	{
		qDebug() << "File is from a more recent version of the" << "application";
		return;
	}
	
	in >> *test;
	
	leTestFilePath->setText(fileName);
	leTestName->setText(test->getName());
	labelNumAll->setNum(test->getCount());
	sbNumVis->setMaximum(test->getCount());
	sbNumVis->setValue(test->getNumVis());
	if(test->checkVis())
		checkBox->setCheckState(Qt::Checked);
	else
		checkBox->setCheckState(Qt::Unchecked);
}

void DlgAddBinTest::setMagicNumber(quint32 magicNumber)
{
	this->magicNumber = magicNumber;
}

quint32 DlgAddBinTest::getNumVis() const
{
	return sbNumVis->value();
}

QString DlgAddBinTest::getTestName() const
{
	return leTestName->text();
}

bool DlgAddBinTest::getVis() const
{
	if(checkBox->checkState() == Qt::Checked)
		return true;
	else
		return false;
}

#include "dlgaddbintest.moc"