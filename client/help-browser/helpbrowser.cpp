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


#include "helpbrowser.h"

HelpBrowser::HelpBrowser(QWidget *parent, Qt::WindowFlags f) : QWidget(parent), ui(new Ui::helpForm)
{
	ui->setupUi(this);
}

HelpBrowser::HelpBrowser(const QString &path, const QString &page, QWidget *parent): QWidget(parent), ui(new Ui::helpForm)
{
	ui->setupUi(this);
	
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_GroupLeader);
	
	ui->textBrowser->setSearchPaths(QStringList() << path << ":/images" << ":/icons");
	ui->textBrowser->setSource(page);
	
	connect(ui->textBrowser, SIGNAL(sourceChanged(QUrl)), SLOT(updateWindowTitle()));
}

HelpBrowser::~HelpBrowser()
{
	delete ui;
}

void HelpBrowser::updateWindowTitle()
{
	setWindowTitle(trUtf8("Справка: %1").arg(ui->textBrowser->documentTitle()));
}

void HelpBrowser::showPage(const QString &path, const QString &page)
{
	HelpBrowser *browser = new HelpBrowser(path, page);
	browser->show();
}

#include "helpbrowser.moc"