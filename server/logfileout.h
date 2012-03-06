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


#ifndef LOGFILEOUT_H
#define LOGFILEOUT_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QTextStream>
#include <QtCore/QFile>


class LogFileOut : public QObject
{

public:
	LogFileOut(QObject *parent = 0);
	LogFileOut(const QString &logFilePath, QObject *parent = 0);
	LogFileOut(const LogFileOut& other);
	virtual ~LogFileOut();
	virtual LogFileOut &operator=(const LogFileOut &other);
	virtual bool operator==(const LogFileOut &other) const;
	
	void setLogFilePath(const QString &logFilePath);
	
	bool write(const QString &message);
	
	LogFileOut& operator <<(const QString &str);
	
private:
	QString logFilePath;
};

#endif // LOGFILEOUT_HOUT_H
