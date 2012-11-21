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


#ifndef SESSION_H
#define SESSION_H

#include <QtCore/QObject>

class Test;
class QSettings;
class QDate;
class QTime;

class Session : public QObject
{
	Q_OBJECT
public:
	explicit Session(QObject *parent = 0);
	virtual ~Session();
	
	void setCloseSession(bool var);
	void setCurrentNumTask(int *curNumTask);
	void setNumRealAnswers(int *numRealAnswers);
	void setCurrentTime(QTime *currentTime);
	void setModeType(quint16 modeType);
	void setStudentName(const QString &studentName);
	void setGroupName(const QString &groupName);
	void setTest(Test *test);
	void setMagicNumber(quint32 magicNumber);
	void writeValues();
	
	bool isCloseSession() const;
	void getValues();
	quint16 getModeType() const;
	QString getStudentName() const;
	QString getGroupName() const;
	QString getSessionTestFilePath() const;
	Test getTest();
	int getCurrentNumTask();
	
private:
	bool closeSession; // true - сессия закрыта, false - открыта
	QString sessionTestFileName; // имя резервного файла
	int *currenNumTask; // номер текущего задания
	int *numRealAnswers; // количество правильных ответов
	QTime *currentTime; // текущее время прохождение файла
	QDate currentDate; // текущая дата
	QString sessionDir; // каталог файлов сессии
	QSettings *settingsSession; // хранение настроек сессии
	quint32 magicNumber; // идентификатор файла с тестом
	quint16 modeType; // режим тестирования
	QString studentName;
	QString groupName;
};

#endif // SESSION_H
