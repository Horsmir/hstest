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


#include "testthread.h"

TestThread::TestThread(QObject* parent): 
	QThread(parent), socketDescriptor(0), testManager(0), blockSize(0)
{
	
}

TestThread::TestThread(int socketDescriptor, TestManager* testManager, QObject* parent): 
	QThread(parent), socketDescriptor(socketDescriptor), testManager(testManager), blockSize(0)
{
	
}

void TestThread::run()
{
    QTcpSocket tcpSocket;
	QString command, testName, catName;
	
	if(!tcpSocket.setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket.error());
		return;
	}
	
	//QDataStream in(&tcpSocket);
	//in >> command;
	while(tcpSocket.bytesAvailable() <= 0)
	{
		if(!tcpSocket.waitForReadyRead(50000))
		{
			tcpSocket.disconnectFromHost();
			tcpSocket.waitForDisconnected();
			return;
		}
	}
	
	//if(tcpSocket.canReadLine())
		command = tcpSocket.readLine();
	
	int com = command.split('|').at(1).toInt();
	if(com == 2)
	{
		catName = command.split('|').at(2);
		testName = command.split('|').at(3);
	}
	
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out << quint16(0);
		
	switch(com)
	{
		case 1:
			out << testManager->getCategories();
			break;
		case 2:
			out << testManager->getTestForUse(catName.toInt(), testName.toInt());
			break;
	}
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	
	tcpSocket.write(block);
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}

#include "testthread.moc"