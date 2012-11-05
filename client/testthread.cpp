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


#include <QtCore/QWaitCondition>
#include <QtNetwork/QTcpSocket>
#include "testthread.h"


TestThread::TestThread(QObject *parent):
	QThread(parent), quit(false)
{
	onGet = 0;
}

TestThread::~TestThread()
{
	quit = true;
}

void TestThread::requestTestDb(const QString &hostName, quint16 port)
{
	this->hostName = hostName;
	this->port = port;
	onGet = 1;
	if(!isRunning())
		start();
}

void TestThread::requestTest(const QString &hostName, quint16 port, int catName, int testName)
{
	this->hostName = hostName;
	this->port = port;
	onGet = 2;
	this->catName = catName;
	this->testName = testName;
	if(!isRunning())
		start();
}

void TestThread::requestGroups(const QString &hostName, quint16 port)
{
	this->hostName = hostName;
	this->port = port;
	onGet = 3;
	if(!isRunning())
		start();
}

void TestThread::sendStudentData(const QString &hostName, quint16 port, const QString &studentName, const QString &groupName, const QString &testName, qreal percent, quint32 ocenka)
{
	this->hostName = hostName;
	this->port = port;
	onGet = 4;
	this->studentName = studentName;
	this->groupName = groupName;
	this->testNameStud = testName;
	this->percent = percent;
	this->ocenka = ocenka;
	if(!isRunning())
		start();
}

void TestThread::run()
{
	QString serverName = hostName;
	quint16 serverPort = port;
	
	while(!quit)
	{
		const int Timeout = 50 * 1000;
		QByteArray query = "";
		QTcpSocket socket;
		socket.connectToHost(serverName, serverPort);
		
		if(!socket.waitForConnected(Timeout))
		{
			emit error(socket.error(), socket.errorString());
			return;
		}
		
		QTextStream out(&query);
		switch(onGet)
		{
			case 1:
				query.append(QString("GET|1|\n").toUtf8());
				break;
			case 2:
				query.append(QString("GET|2|%1|%2|\n").arg(catName).arg(testName).toUtf8());
				break;
			case 3:
				query.append(QString("GET|3|\n").toUtf8());
				break;
			case 4:
				query.append(QString("POST|4|%1|%2|%3|%4|%5|\n").arg(studentName).arg(groupName).arg(testNameStud).arg(QString().setNum(percent, 'f', 2)).arg(ocenka).toUtf8());
				socket.write(query);
				if(!socket.waitForBytesWritten(Timeout))
				{
					emit error(socket.error(), socket.errorString());
				}
				return;
		}
		
		socket.write(query);
		if(!socket.waitForBytesWritten(Timeout))
		{
			emit error(socket.error(), socket.errorString());
			return;
		}
		
		while(socket.bytesAvailable() < (int)sizeof(quint16))
		{
			if(!socket.waitForReadyRead(Timeout))
			{
				emit error(socket.error(), socket.errorString());
				return;
			}
		}
		
		quint16 blockSize;
		QDataStream in(&socket);
		in >> blockSize;
		
		while(socket.bytesAvailable() < blockSize)
		{
			if(!socket.waitForReadyRead(Timeout))
			{
				emit error(socket.error(), socket.errorString());
				return;
			}
		}
		
		if(onGet == 1)
		{
			qRegisterMetaType<TestDB>("TestDB");
			TestDB testDb;
			in >> testDb;
			emit newTestDb(testDb);
		}
		else if(onGet == 2)
		{
			qRegisterMetaType<Test>("Test");
			Test test;
			in >> test;
			emit newTest(test);
		}
		else if(onGet == 3)
		{
			QStringList groups;
			in >> groups;
			emit newGroups(groups);
		}
		
		socket.disconnectFromHost();
		return;
	}
}

#include "testthread.moc"