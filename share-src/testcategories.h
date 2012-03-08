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


#ifndef TESTCATEGORIES_H
#define TESTCATEGORIES_H

#include <QObject>
#include <QStringList>
#include <QTime>

#define FILE_NAME_SIZE 5

class TestCategories : public QObject
{

public:
	TestCategories();
	TestCategories(const TestCategories &other);
	virtual ~TestCategories();
	virtual TestCategories &operator= (const TestCategories &other);
	virtual bool operator== (const TestCategories &other) const;

	void addTest(const QString &testName, quint16 numVis, bool vis = true);
	void setData(QList<QStringList> data);
	void delTest(const QString &testName);
	bool editTest(const QString &testName, quint32 numVis, bool vis);
	void setName(const QString &name);
	void setCount(quint32 c);

	QString getTestFileByName(const QString &name) const;
	QStringList getTestList(bool all = false) const;
	quint32 count() const;
	QList<QStringList> getData() const;
	QString getName() const;
	quint32 getNumVis(const QString &testName) const;

private:
	QString name;				// Название категории
	quint32 _count;				// Количество тестов данной категории
	QList<QStringList> data;	// Список тестов

	QString newFileName();
};

QDataStream &operator << (QDataStream &out, const TestCategories &testCat);
QDataStream &operator >> (QDataStream &in, TestCategories &testCat);

#endif // TESTCATEGORIES_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
