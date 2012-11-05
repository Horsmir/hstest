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


#ifndef HELPBROWSER_H
#define HELPBROWSER_H

#include <QtGui/QWidget>
#include "ui_helpform.h"

namespace Ui
{
	class helpForm;
}

class HelpBrowser : public QWidget
{
	Q_OBJECT
public:
	explicit HelpBrowser(QWidget *parent = 0, Qt::WindowFlags f = 0);
	HelpBrowser(const QString &path, const QString &page, QWidget *parent = 0);
	virtual ~HelpBrowser();
	
	static void showPage(const QString &path, const QString &page);
	
private slots:
	void updateWindowTitle();
	
private:
	Ui::helpForm *ui;
};

#endif // HELPBROWSER_H
