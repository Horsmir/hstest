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


#ifndef DLGSELECT_H
#define DLGSELECT_H

#include <QtGui/QDialog>
#include "ui_select.h"

namespace Ui
{
	class SelectDialog;
}

class DlgSelect : public QDialog
{
	Q_OBJECT
	
public:
	explicit DlgSelect(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~DlgSelect();
	
	void setGroups(QStringList groups);
	
	QDate getDateFrom() const;
	QDate getDateTo() const;
	QString getGroupName() const;
	QString getStudentName() const;
	void getCheckeds(bool &chDate, bool &chGroup, bool &chName);
	
private slots:
	void on_chbDate_stateChanged(int on);
	void on_chbGroups_stateChanged(int on);
	void on_chbName_stateChanged(int on);	
	
private:
	Ui::SelectDialog *ui;
};

#endif // DLGSELECT_H
