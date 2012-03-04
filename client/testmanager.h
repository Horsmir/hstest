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
#include "testthread.h"


class TestManager : public QObject
{
    Q_OBJECT
    
public:
    TestManager ( QObject *parent = 0 );
    TestManager ( const TestManager& other );
    virtual ~TestManager();
    virtual TestManager& operator= ( const TestManager& other );
    virtual bool operator== ( const TestManager& other ) const;

    void loadTestDb();
    void loadTest(const QString &catName, const QString &testName);
    
    void setServerParm(const QString &serverName, quint16 serverPort);

    QStringList getCategoryList() const;
    QStringList getTestListByCategory ( const QString &categoryName, bool all = false) const;
    
    TestDB getCategories() const;
    TestDB* getCategoriesPtr() const;
    
    const TestNode * getFirstNode();
    const TestNode * next();
    QString getTestName() const;
    quint32 getNumNodes() const;
        
signals:
    void testDbLoaded();
    void testLoaded();
    void netIsError(int socketError, const QString &message);
    
private slots:
    void requestNewTestDb(TestDB testDb);
    void requestNewTest(Test test);
    void netError(int socketError, const QString &message);

private:
    TestDB *tests;
    Test *currentTest;
    quint32 magicNumber;
    TestThread thread;
    QString serverName;
    quint16 serverPort;
    quint32 currentNodeId;
    quint32 numNodes;

    Test getTest ( const QString &categoryName, const QString &testName ) const;
};

#endif // TESTMANAGER_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
