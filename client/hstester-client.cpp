#include "hstester-client.h"


MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent), 
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->stackedWidget->setCurrentIndex(0);
	ui->actionBack->setDisabled(true);
	ui->actionForvard->setDisabled(true);
	
	ui->actionRepit->setDisabled(true);
	ui->actionReturn->setDisabled(true);
	ui->actionShowResult->setDisabled(true);
	
	ui->btnNext->setVisible(false);
	ui->progressBarCurTest->setVisible(false);
	ui->preResultView->setVisible(false);
	
	numTasksL = new QLabel(trUtf8("Всего заданий: "), this);
	numTasks = new QLabel(trUtf8("0"), this);
	timerView = new QLabel(trUtf8("0:00"), this);
	timerView->setAlignment(Qt::AlignRight);
	ui->statusBar->addWidget(numTasksL);
	ui->statusBar->addWidget(numTasks);
	ui->statusBar->addWidget(timerView, 1);
	numTasksL->setVisible(false);
	numTasks->setVisible(false);
	timerView->setVisible(false);
	
	numRealAnswers = 0;
	ocenka = 0;
	percent = 0.0;
	numCurrentNode = 0;
	numConfRegAnsw = 1;
	onToggled = false;
	listViewTests = false;
	tTime = new QTime(0, 0);
	mTimer = new QTimer(this);
	appName = trUtf8("Hs Test 0.2");
	
	per2 = 60.0;
	per3 = 80.0;
	per4 = 90.0;
	
	initCloseView();
	initConfView();
	initRegView();
	
	config = new DlgConfig(this);
	
	QString appDir = QCoreApplication::applicationDirPath();
	QDir imagesDir(appDir);
	imagesDir.cdUp();
	imagesDir.cdUp();
	imagesPath = imagesDir.absolutePath() + "/images/";
	
	settings = new QSettings("../config/hstester.conf", QSettings::NativeFormat);
	readSettings();
	
	resultReport = new Report(this, htmlFileResult);
	reportView = new ReportView(this, htmlFileResult);
	reportView->hide();
	QDir dir;
	dir.mkpath(tmpDir);
	
	testManager = new TestManager(this);
	testManager->setServerParm(serverName, serverPort);
	currentNode = 0;
	
	setWindowTitle(appName);
	
	connect(ui->action_AboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	connect(mTimer, SIGNAL(timeout()), SLOT(timered()));
	connect(testManager, SIGNAL(testDbLoaded()), SLOT(testDbLoaded()));
	connect(testManager, SIGNAL(testLoaded()), SLOT(testLoaded()));
	connect(testManager, SIGNAL(netIsError(int,QString)), SLOT(net_error(int,QString)));
}

MainWindow::~MainWindow()
{
	delete ui;
	delete tTime;
	delete settings;
}

void MainWindow::on_actionExit_activated()
{
	close();
}

void MainWindow::initCloseView()
{
	closeNodes[0] = ui->cbAnswer_1;
	closeNodes[1] = ui->cbAnswer_2;
	closeNodes[2] = ui->cbAnswer_3;
	closeNodes[3] = ui->cbAnswer_4;
	closeNodes[4] = ui->cbAnswer_5;
	closeNodes[5] = ui->cbAnswer_6;
	closeNodes[6] = ui->cbAnswer_7;
	closeNodes[7] = ui->cbAnswer_8;
	
	for(int i = 0; i < 8; i++)
		closeNodes[i]->setVisible(false);
}

void MainWindow::initConfView()
{
	confBtnNodes[0] = ui->btnConfAnswer_1;
	confBtnNodes[1] = ui->btnConfAnswer_2;
	confBtnNodes[2] = ui->btnConfAnswer_3;
	confBtnNodes[3] = ui->btnConfAnswer_4;
	confBtnNodes[4] = ui->btnConfAnswer_5;
	
	confLabelNodes[0] = ui->labelConfAnswer_1;
	confLabelNodes[1] = ui->labelConfAnswer_2;
	confLabelNodes[2] = ui->labelConfAnswer_3;
	confLabelNodes[3] = ui->labelConfAnswer_4;
	confLabelNodes[4] = ui->labelConfAnswer_5;
	
	for(int i = 0; i < 5; i++)
	{
		confBtnNodes[i]->setVisible(false);
		confLabelNodes[i]->setVisible(false);
	}
}

