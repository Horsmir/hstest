/*
	Management tests
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


#ifndef TESTMANAGER_H
#define TESTMANAGER_H

#include <QDebug>
#include <QObject>
#include "testdb.h"
#include "test.h"
#include "testthread.h"


class TestManager : public QObject
{
	Q_OBJECT

public:
	TestManager(QObject *parent = 0);
	TestManager(const TestManager &other);
	virtual ~TestManager();
	virtual TestManager &operator= (const TestManager &other);
	virtual bool operator== (const TestManager &other) const;

	void loadTestDb();
	void loadTest(const QString &catName, const QString &testName);
	void loadGroups();
	void sentStudentData(qreal percent, quint32 ocenka);

	void setServerParm(const QString &serverName, quint16 serverPort);
	void setStudentName(const QString &studentName);
	void setGroupName(const QString &groupName);

	QStringList getCategoryList() const;
	QStringList getTestListByCategory(const QString &categoryName, bool all = false) const;

	TestDB getCategories() const;
	TestDB *getCategoriesPtr() const;

	const TestNode *getFirstNode();
	const TestNode *next();
	QString getTestName() const;
	quint32 getNumNodes() const;
	QStringList getGroups() const;
	
	void getPercentParam(float &per2, float per3, float per4);

signals:
	void testDbLoaded();
	void testLoaded();
	void groupsLoaded();
	void netIsError(int socketError, const QString &message);

private slots:
	void requestNewTestDb(TestDB testDb);
	void requestNewTest(Test test);
	void requestNewGroups(QStringList groups);
	void netError(int socketError, const QString &message);

private:
	TestDB *tests;
	Test *currentTest;
	quint32 magicNumber;
	TestThread thread;
	QString serverName;
	quint16 serverPort;
	quint32 currentNodeId;
	quint32 numNodes;
	QStringList groups;
	QString studentName;
	QString groupName;
};

#endif // TESTMANAGER_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
