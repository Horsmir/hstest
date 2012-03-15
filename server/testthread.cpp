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

TestThread::TestThread(): 
	QThread(0), testManager(0), blockSize(0)
{
	
}

TestThread::TestThread(int socketDescriptor, TestManager* testManager): 
	QThread(0), socketDescriptor(socketDescriptor), testManager(testManager), blockSize(0)
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
	
	QTextStream in(&tcpSocket);
	command = in.readLine();
	
	int com = command.split('|').at(1).toInt();
	if(com == 2)
	{
		catName = command.split('|').at(2);
		testName = command.split('|').at(3);
	}
	if(com == 4)
	{
		QStringList lcom = command.split('|');
		testManager->addStudent(lcom.at(2), lcom.at(3), lcom.at(4), lcom.at(5).toDouble(), lcom.at(6).toUInt());
		return;
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
		case 3:
			out << testManager->getGroupsList();
			break;
	}
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	
	tcpSocket.write(block);
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}

#include "testthread.moc"