void MainWindow::initRegView()
{
	regBtnNodes[0] = ui->btnRegAnswer_1;
	regBtnNodes[1] = ui->btnRegAnswer_7;
	regBtnNodes[2] = ui->btnRegAnswer_8;
	regBtnNodes[3] = ui->btnRegAnswer_9;
	regBtnNodes[4] = ui->btnRegAnswer_10;
	regBtnNodes[5] = ui->btnRegAnswer_11;
	regBtnNodes[6] = ui->btnRegAnswer_12;
	regBtnNodes[7] = ui->btnRegAnswer_13;
	
	regLabelNodes[0] = ui->labelRegAnswer_1;
	regLabelNodes[1] = ui->labelRegAnswer_7;
	regLabelNodes[2] = ui->labelRegAnswer_8;
	regLabelNodes[3] = ui->labelRegAnswer_9;
	regLabelNodes[4] = ui->labelRegAnswer_10;
	regLabelNodes[5] = ui->labelRegAnswer_11;
	regLabelNodes[6] = ui->labelRegAnswer_12;
	regLabelNodes[7] = ui->labelRegAnswer_13;
	
	for(int i = 0; i < 8; i++)
	{
		regBtnNodes[i]->setVisible(false);
		regLabelNodes[i]->setVisible(false);
	}
}

void MainWindow::on_btnConfAnswer_1_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnConfAnswer_1, checked);
}

void MainWindow::on_btnConfAnswer_2_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnConfAnswer_2, checked);
}

void MainWindow::on_btnConfAnswer_3_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnConfAnswer_3, checked);
}

void MainWindow::on_btnConfAnswer_4_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnConfAnswer_4, checked);
}

void MainWindow::on_btnConfAnswer_5_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnConfAnswer_5, checked);
}

void MainWindow::on_btnRegAnswer_1_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_1, checked);
}

void MainWindow::on_btnRegAnswer_7_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_7, checked);
}

void MainWindow::on_btnRegAnswer_8_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_8, checked);
}

void MainWindow::on_btnRegAnswer_9_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_9, checked);
}

void MainWindow::on_btnRegAnswer_10_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_10, checked);
}

void MainWindow::on_btnRegAnswer_11_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_11, checked);
}

void MainWindow::on_btnRegAnswer_12_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_12, checked);
}

void MainWindow::on_btnRegAnswer_13_toggled(bool checked)
{
	setNumConfRegBtn(ui->btnRegAnswer_13, checked);
}

/**
 * @brief Установка номера ответа в тестах на упорядочние и соответствие.
 *
 * @param btn Активированная кнопка.
 * @param ch Флаг состояния кнопки (true - нажата, false - отжата).
 * @return void
 **/
void MainWindow::setNumConfRegBtn(QPushButton* btn, bool ch)
{
	if(onToggled)
	{
		if(ch)
		{
			QString n;
			n.setNum(numConfRegAnsw++);
			btn->setText(n);
		}
		else
		{
			switch(currentNode->getType())
			{
				case TYPE_NODE_CONFORMITY:
					numConfRegAnsw = 1;
					onToggled = false;
					for(int i = 0; i < currentNode->getAnswers().count(); i++)
					{
						confBtnNodes[i]->setChecked(false);
						confBtnNodes[i]->setText(" ");
					}
					onToggled = true;
					break;
				case TYPE_NODE_REGULATING:
					numConfRegAnsw = 1;
					onToggled = false;
					for(int i = 0; i < currentNode->getAnswers().count(); i++)
					{
						regBtnNodes[i]->setChecked(false);
						regBtnNodes[i]->setText(" ");
					}
					onToggled = true;
					break;
			}
		}
	}
}

void MainWindow::timered()
{
	int h = tTime->hour();
	int m = tTime->minute() + 1;
	if(m == 60)
	{
		h++;
		m = 0;
	}
	tTime->setHMS(h, m, 0);
	timerView->setText(tTime->toString("h:mm"));
}

