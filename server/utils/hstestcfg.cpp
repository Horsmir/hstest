#include <QtCore/QDir>
#include <QtCore/QCoreApplication>
#include <QtGui/QCloseEvent>
#include <QtGui/QInputDialog>
#include <QtGui/QMessageBox>
#include "hstestcfg.h"

hstestcfg::hstestcfg(QWidget *parent, Qt::WindowFlags f) :
	QDialog(parent, f), ui(new Ui::MainDialog)
{
	ui->setupUi(this);
	
	QString appDirPath = QCoreApplication::applicationDirPath();
	QDir appDir(appDirPath);
	QString iconsPath;
#ifdef Q_OS_LINUX
	appDir.cdUp();
	iconsPath = appDir.absolutePath() + "/share/hstest/icons/";
#endif

	setWindowTitle(trUtf8("Параметры Hs Test Server 0.4"));

	testManager = new TestManager(this);
	QString dataDirPath;
#ifdef Q_OS_LINUX
	appDir.cdUp();
	dataDirPath = appDir.absolutePath() + "/var/lib/hstest";
#endif
#ifdef Q_OS_WIN32
	dataDirPath = appDir.absolutePath() + "/data";
#endif
	QDir dataDir(dataDirPath);
	if(!dataDir.exists())
		dataDir.mkpath(dataDirPath);
	testManager->setTestDir(dataDirPath);
	testManager->readTestDbFromFile();
	createTree();

	addTestDialog = new DlgAddTest(this);
	delTestDialog = new DlgDeleteTest(this);
	editTestDialog = new DlgEditTest(this);
	editGroupsDialog = new DlgEditGroups(this);
	editMarksDialog = new DlgEditMarks(this);
	addBintestDialog = new DlgAddBinTest(this);
}

hstestcfg::~hstestcfg()
{
	delete ui;
}

void hstestcfg::closeEvent(QCloseEvent *event)
{
	testManager->writeTestDbToFile();
	event->accept();
}

void hstestcfg::createTree()
{
	ui->teTests->clear();
	QStringList cats = testManager->getCategoryList();
	QStringList testList;
	QString curCat = "";
	if(cats.isEmpty())
		return;
	cats.sort();
	for(int i = 0; i < cats.count(); i++)
	{
		curCat = cats.at(i);
		ui->teTests->appendPlainText(QString().setNum(i + 1) + ". " + curCat);

		testList = testManager->getTestListByCategory(curCat, true);
		int n = testList.count();
		if(testList.isEmpty())
			continue;
		testList.sort();
		for(int j = 0; j < n; j++)
		{
			ui->teTests->appendPlainText("    - " + testList.at(j));
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
	addTestDialog->clear();
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
	editTestDialog->clear();
	editTestDialog->setTestManager(testManager);
	if(editTestDialog->exec() == QDialog::Accepted)
	{
		if(!testManager->editTest(editTestDialog->getCategory(), editTestDialog->getTest(), editTestDialog->getNumVis(), editTestDialog->getVis()))
			QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Не возможно изменить тест ") + delTestDialog->getTest() + trUtf8("."));
		else
			testManager->writeTestDbToFile();
	}
}

void hstestcfg::on_btnEditGroups_clicked()
{
	testManager->readStudentDbFromFile();
	editGroupsDialog->setTestManager(testManager);
	editGroupsDialog->show();
}

void hstestcfg::on_btnEditMarks_clicked()
{
	float percent2, percent3, percent4;
	testManager->getPercentParam(percent2, percent3, percent4);
	editMarksDialog->setPercents(percent2, percent3, percent4);
	if(editMarksDialog->exec() == QDialog::Accepted)
	{
		editMarksDialog->getPercents(percent2, percent3, percent4);
		testManager->setPercentParam(percent2, percent3, percent4);
	}
}

void hstestcfg::on_btnAddBinTest_clicked()
{
	Test newTest;
	addBintestDialog->setCat(testManager->getCategoryList());
	addBintestDialog->setMagicNumber(testManager->getMagicNumber());
	addBintestDialog->setTest(&newTest);
	if(addBintestDialog->exec() == QDialog::Accepted)
	{
		newTest.setName(addBintestDialog->getTestName());
		newTest.setNumVis(addBintestDialog->getNumVis());
		if(addBintestDialog->getNumVis())
			newTest.setVis();
		else
			newTest.setNoVis();
		testManager->addTest(addBintestDialog->getCatName(), newTest);
		createTree();
	}
}

#include "hstestcfg.moc"
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
