#include "hstestcfg.h"

hstestcfg::hstestcfg() :
	QDialog()
{
	horizontalLayout = new QHBoxLayout(this);
	teTests = new QPlainTextEdit(this);
	teTests->setReadOnly(true);
	horizontalLayout->addWidget(teTests);

	verticalLayout = new QVBoxLayout();
	btnAddCat = new QPushButton(trUtf8("Добавить категорию"), this);
	btnAddTest = new QPushButton(trUtf8("Добавить тест"), this);
	btnDelCat = new QPushButton(trUtf8("Удалить категорию"), this);
	btnDelTest = new QPushButton(trUtf8("Удалить тест"), this);
	btnEditTest = new QPushButton(trUtf8("Изменить тест"), this);
	btnClose = new QPushButton(trUtf8("Закрыть"), this);

	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

	verticalLayout->addWidget(btnAddCat);
	verticalLayout->addWidget(btnAddTest);
	verticalLayout->addWidget(btnDelCat);
	verticalLayout->addWidget(btnDelTest);
	verticalLayout->addWidget(btnEditTest);
	verticalLayout->addWidget(btnClose);
	verticalLayout->addItem(verticalSpacer);

	horizontalLayout->addLayout(verticalLayout);
	
	QString appDirPath = QCoreApplication::applicationDirPath();
	QDir appDir(appDirPath);
	appDir.cdUp();
	QString iconsPath = appDir.absolutePath() + "/share/hstest/icons/";

	QIcon logo;
	logo.addPixmap(QPixmap(iconsPath + "logo.svg"));
	setWindowIcon(logo);
	setWindowTitle(trUtf8("Параметры Hs Test Server"));

	testManager = new TestManager(this);
	appDir.cdUp();
	testManager->setTestDir(appDir.absolutePath() + "/var/lib/hstest");
	testManager->readTestDbFromFile();
	createTree();

	addTestDialog = new DlgAddTest(this);
	delTestDialog = new DlgDeleteTest(this);
	editTestDialog = new DlgEditTest(this);

	connect(btnAddCat, SIGNAL(clicked(bool)), SLOT(on_btnAddCat_clicked()));
	connect(btnAddTest, SIGNAL(clicked(bool)), SLOT(on_btnAddTest_clicked()));
	connect(btnClose, SIGNAL(clicked(bool)), SLOT(on_btnClose_clicked()));
	connect(btnDelCat, SIGNAL(clicked(bool)), SLOT(on_btnDelCat_clicked()));
	connect(btnEditTest, SIGNAL(clicked(bool)), SLOT(on_btnEditTest_clicked()));
	connect(btnDelTest, SIGNAL(clicked(bool)), SLOT(on_btnDelTest_clicked()));
}

hstestcfg::~hstestcfg()
{}

void hstestcfg::closeEvent(QCloseEvent *event)
{
	testManager->writeTestDbToFile();
	event->accept();
}

void hstestcfg::createTree()
{
	teTests->clear();
	QStringList cats = testManager->getCategoryList();
	QStringList testList;
	QString curCat = "";
	if(cats.isEmpty())
		return;
	for(int i = 0; i < cats.count(); i++)
	{
		curCat = cats.at(i);
		teTests->appendPlainText(QString().setNum(i + 1) + ". " + curCat);

		testList = testManager->getTestListByCategory(curCat, true);
		int n = testList.count();
		if(testList.isEmpty())
			continue;
		for(int j = 0; j < n; j++)
		{
			teTests->appendPlainText("    - " + testList.at(j));
		}
	}
}

void hstestcfg::on_btnAddCat_clicked()
{
	bool ok;
	QString text = QInputDialog::getText(this, trUtf8("Добавить категорию"), trUtf8("Категория:"), QLineEdit::Normal, "", &ok);
	if(ok && !text.isEmpty())
		testManager->addCategory(text);
	testManager->writeTestDbToFile();
	createTree();
}

void hstestcfg::on_btnAddTest_clicked()
{
	bool ok;
	addTestDialog->setCats(testManager->getCategoryList());
	if(addTestDialog->exec() == QDialog::Accepted)
	{
		ok = testManager->loadTestFromFile(addTestDialog->getCat(), addTestDialog->getTestTextFileName(), addTestDialog->getNumVis(), addTestDialog->getVis());
		if(!ok)
			QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Не возможно загрузить тест."));
	}
	createTree();
}

void hstestcfg::on_btnClose_clicked()
{
	close();
}

void hstestcfg::on_btnDelCat_clicked()
{
	bool ok;
	QString delCatName = QInputDialog::getItem(this, trUtf8("Удалить категорию"), trUtf8("Категория"), testManager->getCategoryList(), 0, false, &ok);
	if(ok && !delCatName.isEmpty())
		if(!testManager->delCategory(delCatName))
			QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Не возможно удалить категорию.\nКатегория ") + delCatName + trUtf8(" не пустая."));
	createTree();
}

void hstestcfg::on_btnDelTest_clicked()
{
	bool ok;
	delTestDialog->setCategories(testManager->getCategoriesPtr());
	if(delTestDialog->exec() == QDialog::Accepted)
	{
		ok = testManager->delTest(delTestDialog->getCategory(), delTestDialog->getTest());
		if(!ok)
			QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Не возможно удалить тест ") + delTestDialog->getTest() + trUtf8("."));
	}
	createTree();
}

void hstestcfg::on_btnEditTest_clicked()
{
	editTestDialog->setTestManager(testManager);
	if(editTestDialog->exec() == QDialog::Accepted)
	{
		if(!testManager->editTest(editTestDialog->getCategory(), editTestDialog->getTest(), editTestDialog->getNumVis(), editTestDialog->getVis()))
			QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Не возможно изменить тест ") + delTestDialog->getTest() + trUtf8("."));
		else
			testManager->writeTestDbToFile();
	}
}

#include "hstestcfg.moc"
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