void MainWindow::readSettings()
{
	tmpDir = settings->value("files/TmpDirectory", QString(QDir::tempPath() + "/hstester-client")).toString();
	
	htmlFileResult = settings->value("files/ResultFile", QString(tmpDir + "/result.html")).toString();
	
	serverName = settings->value("server/name", QString("localhost")).toString();
	serverPort = settings->value("server/port", qint16(1605)).toInt();
	
	resultReportOn = settings->value("view/ReportOn", bool(true)).toBool();
}

void MainWindow::writeSettings()
{
	settings->setValue("files/TmpDirectory", tmpDir);
	settings->setValue("files/ResultFile", htmlFileResult);
	
	settings->setValue("server/name", serverName);
	settings->setValue("server/port", serverPort);
	
	settings->setValue("view/ReportOn", resultReportOn);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	writeSettings();
	event->accept();
}

void MainWindow::on_actionAdvance_triggered()
{
	config->setServerParm(serverName, serverPort);
	config->setViewPanel(true); // TODO: реализовать отображение/скрытие панели инструментов
	config->setCreateReport(resultReportOn);
	
	if(config->exec() == QDialog::Accepted)
	{
		serverName = config->getServerName();
		serverPort = config->getServerPort();
		resultReportOn = config->getCreateReport();
		writeSettings();
	}
}

void MainWindow::on_actionLoadTests_triggered()
{
	listViewTests = false;
	testManager->loadTestDb();
}

void MainWindow::testDbLoaded()
{
	QIcon folderIcon;
	//folderIcon.addPixmap(style->standardPixmap(QStyle::SP_DirClosedIcon));
	folderIcon.addPixmap(QPixmap(ui->iconsPath + "folder.png"));
	ui->listCatTestView->clear();
	QStringList catList = testManager->getCategoryList();
	for(int i = 0; i < catList.count(); i++)
	{
		QListWidgetItem *cat = new QListWidgetItem(folderIcon, catList.at(i));
		ui->listCatTestView->addItem(cat);
	}
}

void MainWindow::net_error(int socketError, const QString &error_string)
{
	switch (socketError) {
		case QAbstractSocket::HostNotFoundError:
			QMessageBox::information(this, trUtf8("Hs Test Client"),
											trUtf8("Сервер не найден. Установите пожалуйста адрес и порт сервера в настройках."));
											break;
		case QAbstractSocket::ConnectionRefusedError:
			QMessageBox::information(this, trUtf8("Hs Test Client"),
											trUtf8("Соединение было разорвано другим узлом. "
											"Убедитесь, что сервер работает, и имя хоста и порт настроены верно."));
			break;
		default:
			QMessageBox::information(this, trUtf8("Hs Test Client"),
											trUtf8("Произошла следующая ошибка: %1.").arg(error_string));
	}
}

void MainWindow::chekResult()
{
	qint8 result = 0;
	QString sresult = "";
	int n = currentNode->getAnswers().count(), i = 0;
	
	switch(currentNode->getType())
	{
		case TYPE_NODE_CLOSE:
			for(i = 0; i < n; i++)
			{
				if(closeNodes[i]->isChecked())
					result += std::pow(2, i);
			}
			if(currentNode->checkAnswer(result))
			{
				numRealAnswers++;
				if(resultReportOn)
					resultReport->addCloseNode(currentNode, true);
			}
			else
				if(resultReportOn)
					resultReport->addCloseNode(currentNode, false);
				break;
			
		case TYPE_NODE_OPEN:
			sresult = ui->leAnswer->text();
			if(currentNode->checkAnswerOpen(sresult))
			{
				numRealAnswers++;
				if(resultReportOn)
					resultReport->addOpenNode(currentNode, true);
			}
			else
				if(resultReportOn)
					resultReport->addOpenNode(currentNode, false);
				break;
			
		case TYPE_NODE_CONFORMITY:
			for(i = 0; i < n; i++)
			{
				if(confBtnNodes[i]->text() == " ")
					sresult += "0";
				else
					sresult += confBtnNodes[i]->text();
			}
			if(currentNode->checkAnswer(sresult))
			{
				numRealAnswers++;
				if(resultReportOn)
					resultReport->addConformityNode(currentNode, true);
			}
			else
				if(resultReportOn)
					resultReport->addConformityNode(currentNode, false);
				break;
			
		case TYPE_NODE_REGULATING:
			for(i = 0; i < n; i++)
			{
				if(regBtnNodes[i]->text() == " ")
					sresult += "0";
				else
					sresult += regBtnNodes[i]->text();
			}
			if(currentNode->checkAnswer(sresult))
			{
				numRealAnswers++;
				if(resultReportOn)
					resultReport->addRegulatingNode(currentNode, true);
			}
			else
				if(resultReportOn)
					resultReport->addRegulatingNode(currentNode, false);
				break;
	}
}

