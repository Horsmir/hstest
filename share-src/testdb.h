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


#ifndef TESTDB_H
#define TESTDB_H

#include <QObject>
#include <QMetaType>
#include "testcategories.h"


class TestDB : public QObject
{

public:
	TestDB(QObject *parent = 0);
	TestDB(const TestDB &other);
	virtual ~TestDB();
	virtual TestDB &operator= (const TestDB &other);
	virtual bool operator== (const TestDB &other) const;

	bool addCategory(const QString &catName);
	void addTest(const QString &catName, const QString &testName, quint16 numVis, bool vis = true);
	void setCategories(QList<TestCategories> categories);

	QStringList getCategoryNameList() const;
	QStringList getTestNameListByCategory(const QString &catName, bool all = false) const;
	QString getFileNameTest(const QString &catName, const QString &testName) const;
	quint32 getNumVis(const QString &catName, const QString &testName) const;
	QList<TestCategories> getCategories() const;

	bool delCategory(const QString &catName);
	bool delTest(const QString &catName, const QString &testName);

	bool editTest(const QString &catName, const QString &testName, const quint32 numVis, const bool vis);

private:
	QList<TestCategories> categories;

	qint32 getCategoryIdByName(const QString &catName) const;
};

QDataStream &operator << (QDataStream &out, const TestDB &testDb);
QDataStream &operator >> (QDataStream &in, TestDB &testDb);

#endif // TESTDB_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
