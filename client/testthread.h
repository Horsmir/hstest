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


#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QtCore/QThread>
#include <QtCore/QWaitCondition>
#include <QtNetwork/QTcpSocket>
#include "testdb.h"
#include "test.h"

#define QT_NO_CAST_TO_ASCII


class TestThread : public QThread
{
	Q_OBJECT
	
public:
    TestThread(QObject *parent = 0);
    virtual ~TestThread();
	
	void requestTestDb(const QString &hostName, quint16 port);
	void requestTest(const QString &hostName, quint16 port, int catName, int testName);
	void requestGroups(const QString &hostName, quint16 port);
	void sendStudentData(const QString &hostName, quint16 port, const QString &studentName, const QString &groupName, const QString &testName, qreal percent, quint32 ocenka);
	void run();
	
signals:
	void newTestDb(TestDB categories);
	void newTest(Test test);
	void newGroups(QStringList groups);
	void error(int socketError, const QString &message);
	
private:
	QString hostName;
	quint16 port;
	bool quit;
	quint16 onGet;
	int catName;
	int testName;
	QString studentName;
	QString groupName;
	QString testNameStud;
	qreal percent;
	quint32 ocenka;
};

#endif // TESTTHREAD_H