void MainWindow::showResult()
{
	QString nf;
	
	mTimer->stop();
	ui->btnNext->setVisible(false);
	ui->progressBarCurTest->setVisible(false);
	ui->preResultView->setVisible(false);
	
	ui->labelResultTest->setText(testManager->getTestName());
	percent = (float(numRealAnswers) * 100.0) / float(testManager->getNumNodes());
	nf.setNum(percent, 'f', 2);
	
	ui->labelResultPrec->setText(trUtf8("Верных ответов: ") + nf + "%");
	
	if(percent < per2)
		ocenka = 2;
	else if(percent >= per2 && percent < per3)
		ocenka = 3;
	else if(percent >= per3 && percent < per4)
		ocenka = 4;
	else
		ocenka = 5;
	ui->labelResultImg->setPixmap(QPixmap(imagesPath + nf.setNum(ocenka) + ".svg"));
	
	QStringList timeList = timerView->text().split(':');
	ui->labelResultTime->setText(QString(trUtf8("Время решения теста: %1ч. %2м.")).arg(timeList.at(0)).arg(timeList.at(1)));
	
	ui->actionRepit->setEnabled(true);
	ui->actionReturn->setEnabled(true);
	ui->actionShowResult->setEnabled(true);
	
	ui->stackedWidget->setCurrentIndex(5);
	
	if(resultReportOn)
	{
		resultReport->setNameTest(testManager->getTestName());
		resultReport->setTimeTest(timerView->text());
		resultReport->setPercents(percent);
		resultReport->setOcenka(ocenka);
		resultReport->writeReportFile();
	}
}

void MainWindow::showTestNode()
{
	if(numCurrentNode == 0)
		currentNode = testManager->getFirstNode();
	else
		currentNode = testManager->next();
	int c_answ = 0;
	QString ques_conf = "";
	
	switch(currentNode->getType())
	{
		case TYPE_NODE_CLOSE:
			for(int i = 0; i < 8; i++)
				closeNodes[i]->setVisible(false);
			ui->labelTaskClose->setText(currentNode->getTask());
			ui->labelQuestClose->setText(currentNode->getQuestion());
			c_answ = currentNode->getAnswers().count();
			for(int i = 0; i < c_answ; i++)
			{
				closeNodes[i]->setText(currentNode->getAnswers().at(i));
				closeNodes[i]->setChecked(false);
				closeNodes[i]->setVisible(true);
			}
			ui->stackedWidget->setCurrentIndex(1);
			break;
			
		case TYPE_NODE_OPEN:
			ui->labelTaskOpen->setText(currentNode->getTask());
			ui->labelQuestOpen->setText(currentNode->getQuestion());
			ui->leAnswer->clear();
			ui->stackedWidget->setCurrentIndex(2);
			break;
			
		case TYPE_NODE_CONFORMITY:
			numConfRegAnsw = 1;
			onToggled = false;
			for(int i = 0; i < 5; i++)
			{
				confBtnNodes[i]->setVisible(false);
				confBtnNodes[i]->setChecked(false);
				confLabelNodes[i]->setVisible(false);
			}
			onToggled = true;
			ui->labelTaskConformity->setText(currentNode->getTask());
			
			for(int i = 0; i < currentNode->getQuestions().count(); i++)
			{
				ques_conf += QString("%1. " + currentNode->getQuestions().at(i) + "\n\n").arg(i + 1);
			}
			ui->teQuestions->setText(ques_conf);
			for(int i = 0; i < currentNode->getAnswers().count(); i++)
			{
				confBtnNodes[i]->setText(" ");
				confBtnNodes[i]->setVisible(true);
				confLabelNodes[i]->setText(currentNode->getAnswers().at(i));
				confLabelNodes[i]->setVisible(true);
			}
			ui->stackedWidget->setCurrentIndex(3);
			break;
			
		case TYPE_NODE_REGULATING:
			numConfRegAnsw = 1;
			onToggled = false;
			for(int i = 0; i < 8; i++)
			{
				regBtnNodes[i]->setVisible(false);
				regBtnNodes[i]->setChecked(false);
				regLabelNodes[i]->setVisible(false);
			}
			onToggled = true;
			ui->labelTaskRegulating->setText(currentNode->getTask());
			for(int i = 0; i < currentNode->getAnswers().count(); i++)
			{
				regBtnNodes[i]->setText(" ");
				regBtnNodes[i]->setVisible(true);
				regLabelNodes[i]->setText(currentNode->getAnswers().at(i));
				regLabelNodes[i]->setVisible(true);
			}
			ui->stackedWidget->setCurrentIndex(4);
			break;
	}
}

