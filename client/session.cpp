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


#include <QtCore/QDebug>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QSettings>
#include <QtCore/QDir>
#include "hstestconfigure.h"
#include "test.h"
#include "session.h"

Session::Session(QObject *parent): QObject(parent), closeSession(false), currenNumTask(0), currentTime(0), numRealAnswers(0), magicNumber(0), modeType(0), currentCatName(0)
{
	sessionTestFileName = "hstestsession.tst";
	currentDate = QDate::currentDate();
	sessionDir = QDir::homePath() + "/.hstest";
	settingsSession = new QSettings(sessionDir + "/session", QSettings::NativeFormat, this);
	settingsSession->setValue("Session/Date", currentDate);
	closeSession = settingsSession->value("Session/CloseSession", true).toBool();
	studentName = QString();
	groupName = QString();
}

Session::~Session()
{

}

QString Session::getSessionTestFilePath() const
{
	return sessionDir + "/" + sessionTestFileName;
}

void Session::getValues()
{
	*currenNumTask = settingsSession->value("Session/CurrentNumTask", 0).toInt();
	*currentTime = settingsSession->value("Session/CurrentTime", QTime()).toTime();
	*numRealAnswers = settingsSession->value("Session/NumRealAnswer", 0).toInt();
	modeType = settingsSession->value("Session/ModeType", 0).toUInt();
	*currentCatName = settingsSession->value("Session/CurrentCatName", QString()).toString();
	studentName = settingsSession->value("Session/StudentName", QString()).toString();
	groupName = settingsSession->value("Session/GroupName", QString()).toString();
}

bool Session::isCloseSession() const
{
	return closeSession;
}

void Session::setCloseSession(bool var)
{
	closeSession = var;
	settingsSession->setValue("Session/CloseSession", closeSession);
}

void Session::setCurrentNumTask(int *curNumTask)
{
	this->currenNumTask = curNumTask;
}

void Session::setCurrentTime(QTime *currentTime)
{
	this->currentTime = currentTime;
}

void Session::setNumRealAnswers(int *numRealAnswers)
{
	this->numRealAnswers = numRealAnswers;
}

void Session::writeValues()
{
	settingsSession->setValue("Session/CurrentNumTask", *currenNumTask);
	settingsSession->setValue("Session/CurrentTime", *currentTime);
	settingsSession->setValue("Session/NumRealAnswer", *numRealAnswers);
	settingsSession->setValue("Session/ModeType", modeType);
	settingsSession->setValue("Session/CurrentCatName", *currentCatName);
	settingsSession->setValue("Session/StudentName", studentName);
	settingsSession->setValue("Session/GroupName", groupName);
}

Test Session::getTest()
{
	Test ret;
	quint32 magic;
	quint16 streamVersion;
	
	QFile file(getSessionTestFilePath());
	if(!file.exists())
	{
		qDebug() << "File " << getSessionTestFilePath() << " no exist.";
		return ret;
	}
	if(!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Can not open file " << getSessionTestFilePath() << " for reading. Error: " << file.errorString();
		return ret;
	}
	
	QDataStream in(&file);
	in >> magic >> streamVersion;
	if(magic != magicNumber)
	{
		qDebug() << "File is not recognized by this application";
		return ret;
	}
	else if(streamVersion > in.version())
	{
		qDebug() << "File is from a more recent version of the" << "application";
		return ret;
	}
	
	in >> ret;
	return ret;
}

void Session::setMagicNumber(quint32 magicNumber)
{
	this->magicNumber = magicNumber;
}

void Session::setTest(Test *test)
{
	QFile file(getSessionTestFilePath());
	if(!file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Can not open file " << getSessionTestFilePath() << " for writing. Error: " << file.errorString();
		return;
	}
	
	QDataStream out(&file);
	out << quint32(magicNumber) << quint16(out.version());
	out << *test;
}

int Session::getCurrentNumTask()
{
	return *currenNumTask;
}

QString Session::getGroupName() const
{
	return groupName;
}

quint16 Session::getModeType() const
{
	return modeType;
}

QString Session::getStudentName() const
{
	return studentName;
}

void Session::setGroupName(const QString &groupName)
{
	this->groupName = groupName;
}

void Session::setModeType(quint16 modeType)
{
	this->modeType = modeType;
}

void Session::setStudentName(const QString &studentName)
{
	this->studentName = studentName;
}

void Session::setCurrentCatName(QString *currentCatName)
{
	this->currentCatName = currentCatName;
}

#include "session.moc"