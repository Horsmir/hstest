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


#ifndef DLGEDITFONTS_H
#define DLGEDITFONTS_H

#include <QtGui/QDialog>
#include <QtGui/QVBoxLayout>
#include <QtGui/QFormLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFontDialog>

class DlgEditFonts : public QDialog
{
	Q_OBJECT
	
public:
	explicit DlgEditFonts(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~DlgEditFonts();
	
	void setFonts(QFont fTask, QFont fQuest, QFont fAnsw);
	void getFonts(QFont &fTask, QFont &fQuest, QFont &fAnsw);
	
private slots:
	void on_btnTask_clicked();
	void on_btnQuest_clicked();
	void on_btnAnsw_clicked();
	
private:
	QVBoxLayout *verticalLayout;
	QFormLayout *formLayout;
	QLabel *label;
	QPushButton *btnTask;
	QLabel *label_2;
	QPushButton *btnQuest;
	QLabel *label_3;
	QPushButton *btnAnsw;
	QDialogButtonBox *buttonBox;
	
	QFont fTask;
	QFont fQuest;
	QFont fAnsw;
};

#endif // DLGEDITFONTS_H