void MainWindow::testLoaded()
{
	numTasks->setNum(int(testManager->getNumNodes()));
	ui->progressBarCurTest->setMaximum(testManager->getNumNodes());
	ui->progressBarCurTest->setValue(0);
	setWindowTitle(appName + " - " + testManager->getTestName());
	
	numTasksL->setVisible(true);
	numTasks->setVisible(true);
	timerView->setVisible(true);
	ui->btnNext->setVisible(true);
	ui->progressBarCurTest->setVisible(true);
	ui->preResultView->setVisible(true);
	
	ui->actionBack->setDisabled(true);
	ui->actionForvard->setDisabled(true);
	ui->actionLoadTests->setDisabled(true);
	
	numCurrentNode = 0;
	tTime->setHMS(0, 0, 0);
	mTimer->start(60000);
	showTestNode();
}

void MainWindow::on_listCatTestView_clicked(const QModelIndex &index)
{
	QListWidgetItem* curItem = ui->listCatTestView->currentItem();
	if(!listViewTests)
	{  
		curCatName = curItem->text();
		ui->listCatTestView->clear();
		ui->listCatTestView->addItems(testManager->getTestListByCategory(curCatName));
		
		QIcon testIcon;
		testIcon.addPixmap(QPixmap(ui->iconsPath + "test.png"));
		for(int i = 0; i < ui->listCatTestView->count(); i++)
			ui->listCatTestView->item(i)->setIcon(testIcon);
		
		ui->actionBack->setEnabled(true);
		ui->actionForvard->setDisabled(true);
		listViewTests = true;
	}
	else
	{
		testManager->loadTest(curCatName, curItem->text());
	}
}

void MainWindow::on_btnNext_clicked()
{
	int preResult = 0;
	float prePer = 0.0;
	chekResult();
	ui->progressBarCurTest->setValue(numCurrentNode + 1);
	numCurrentNode++;
	
	preResult = numRealAnswers + testManager->getNumNodes() - numCurrentNode;
	prePer = (float(preResult) * 100.0) / float(testManager->getNumNodes());
	if(prePer < per2)
		ui->preResultView->display(2);
	else if(prePer >= per2 && prePer < per3)
		ui->preResultView->display(3);
	else if(prePer >= per3 && prePer < per4)
		ui->preResultView->display(4);
	else
		ui->preResultView->display(5);
	
	if(numCurrentNode >= testManager->getNumNodes())
	{
		showResult();
		return;
	}
	if(numCurrentNode == (testManager->getNumNodes() - 1))
		ui->btnNext->setText(trUtf8("Результат"));
	showTestNode();
}

void MainWindow::on_actionBack_activated()
{
	ui->listCatTestView->clear();
	testDbLoaded();
	ui->actionBack->setDisabled(true);
	ui->actionForvard->setEnabled(true);
	listViewTests = false;
}

