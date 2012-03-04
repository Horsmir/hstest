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


#include "testmanager.h"

TestManager::TestManager ( QObject* parent ) :
    QObject ( parent )
{
    tests = new TestDB ( this );
    testsDir = "../../server/data";
    testDbFileName = "testsdb.tst";
    magicNumber = 0xAAFF452C;
}

TestManager::TestManager ( const TestManager& other ) :
    QObject ( other.parent() )
{
    tests = other.tests;
    testDbFileName = other.testDbFileName;
    testsDir = other.testsDir;
}

TestManager::~TestManager()
{

}

TestManager& TestManager::operator= ( const TestManager& other )
{
    setParent ( other.parent() );
    tests = other.tests;
    testDbFileName = other.testDbFileName;
    testsDir = other.testsDir;
    return *this;
}

bool TestManager::operator== ( const TestManager& other ) const
{
    return ( tests == other.tests );
}

bool TestManager::addCategory ( const QString& categoryName )
{
    return tests->addCategory ( categoryName );
}

bool TestManager::addTest ( const QString& categoryName, Test test )
{
    tests->addTest ( categoryName, test.getName(), test.getNumVis(), test.getVis() );
    QString testFileName = tests->getFileNameTest ( categoryName, test.getName() );

    QFile file ( testsDir + "/" + testFileName );
    if ( !file.open ( QIODevice::WriteOnly ) )
    {
        qDebug() << "Can not open file " << ( testsDir + "/" + testFileName ) << " for writing. Error: " << file.errorString();
        tests->delTest ( categoryName, test.getName() );
        return false;
    }

    QDataStream out ( &file );
    out << quint32 ( magicNumber ) << quint16 ( out.version() );
    out << test;
    return true;
}

QStringList TestManager::getCategoryList() const
{
    return tests->getCategoryNameList();
}

Test TestManager::getTest ( const QString& categoryName, const QString& testName ) const
{
    Test ret;
    quint32 magic;
    quint16 streamVersion;

    QString testFileName = tests->getFileNameTest ( categoryName, testName );
    QFile file ( testsDir + "/" + testFileName );
    if ( !file.exists() )
    {
        qDebug() << "File " << ( testsDir + "/" + testFileName ) << " no exist.";
        return ret;
    }
    if ( !file.open ( QIODevice::ReadOnly ) )
    {
        qDebug() << "Can not open file " << ( testsDir + "/" + testFileName ) << " for reading. Error: " << file.errorString();
        return ret;
    }

    QDataStream in ( &file );
    in >> magic >> streamVersion;
    if ( magic != magicNumber )
    {
        qDebug() << "File is not recognized by this application";
        return ret;
    }
    else if ( streamVersion > in.version() )
    {
        qDebug() << "File is from a more recent version of the" << "application";
        return ret;
    }

    in >> ret;
    return ret;
}

QString TestManager::getTestDbFileName() const
{
    return testDbFileName;
}

QString TestManager::getTestDir() const
{
    return testsDir;
}

Test TestManager::getTestForUse ( int categoryName, int testName ) const
{
    QString strCategoryName = tests->getCategoryNameList().at(categoryName);
    QString strTestName = tests->getTestNameListByCategory(strCategoryName).at(testName);
    Test sourceTest = getTest ( strCategoryName, strTestName );
    Test destTest;
    
    quint32 numVis = sourceTest.getNumVis();
    quint32 num = sourceTest.getCount();
    if(numVis > num)
        numVis = num;
    uint a = 0, b = 0, c = 0, j = 0;
    uint *d = new uint[num];
    
    for(uint i = 0; i < num; i++)
        d[i] = i;
    
    while(j < (num * 2))
    {
        a = qrand() % num;
        b = qrand() % num;
        c = d[a];
        d[a] = d[b];
        d[b] = c;
        j++;
    }
    
    destTest.setName(sourceTest.getName());
    destTest.setNumVis(numVis);
    
    for(uint i = 0; i < numVis; i++)
    {
        destTest.addNode(sourceTest.getNode(d[i]));
    }
    
    delete[] d;
    return destTest;
}

QStringList TestManager::getTestListByCategory ( const QString& categoryName, bool all) const
{
    return tests->getTestNameListByCategory ( categoryName, all);
}

bool TestManager::loadTestFromFile ( const QString& categoryName, const QString& testFileTextName, quint32 numVis, bool vis )
{
    Test newTest;
    newTest.readFromText ( testFileTextName );
    newTest.setNumVis ( numVis );
    if ( vis )
        newTest.setVis();
    else
        newTest.setNoVis();
    return addTest ( categoryName, newTest );
}

bool TestManager::readTestDbFromFile()
{
    QFile file;
    quint32 magic;
    quint16 streamVersion;
    TestDB newTestDb ( this );

    file.setFileName ( testsDir + "/" + testDbFileName );
    if ( !file.exists() )
    {
        qDebug() << "File " << ( testsDir + "/" + testDbFileName ) << " no exist.";
        return false;
    }
    if ( !file.open ( QIODevice::ReadOnly ) )
    {
        qDebug() << "Cannot open file for reading: " << file.errorString();
        return false;
    }

    QDataStream in ( &file );
    in >> magic >> streamVersion;

    if ( magic != magicNumber )
    {
        qDebug() << "File is not recognized by this application";
        return false;
    }
    else if ( streamVersion > in.version() )
    {
        qDebug() << "File is from a more recent version of the" << "application";
        return false;
    }

    in >> newTestDb;
    *tests = newTestDb;
    return true;
}

void TestManager::setTestDbFileName ( const QString& testDbFileName )
{
    this->testDbFileName = testDbFileName;
}

void TestManager::setTestDir ( const QString& testDirName )
{
    this->testsDir = testDirName;
}

bool TestManager::writeTestDbToFile()
{
    QFile file ( testsDir + "/" + testDbFileName );

    if ( !file.open ( QIODevice::WriteOnly ) )
    {
        qDebug() << "Cannot open file for writing: " << file.errorString();
        return false;
    }

    QDataStream out ( &file );
    out << quint32 ( magicNumber ) << quint16 ( out.version() );
    out << *tests;
    return true;
}

TestDB TestManager::getCategories() const
{
    return *tests;
}

bool TestManager::delCategory ( const QString& catName )
{
    return tests->delCategory(catName);
}

TestDB *TestManager::getCategoriesPtr() const
{
    return tests;
}

bool TestManager::delTest(const QString &catName, const QString &testName)
{
    QString testFileName = tests->getFileNameTest(catName, testName);
    bool ok = QFile::remove(testsDir + "/" + testFileName);
    if(ok)
        return tests->delTest(catName, testName);
    return false;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
