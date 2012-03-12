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


#ifndef STUDENTDB_H
#define STUDENTDB_H

#include <QtCore/QObject>
#include <QtCore/QDate>
#include "student.h"


class StudentDb : public QObject
{

public:
	StudentDb(QObject *parent);
	StudentDb(const StudentDb &other);
	virtual ~StudentDb();
	virtual StudentDb &operator=(const StudentDb &other);
	
	void addNewStudent(const QString &studentName, const QString &groupName);
	void addGroup(const QString &group);
	void addTestForStudent(const QString &studentName, const QString &groupName, const QString &testName, qreal percent, quint32 ocenka);
	
	void setStudents(QList<Student> students);
	void setGroups(QStringList groups);
	
	QStringList getGroups() const;
	Student getStudentByName(const QString &studentName, const QString &groupName) const;
	QList<Student> getStudents() const;
	
private:
	QList<Student> students;
	QStringList groups;
};

QDataStream &operator <<(QDataStream &out, const StudentDb &db);
QDataStream &operator >>(QDataStream &in, StudentDb &db);

#endif // STUDENTDB_H
