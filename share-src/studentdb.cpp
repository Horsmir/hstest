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


#include "studentdb.h"

StudentDb::StudentDb(QObject *parent): 
	QObject(parent)
{

}

StudentDb::StudentDb(const StudentDb &other)
{
	setParent(other.parent());
	students = other.students;
	groups = other.groups;
}

StudentDb::~StudentDb()
{

}

StudentDb &StudentDb::operator=(const StudentDb &other)
{
	students = other.students;
	groups = other.groups;
	return *this;
}

void StudentDb::addNewStudent(const QString &studentName, const QString &groupName)
{
	Student newStudent;
	newStudent.setName(studentName);
	newStudent.setGroupName(groupName);
	for(int i = 0; i < students.count(); i++)
	{
		if(newStudent == students.at(i))
			return;
	}
	
	students.append(newStudent);
}

void StudentDb::addGroup(const QString &group)
{
	int id = groups.indexOf(group);
	if(id == -1)
		groups.append(group);
}

void StudentDb::addTestForStudent(const QString &studentName, const QString &groupName, const QString &testName, qreal percent, quint32 ocenka)
{
	int stud = -1;
	bool ok = false;
	for(int i = 0; i < students.count(); i++)
	{
		if(studentName == students.at(i).getName() && groupName == students.at(i).getGroupName())
		{
			ok = true;
			stud = i;
			break;
		}
	}
	
	if(!ok)
	{
		addNewStudent(studentName, groupName);
		stud = students.count() - 1;
	}
	
	QDate today = QDate::currentDate();
	students[stud].addTest(today.toString("dd.MM.yyyy"), testName, percent, ocenka);
}

void StudentDb::setStudents(QList< Student > students)
{
	this->students = students;
}

void StudentDb::setGroups(QStringList groups)
{
	this->groups = groups;
}

QStringList StudentDb::getGroups() const
{
	return groups;
}

Student StudentDb::getStudentByName(const QString &studentName, const QString &groupName) const
{
	Student ret;
	for(int i = 0; i < students.count(); i++)
	{
		if(studentName == students.at(i).getName() && groupName == students.at(i).getGroupName())
			ret = students.at(i);
	}
	return ret;
}

QList< Student > StudentDb::getStudents() const
{
	return students;
}

QList<QStringList> StudentDb::select(bool chDate, bool chGroup, bool chName, QDate from, QDate to, const QString &groupName, const QString &studentName)
{
	QList<QStringList> tmpAll, tmp1;
	
	tmpAll = select();
	
	if(chDate)
	{
		for(int i = 0; i < tmpAll.count(); i++)
		{
			QDate studDate = QDate::fromString(tmpAll.at(i).at(2), "dd.MM.yyyy");
			if(studDate >= from && studDate <= to)
				tmp1 << tmpAll.at(i);
		}
		tmpAll = tmp1;
	}
	
	if(chGroup)
	{
		tmp1.clear();
		for(int i = 0; i < tmpAll.count(); i++)
		{
			if(tmpAll.at(i).at(1) == groupName)
				tmp1 << tmpAll.at(i);
		}
		tmpAll = tmp1;
	}
	
	if(chName)
	{
		tmp1.clear();
		for(int i = 0; i < tmpAll.count(); i++)
		{
			if(tmpAll.at(i).at(0) == studentName)
				tmp1 << tmpAll.at(i);
		}
		tmpAll = tmp1;
	}
	return tmpAll;
}

QList< QStringList > StudentDb::select()
{
	QList<QStringList> ret;
	for(int i = 0; i < students.count(); i++)
	{
		ret += students.at(i).getTestListWithStud();
	}
	return ret;
}

//============================================================================================================//

QDataStream &operator<<(QDataStream &out, const StudentDb &db)
{
	out << db.getStudents() << db.getGroups();
	return out;
}

QDataStream &operator>>(QDataStream &in, StudentDb &db)
{
	QList<Student> studs;
	QStringList groups;
	
	in >> studs >> groups;
	db.setStudents(studs);
	db.setGroups(groups);
	
	return in;
}
