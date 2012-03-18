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


#ifndef STUDENT_H
#define STUDENT_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QStringList>


class Student : public QObject
{

public:
	Student(QObject *parent = 0);
	Student(const Student &other);
	virtual ~Student();
	virtual Student &operator=(const Student &other);
	virtual bool operator==(const Student &other) const;
	
	void setName(const QString &name);
	void setGroupName(const QString &groupName);
	void addTest(const QString &date, const QString &testName, qreal percent, quint32 ocenka);
	void setTestList(QList<QStringList> &testList);
	
	QString getName() const;
	QString getGroupName() const;
	QList<QStringList> getTestList() const;
	QStringList getTestById(qint32 index) const;
	QList<QStringList> getTestListWithStud() const;
	
private:
	QString name;
	QString groupName;
	QList<QStringList> testList;
};

QDataStream &operator <<(QDataStream &out, const Student &stud);
QDataStream &operator >>(QDataStream &in, Student &stud);

#endif // STUDENT_H
