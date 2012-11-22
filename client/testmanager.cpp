/*
    Management tests.
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


#include "testmanager.h"

TestManager::TestManager(QObject *parent) :
	QObject(parent), tests(0), currentTest(0), serverName("localhost"), serverPort(0), currentNodeId(0), isSession(false)
{
	magicNumber = 0xAAFF452C;
	session = new Session(this);
	session->setMagicNumber(magicNumber);

	connect(&thread, SIGNAL(newTestDb(TestDB)), SLOT(requestNewTestDb(TestDB)));
	connect(&thread, SIGNAL(newTest(Test)), SLOT(requestNewTest(Test)));
	connect(&thread, SIGNAL(newGroups(QStringList)), SLOT(requestNewGroups(QStringList)));
	connect(&thread, SIGNAL(error(int, QString)), SLOT(netError(int, QString)));
}

TestManager::TestManager(const TestManager &other) :
	QObject(other.parent())
{
	tests = other.tests;
	session = other.session;
}

TestManager::~TestManager()
{
	delete tests;
	delete currentTest;
}

TestManager &TestManager::operator= (const TestManager &other)
{
	setParent(other.parent());
	tests = other.tests;
	session = other.session;
	return *this;
}

bool TestManager::operator== (const TestManager &other) const
{
	return (tests == other.tests);
}

/**
 * @brief Возвращает список категорий
 *
 * @return QStringList
 **/
QStringList TestManager::getCategoryList() const
{
	return tests->getCategoryNameList();
}

/**
 * @brief Возвращает список тестов включенных в категорию categoryName
 *
 * @param categoryName имя категории
 * @param all если true будет возвращён весь список тестов, если false - только "видимые"
 * @return QStringList
 **/
QStringList TestManager::getTestListByCategory(const QString &categoryName, bool all) const
{
	return tests->getTestNameListByCategory(categoryName, all);
}

TestDB TestManager::getCategories() const
{
	return *tests;
}

TestDB *TestManager::getCategoriesPtr() const
{
	return tests;
}

void TestManager::loadTestDb()
{
	thread.requestTestDb(serverName, serverPort);
}

void TestManager::setServerParm(const QString &serverName, quint16 serverPort)
{
	this->serverName = serverName;
	this->serverPort = serverPort;
}

void TestManager::loadTest(const QString &catName, const QString &testName)
{
	int catId, testId;
	catId = tests->getCategoryNameList().indexOf(catName);
	testId = tests->getTestNameListByCategory(catName).indexOf(testName);
	thread.requestTest(serverName, serverPort, catId, testId);
}

void TestManager::requestNewTestDb(TestDB testDb)
{
	if(tests != 0)
		delete tests;
	tests = new TestDB(testDb);
	emit testDbLoaded();
}

void TestManager::requestNewTest(Test test)
{
	if(currentTest != 0)
		delete currentTest;
	currentTest = new Test(test);
	numNodes = currentTest->getCount();
	currentTest->shuffle();
	session->setTest(currentTest);
	session->setCloseSession(false);
	emit testLoaded();
}

void TestManager::netError(int socketError, const QString &message)
{
	emit netIsError(socketError, message);
}

const TestNode *TestManager::getFirstNode()
{
	currentNodeId = 1;
	return currentTest->getNodePtr(0);
}

const TestNode *TestManager::next()
{
	if(currentNodeId >= currentTest->getCount())
		return 0;
	return currentTest->getNodePtr(currentNodeId++);
}

QString TestManager::getTestName() const
{
	return currentTest->getName();
}

quint32 TestManager::getNumNodes() const
{
	return numNodes;
}

void TestManager::getPercentParam(float &per2, float per3, float per4)
{
	tests->getPercentParam(per2, per3, per4);
}

void TestManager::setStudentName(const QString &studentName)
{
	this->studentName = studentName;
}

void TestManager::setGroupName(const QString &groupName)
{
	this->groupName = groupName;
}

void TestManager::loadGroups()
{
	thread.requestGroups(serverName, serverPort);
}

QStringList TestManager::getGroups() const
{
	return groups;
}

void TestManager::requestNewGroups(QStringList groups)
{
	this->groups = groups;
	emit groupsLoaded();
}

void TestManager::sentStudentData(qreal percent, quint32 ocenka)
{
	thread.sendStudentData(serverName, serverPort, studentName, groupName, currentTest->getName(), percent, ocenka);
}

bool TestManager::isCloseSession() const
{
	return session->isCloseSession();
}

void TestManager::closeSession()
{
	session->setCloseSession(true);
	isSession = false;
}

void TestManager::setSessionParam(int *currenNumTask, int *numRealAnswers, QTime *currentTime, QString *currentCatName)
{
	session->setCurrentNumTask(currenNumTask);
	session->setCurrentTime(currentTime);
	session->setNumRealAnswers(numRealAnswers);
	session->setCurrentCatName(currentCatName);
}

void TestManager::writeSession()
{
	session->writeValues();
}

void TestManager::getSessionParam()
{
	session->getValues();
	if(currentTest != 0)
		delete currentTest;
	currentTest = new Test(session->getTest());
	numNodes = currentTest->getCount();
	currentNodeId = session->getCurrentNumTask();
	emit testLoaded();
}

void TestManager::setIsSession(bool ses)
{
	isSession = ses;
}

bool TestManager::getIsSession() const
{
	return isSession;
}

quint16 TestManager::getModeType()
{
	quint16 ret = session->getModeType();
	if(ret == 1)
	{
		studentName = session->getStudentName();
		groupName = session->getGroupName();
	}
	return ret;
}

void TestManager::setModeType(quint16 modeType)
{
	session->setModeType(modeType);
	if(modeType == 1)
	{
		session->setStudentName(studentName);
		session->setGroupName(groupName);
	}
}

#include "testmanager.moc"

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
