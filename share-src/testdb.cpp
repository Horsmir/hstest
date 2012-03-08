/*
    Class test data base.
    Copyright (C) 2012  Roman Brown firdragon76@gmail.com

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


#include "testdb.h"
#include <qmetatype.h>

TestDB::TestDB(QObject *parent) :
	QObject(parent)
{

}

TestDB::TestDB(const TestDB &other) :
	QObject(other.parent())
{
	this->categories = other.categories;
}

TestDB::~TestDB()
{

}

TestDB &TestDB::operator= (const TestDB &other)
{
	this->setParent(other.parent());
	this->categories = other.categories;
	return *this;
}

bool TestDB::operator== (const TestDB &other) const
{
	return (this->categories == other.categories);
}

bool TestDB::addCategory(const QString &catName)
{
	int existCat = getCategoryNameList().indexOf(catName);

	if(existCat != -1)
		return false;

	TestCategories newCat;
	newCat.setName(catName);
	categories.append(newCat);
	return true;
}

void TestDB::addTest(const QString &catName, const QString &testName, quint16 numVis, bool vis)
{
	qint32 id = getCategoryIdByName(catName);

	if(id != -1)
		categories[id].addTest(testName, numVis, vis);
}

QStringList TestDB::getCategoryNameList() const
{
	QStringList ret;
	for(int i = 0; i < categories.count(); i++)
		ret.append(categories.at(i).getName());
	return ret;
}

qint32 TestDB::getCategoryIdByName(const QString &catName) const
{
	qint32 id = -1;
	for(int i = 0; i < categories.count(); i++)
	{
		if(categories.at(i).getName() == catName)
		{
			id = i;
			break;
		}
	}
	return id;
}

QStringList TestDB::getTestNameListByCategory(const QString &catName, bool all) const
{
	QStringList ret;
	TestCategories cat;
	qint32 id = getCategoryIdByName(catName);
	if(id != -1)
	{
		cat = categories[id];
		if(cat.count() != 0)
			ret = cat.getTestList(all);
	}
	return ret;
}

QString TestDB::getFileNameTest(const QString &catName, const QString &testName) const
{
	qint32 id = getCategoryIdByName(catName);
	if(id != -1)
		return categories.at(id).getTestFileByName(testName);
	else
		return "";
}

quint32 TestDB::getNumVis(const QString &catName, const QString &testName) const
{
	qint32 id = getCategoryIdByName(catName);
	if(id != -1)
		return categories.at(id).getNumVis(testName);
	else
		return 0;
}

QList< TestCategories > TestDB::getCategories() const
{
	return categories;
}

void TestDB::setCategories(QList< TestCategories > categories)
{
	this->categories = categories;
}

bool TestDB::delCategory(const QString &catName)
{
	qint32 id = getCategoryIdByName(catName);
	if(id == -1)
		return false;
	if(categories.at(id).count() > 0)
		return false;
	categories.removeAt(id);
	return true;
}

bool TestDB::delTest(const QString &catName, const QString &testName)
{
	qint32 id = getCategoryIdByName(catName);
	if(id == -1)
		return false;
	categories[id].delTest(testName);
	return true;
}

bool TestDB::editTest(const QString &catName, const QString &testName, const quint32 numVis, const bool vis)
{
	qint32 id = getCategoryIdByName(catName);
	if(id == -1)
		return false;
	categories[id].editTest(testName, numVis, vis);
	return true;
}

QDataStream &operator << (QDataStream &out, const TestDB &testDb)
{
	out << testDb.getCategories();
	return out;
}

QDataStream &operator >> (QDataStream &in, TestDB &testDb)
{
	QList<TestCategories> cats;

	in >> cats;
	testDb.setCategories(cats);
	return in;
}

Q_DECLARE_METATYPE(TestDB);

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
