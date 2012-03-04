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

#ifndef REPORT_H
#define REPORT_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QFile>
#include "testnode.h"

class RepTmpl : public QObject
{
	
public:
	RepTmpl(QObject *parent = 0);
	
	QString tmplHTMLHead() const;
	QString tmplHTMLCloseTest() const;
	QString tmplHTMLCloseTestAnswOn() const;
	QString tmplHTMLCloseTestAnswOff() const;
	QString tmplHTMLOpenTest() const;
	QString tmplHTMLConformityTest() const;
	QString tmplHTMLConformityTestAnsw() const;
	QString tmplHTMLRegulatingTests() const;
	QString tmplHTMLRegulatingTestsAnsw() const;
	
private:
	QString _tmplHTMLHead;
	QString _tmplHTMLCloseTest;
	QString _tmplHTMLCloseTestAnswOn;
	QString _tmplHTMLCloseTestAnswOff;
	QString _tmplHTMLOpenTest;
	QString _tmplHTMLConformityTest;
	QString _tmplHTMLConformityTestAnsw;
	QString _tmplHTMLRegulatingTests;
	QString _tmplHTMLRegulatingTestsAnsw;
};

class Report : public QObject
{

public:
	Report(QObject *parent = 0, const QString &report_file_name = "report.html");
    virtual ~Report();
	
	void setNameTest(const QString &name_test);
	void setTimeTest(const QString &time_test);
	void setPercents(const float perc);
	void setOcenka(const quint8 ocenk);
	void setReportFileName(const QString &file_name);
	void writeReportFile();
	
	void addCloseNode(const TestNode *node, bool answ);
	void addOpenNode(const TestNode *node, bool answ);
	void addConformityNode(const TestNode *node, bool answ);
	void addRegulatingNode(const TestNode *node, bool answ);
	
	void clear();
	
private:
	QString nameTest;   // название теста
	QString timeTest;   // время прохождения теста
	float percents;     // процент правильных ответов
	quint8 ocenka;      // оценка
	RepTmpl tmpl;
	
	QString buffer;
	
	QString reportFileName;
	
	quint16 curNumber;
};

#endif // REPORT_H
