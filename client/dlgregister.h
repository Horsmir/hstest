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


#ifndef DLGREGISTER_H
#define DLGREGISTER_H

#include <QtGui/QDialog>
#include "ui_dlgregister.h"

namespace Ui
{
	class DlgRegister;
}

class DlgRegister : public QDialog
{
	Q_OBJECT
	
public:
	explicit DlgRegister(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~DlgRegister();
	
	void setGroups(QStringList groups);
	
	QString getStudentName() const;
	QString getGroupName() const;
	int getMode() const;
	
private slots:
	void on_cbMode_currentIndexChanged(int index);
	void on_leFio_textChanged();
	
private:
	Ui::DlgRegister *ui;
};

#endif // DLGREGISTER_H