void MainWindow::on_actionForvard_activated()
{
	ui->listCatTestView->clear();
	ui->listCatTestView->addItems(testManager->getTestListByCategory(curCatName));
	
	QIcon testIcon;
	testIcon.addPixmap(QPixmap(ui->iconsPath + "test.png"));
	for(int i = 0; i < ui->listCatTestView->count(); i++)
		ui->listCatTestView->item(i)->setIcon(testIcon);
	
	ui->actionBack->setEnabled(true);
	ui->actionForvard->setDisabled(true);
	listViewTests = true;
}

void MainWindow::on_actionShowResult_triggered()
{
	reportView->load();
	reportView->show();
}

void MainWindow::on_actionRepit_triggered()
{
	numRealAnswers = 0;
	ocenka = 2;
	percent = 0.0;
	numConfRegAnsw = 1;
	resultReport->clear();
	
	for(int i = 0; i < 5; i++)
	{
		confBtnNodes[i]->setChecked(false);
	}
	for(int i = 0; i < 8; i++)
	{
		regBtnNodes[i]->setChecked(false);
	}
	
	ui->btnNext->setText(trUtf8("Следующий"));
	ui->actionRepit->setDisabled(true);
	ui->actionReturn->setDisabled(true);
	ui->actionShowResult->setDisabled(true);
	ui->preResultView->display(5);
	
	testManager->loadTest(curCatName, testManager->getTestName());
}

void MainWindow::on_actionReturn_triggered()
{
	numRealAnswers = 0;
	ocenka = 2;
	percent = 0.0;
	numConfRegAnsw = 1;
	listViewTests = false;
	resultReport->clear();
	
	for(int i = 0; i < 5; i++)
	{
		confBtnNodes[i]->setChecked(false);
	}
	for(int i = 0; i < 8; i++)
	{
		regBtnNodes[i]->setChecked(false);
	}
	
	ui->progressBarCurTest->setValue(0);
	ui->btnNext->setText(QObject::trUtf8("Следующий"));
	ui->actionRepit->setDisabled(true);
	ui->actionReturn->setDisabled(true);
	ui->actionShowResult->setDisabled(true);
	ui->preResultView->display(5);
	numTasks->setText("0");
	numTasks->setVisible(false);
	numTasksL->setVisible(false);
	timerView->setVisible(false);
	
	testDbLoaded();
	ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionAbout_triggered()
{
	QString str1, str2, str3, str4;
	
	str1 = trUtf8("<h2>%1</h2><p>Программа <b>Hs Test</b> предназначена для тестирования учеников, студентов и сотрудников учреждений.</p><p>Copyright &copy;  2012 Роман Браун</p>").arg(appName);
	str2 = trUtf8("<p>Это программа является свободным программным обеспечением. Вы можете распространять и/или модифицировать её согласно условиям Стандартной Общественной Лицензии GNU, опубликованной Фондом Свободного Программного Обеспечения, версии 3 или, по Вашему желанию, любой более поздней версии.</p>");
	str3 = trUtf8("<p>Эта программа распространяется в надежде, что она будет полезной, но БЕЗ ВСЯКИХ ГАРАНТИЙ, в том числе подразумеваемых гарантий ТОВАРНОГО СОСТОЯНИЯ ПРИ ПРОДАЖЕ и ГОДНОСТИ ДЛЯ ОПРЕДЕЛЁННОГО ПРИМЕНЕНИЯ. Смотрите Стандартную Общественную Лицензию GNU для получения дополнительной информации.</p>");
	str4 = trUtf8("<p>Вы должны были получить копию Стандартной Общественной Лицензии GNU вместе с программой. В случае её отсутствия, посмотрите <a href=\"http://www.gnu.org/licenses/\">http://www.gnu.org/licenses/</a>.</p><p>E-Mail: <a href=\"mailto:firdragon76@gmail.com\">firdragon76@gmail.com</a><br>Сайт программы: <a href=\"github.com/Horsmir/hstest\">github.com/Horsmir/hstest</a></p>");
	
	QMessageBox::about(this, trUtf8("О программе"), str1 + str2 + str3 + str4);
}

void MainWindow::on_actionHelp_triggered()
{
	QString curPath = QDir::currentPath();
	curPath = "file://" + curPath + "/help_rus.pdf";
	QDesktopServices::openUrl(QUrl(curPath, QUrl::TolerantMode));
}

#include "hstester-client.moc"