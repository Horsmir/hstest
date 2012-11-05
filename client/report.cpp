/*
    Create HTML-report.
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


#include <QtCore/QFile>
#include "report.h"

RepTmpl::RepTmpl(QObject *parent):
	QObject(parent)
{
	_tmplHTMLHead = QObject::trUtf8("<html>\n<head>\n<meta name=\"qrichtext\" content=\"1\" />\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />\n<title>Report</title>\n<style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style>\n</head>\n<body style=\" font-size:12pt; font-weight:400; font-style:normal; text-decoration:none;\">\n<center>\n<h1>Результат тестирования</h2>\n</center>\n<hr />\n<p align=\"left\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\n<b>Тест:</b> %1<br />\n<b>Время решения теста:</b> %2<br />\n<b>Процент верных ответов:</b> %3<br />\n<b>Оценка:</b> %4</p><hr />\n");
	
	_tmplHTMLCloseTestAnswOn = QObject::trUtf8("+|%1<br />\n");
	
	_tmplHTMLCloseTestAnswOff = QObject::trUtf8("-|%1<br />\n");
	
	_tmplHTMLCloseTest = QObject::trUtf8("<h2 style=\"background: #%1\">Задание №%2</h2>\n<p align=\"left\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\n<i>%3</i><br />\n<b>Вопрос:</b> %4<br />\n\%5\n</p>\n<hr />\n");
	
	_tmplHTMLOpenTest = QObject::trUtf8("<h2 style=\"background: #%1\">Задание №%2</h2>\n<p align=\"left\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\n<i>%3</i><br />\n<b>Вопрос:</b> %4<br />\n<b>Ответ:</b> %5\n</p>\n<hr />\n");
	
	_tmplHTMLConformityTest = QObject::trUtf8("<h2 style=\"background: #%1\">Задание №%2</h2>\n<i>%3</i><br />\n<table border=\"1\" align=\"left\" cellspacing=\"0\" cellpadding=\"4\">\n%4\n</table>\n<hr />\n");
	
	_tmplHTMLConformityTestAnsw = QObject::trUtf8("<tr><td>%1</td>\n<td>%2</td>\n</tr>");
	_tmplHTMLRegulatingTests = QObject::trUtf8("<h2 style=\"background: #%1\">Задание №%2</h2>\n<i>%3</i><br />\n<ol style=\"-qt-list-indent: 1;\">\n%4\n</ol>\n<hr />\n");
	
	_tmplHTMLRegulatingTestsAnsw = QObject::trUtf8("<li>%1</li>\n");
}

QString RepTmpl::tmplHTMLHead() const
{
	return _tmplHTMLHead;
}

QString RepTmpl::tmplHTMLCloseTest() const
{
	return _tmplHTMLCloseTest;
}

QString RepTmpl::tmplHTMLCloseTestAnswOn() const
{
	return _tmplHTMLCloseTestAnswOn;
}

QString RepTmpl::tmplHTMLCloseTestAnswOff() const
{
	return _tmplHTMLCloseTestAnswOff;
}

QString RepTmpl::tmplHTMLOpenTest() const
{
	return _tmplHTMLOpenTest;
}

QString RepTmpl::tmplHTMLConformityTest() const
{
	return _tmplHTMLConformityTest;
}

QString RepTmpl::tmplHTMLConformityTestAnsw() const
{
	return _tmplHTMLConformityTestAnsw;
}

QString RepTmpl::tmplHTMLRegulatingTests() const
{
	return _tmplHTMLRegulatingTests;
}

QString RepTmpl::tmplHTMLRegulatingTestsAnsw() const
{
	return _tmplHTMLRegulatingTestsAnsw;
}

//============================================================================//

Report::Report(QObject *parent, const QString &report_file_name):
	QObject(parent), reportFileName(report_file_name)
{
	nameTest = "";
	timeTest = "";
	percents = 0;
	ocenka = 0;
	buffer = "";
	curNumber = 1;
}

Report::~Report()
{

}

void Report::setNameTest(const QString &name_test)
{
	nameTest = name_test;
}

void Report::setTimeTest(const QString &time_test)
{
	timeTest = time_test;
}

void Report::setPercents(const float perc)
{
	percents = perc;
}

void Report::setOcenka(const quint8 ocenk)
{
	ocenka = ocenk;
}

void Report::setReportFileName(const QString &file_name)
{
	reportFileName = file_name;
}

void Report::writeReportFile()
{
	QFile file(reportFileName);
	if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
		qDebug() << "no open file " << reportFileName;
	
	QTextStream out(&file);
	out << tmpl.tmplHTMLHead().arg(nameTest).arg(timeTest).arg(percents).arg(ocenka);
	out << buffer;
	out << QString("</body></html>");
	file.close();
}

void Report::addCloseNode(const TestNode *node, bool answ)
{
	QString answers = "", color;
	int ransw = 0;
	for(int i = 0; i < node->getAnswers().count(); i++)
	{
		ransw = int(node->getRealsInt()) & int(std::pow(2, i));
		if(ransw == 0)
		{
			answers += tmpl.tmplHTMLCloseTestAnswOff().arg(node->getAnswers().at(i));
		}
		else
		{
			answers += tmpl.tmplHTMLCloseTestAnswOn().arg(node->getAnswers().at(i));
		}
	}
	if(answ)
		color = "00ff00";
	else
		color = "ff0000";
	
	buffer += tmpl.tmplHTMLCloseTest().arg(color).arg(curNumber).arg(node->getTask()).arg(node->getQuestion()).arg(answers);
	curNumber++;
}

void Report::addOpenNode(const TestNode *node, bool answ)
{
	QString color;
	if(answ)
		color = "00ff00";
	else
		color = "ff0000";
	
	buffer += tmpl.tmplHTMLOpenTest().arg(color).arg(curNumber).arg(node->getTask()).arg(node->getQuestion()).arg(node->getAnswers().at(0));
	curNumber++;
}

void Report::addConformityNode(const TestNode *node, bool answ)
{
	QString answers = "", color, tmp_quest;
	if(answ)
		color = "00ff00";
	else
		color = "ff0000";
	
	for(int i = 0; i < node->getAnswers().count(); i++)
	{
		if(i >= node->getQuestions().count())
			tmp_quest = "";
		else
			tmp_quest = node->getQuestions().at(i);
		
		int p = node->getReals().indexOf(QString().setNum(i + 1));
		if(p == -1)
			p = node->getReals().indexOf('0');
		
		answers += tmpl.tmplHTMLConformityTestAnsw().arg(tmp_quest).arg(node->getAnswers().at(p));
	}
	buffer += tmpl.tmplHTMLConformityTest().arg(color).arg(curNumber).arg(node->getTask()).arg(answers);
	curNumber++;
}

void Report::addRegulatingNode(const TestNode *node, bool answ)
{
	QString answers = "", color;
	if(answ)
		color = "00ff00";
	else
		color = "ff0000";
	
	for(int i = 0; i < node->getAnswers().count(); i++)
	{
		int p = node->getReals().indexOf(QString().setNum(i + 1));;
		answers += tmpl.tmplHTMLRegulatingTestsAnsw().arg(node->getAnswers().at(p));
	}
	buffer += tmpl.tmplHTMLRegulatingTests().arg(color).arg(curNumber).arg(node->getTask()).arg(answers);
	curNumber++;
}

void Report::clear()
{
	buffer.clear();
	nameTest = "";
	timeTest = "";
	percents = 0;
	ocenka = 0;
	curNumber = 1;
}