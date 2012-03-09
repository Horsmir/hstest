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


#include "testcategories.h"

TestCategories::TestCategories() :
	QObject()
{
	name = "";
	_count = 0;
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
}

TestCategories::TestCategories(const TestCategories &other) :
	QObject()
{
	name = other.name;
	data = other.data;
	_count = data.count();
}

TestCategories::~TestCategories()
{

}

TestCategories &TestCategories::operator= (const TestCategories &other)
{
	this->name = other.name;
	this->data = other.data;
	this->_count = this->data.count();
	return *this;
}

bool TestCategories::operator== (const TestCategories &other) const
{
	return ((this->name == other.name) && (this->data == other.data));
}

void TestCategories::addTest(const QString &testName, quint16 numVis, bool vis)
{
	QStringList node;
	QString fileName = newFileName();
	QString strVis = "0";
	if(vis)
		strVis = "1";

	node.append(testName);
	node.append(fileName);
	node.append(QString().setNum(numVis));
	node.append(strVis);
	data.append(node);

	_count = data.count();
}

void TestCategories::setData(QList<QStringList> data)
{
	this->data = data;
}

void TestCategories::delTest(const QString &testName)
{
	int id = -1;

	for(quint32 i = 0; i < _count; i++)
	{
		if(data.at(i).at(0) == testName)
		{
			id = i;
			break;
		}
	}
	if(id != -1)
	{
		data.removeAt(id);
		_count--;
	}
}

void TestCategories::setName(const QString &name)
{
	this->name = name;
}

QString TestCategories::getName() const
{
	return name;
}

QString TestCategories::getTestFileByName(const QString &name) const
{
	int id = -1;

	for(quint32 i = 0; i < _count; i++)
	{
		if(data.at(i).at(0) == name)
		{
			id = i;
			break;
		}
	}

	if(id == -1)
		return "";

	return data.at(id).at(1);
}

quint32 TestCategories::count() const
{
	return _count;
}

void TestCategories::setCount(quint32 c)
{
	_count = c;
}

QList< QStringList > TestCategories::getData() const
{
	return data;
}

QString TestCategories::newFileName()
{
	QString fileName = "ts";
	for(int i = 0; i < FILE_NAME_SIZE; i++)
	{
		fileName += QString().setNum(qrand() % 10);
	}
	fileName += ".tst";
	return fileName;
}

QStringList TestCategories::getTestList(bool all) const
{
	if(data.isEmpty())
		return QStringList();
	QStringList ret;
	if(all)
		for(int i = 0; i < data.count(); i++)
			ret.append(data.at(i).at(0));
	else
		for(int i = 0; i < data.count(); i++)
		{
			bool vis = data.at(i).at(3).toUInt();
			if(vis == 1)
				ret.append(data.at(i).at(0));
		}
	return ret;
}

quint32 TestCategories::getNumVis(const QString &testName) const
{
	int id = -1;

	for(quint32 i = 0; i < _count; i++)
	{
		if(data.at(i).at(0) == testName)
		{
			id = i;
			break;
		}
	}

	if(id == -1)
		return 0;

	return data.at(id).at(2).toUInt();
}

bool TestCategories::editTest(const QString &testName, quint32 numVis, bool vis)
{
	QString testFileName = getTestFileByName(testName);
	QStringList node;
	int id = -1;
	QString strVis = "0";
	if(vis)
		strVis = "1";
	
	for(quint32 i = 0; i < _count; i++)
	{
		if(data.at(i).at(0) == testName)
		{
			id = i;
			break;
		}
	}
	if(id == -1)
		return false;
	
	node << testName;
	node << testFileName;
	node << QString().setNum(numVis);
	node << strVis;
	data.removeAt(id);
	data.append(node);
	return true;
}

QDataStream &operator << (QDataStream &out, const TestCategories &testCat)
{
	out << testCat.getName() << quint32(testCat.count()) << testCat.getData();
	return out;
}

QDataStream &operator >> (QDataStream &in, TestCategories &testCat)
{
	QString name = "";
	quint32 count = 0;
	QList<QStringList> data;

	in >> name >> count >> data;
	testCat.setName(name);
	testCat.setCount(count);
	testCat.setData(data);

	return in;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
