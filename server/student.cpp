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


#include "student.h"

Student::Student(QObject *parent):
	QObject(parent), name(""), groupName("")
{

}

Student::Student(const Student &other):
	QObject(other.parent())
{
	name = other.name;
	groupName = other.groupName;
	testList = other.testList;
}

Student::~Student()
{

}

Student &Student::operator=(const Student &other)
{
	setParent(other.parent());
	name = other.name;
	groupName = other.groupName;
	testList = other.testList;
	return *this;
}

bool Student::operator==(const Student &other) const
{
	if(name != other.name)
		return false;
	if(groupName != other.groupName)
		return false;
	return true;
}

void Student::addTest(const QString &date, const QString &testName, qreal percent, quint32 ocenka)
{
	QStringList ret;
	ret << date;
	ret << testName;
	ret << QString().setNum(percent);
	ret << QString().setNum(ocenka);
	testList.append(ret);
}

QString Student::getGroupName() const
{
	return groupName;
}

QString Student::getName() const
{
	return name;
}

QStringList Student::getTestById(qint32 index) const
{
	QStringList ret;
	if(testList.count() >= index)
	{
		qDebug() << "In Student::getTestById, index > count";
		return ret;
	}
	ret = testList.at(index);
	return ret;
}

QList< QStringList > Student::getTestList() const
{
	return testList;
}

void Student::setGroupName(const QString &groupName)
{
	this->groupName = groupName;
}

void Student::setName(const QString &name)
{
	this->name = name;
}

void Student::setTestList(QList< QStringList > &testList)
{
	this->testList = testList;
}

//========================================================================================

QDataStream &operator<<(QDataStream &out, const Student &stud)
{
	out << stud.getName() << stud.getGroupName() << stud.getTestList();
	return out;
}

QDataStream &operator>>(QDataStream &in, Student &stud)
{
	QString name, groupName;
	QList<QStringList> testList;
	
	in >> name >> groupName >> testList;
	stud.setName(name);
	stud.setGroupName(groupName);
	stud.setTestList(testList);
	
	return in;
}
