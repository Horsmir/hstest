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


#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include "logfileout.h"

LogFileOut::LogFileOut(QObject *parent):
	QObject(parent)
{
	logFilePath = "/var/log/hstest/server.log";
}

LogFileOut::LogFileOut(const QString &logFilePath, QObject *parent): QObject(parent)
{
	this->logFilePath = logFilePath;
}

LogFileOut::LogFileOut(const LogFileOut &other):
	QObject(other.parent())
{
	logFilePath = other.logFilePath;
}

LogFileOut::~LogFileOut()
{

}

LogFileOut &LogFileOut::operator=(const LogFileOut &other)
{
	setParent(other.parent());
	logFilePath = other.logFilePath;
	return *this;
}

bool LogFileOut::operator==(const LogFileOut &other) const
{
	return (logFilePath == other.logFilePath);
}

void LogFileOut::setLogFilePath(const QString &logFilePath)
{
	this->logFilePath = logFilePath;
}

bool LogFileOut::write(const QString &message) 
{
	QFile file(logFilePath);
	if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Can not open file " << logFilePath;
        return false;
    }
	QTextStream out(&file);
	out << message << "\n";
	return true;
}

LogFileOut &LogFileOut::operator<<(const QString &str)
{
	write(str);
	return *this;
}
