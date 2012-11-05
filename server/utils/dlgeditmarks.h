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


#ifndef DLGEDITMARKS_H
#define DLGEDITMARKS_H

#include <QtGui/QDialog>
#include "ui_dlgeditmarks.h"

namespace Ui
{
	class DlgEditMarks;
}

class DlgEditMarks : public QDialog
{
	Q_OBJECT
	
public:
	explicit DlgEditMarks(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~DlgEditMarks();
	
	void setPercents(float per2, float per3, float per4);
	
	void getPercents(float &per2, float &per3, float &per4);
	
private slots:
	void on_dsbPer2_changed(const QString &text);
	void on_dsbPer3_changed(const QString &text);
	void on_dsbPer4_changed(const QString &text);
	
private:
	Ui::DlgEditMarks *ui;
};

#endif // DLGEDITMARKS_H
