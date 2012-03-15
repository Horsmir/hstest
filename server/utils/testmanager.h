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


#ifndef TESTMANAGER_H
#define TESTMANAGER_H

#include <QDebug>
#include <QObject>
#include "testdb.h"
#include "test.h"
#include "studentdb.h"


class TestManager : public QObject
{

public:
	TestManager(QObject *parent = 0);
	TestManager(const TestManager &other);
	virtual ~TestManager();
	virtual TestManager &operator= (const TestManager &other);
	virtual bool operator== (const TestManager &other) const;

	bool readTestDbFromFile();
	bool readStudentDbFromFile();
	bool writeTestDbToFile();
	bool writeStudentDbToFile();

	void setTestDir(const QString &testDirName);
	void setTestDbFileName(const QString &testDbFileName);

	bool addCategory(const QString &categoryName);
	bool loadTestFromFile(const QString &categoryName, const QString &testFileTextName, quint32 numVis, bool vis = true);

	QStringList getCategoryList() const;
	QStringList getTestListByCategory(const QString &categoryName, bool all = false) const;
	Test getTestForUse(int categoryName, int testName) const;
	TestDB getCategories() const;
	TestDB *getCategoriesPtr() const;
	Test getTest(const QString &categoryName, const QString &testName) const;

	QString getTestDir() const;
	QString getTestDbFileName() const;

	bool delCategory(const QString &catName);
	bool delTest(const QString &catName, const QString &testName);
	bool editTest(const QString &catName, const QString &testName, const quint32 numVis, const bool vis);
	
	void addGroup(const QString &group);
	QStringList getGroupsList() const;

private:
	TestDB *tests;
	StudentDb *students;
	QString testsDir;
	QString testDbFileName;
	QString studentDbFileName;
	quint32 magicNumber;

	bool addTest(const QString &categoryName, Test test);
};

#endif // TESTMANAGER_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
