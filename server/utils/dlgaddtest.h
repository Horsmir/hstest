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


#ifndef DLGADDTEST_H
#define DLGADDTEST_H

#include <QtGui/QDialog>
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFileDialog>


class DlgAddTest : public QDialog
{
	Q_OBJECT
	
public:
    explicit DlgAddTest ( QWidget* parent = 0, Qt::WindowFlags f = 0 );
	
	void setCats(const QStringList &cats);
	
	QString getTestTextFileName() const;
	quint32 getNumVis() const;
	bool getVis() const;
	QString getCat() const;
	
private slots:
	void on_toolBtnFileOpen_clicked();
	
private:
	QVBoxLayout *verticalLayout;
	QHBoxLayout *horizontalLayout;
	QLabel *label;
	QLineEdit *leTestFileName;
	QToolButton *toolBtnFileOpen;
	QHBoxLayout *horizontalLayout_2;
	QLabel *label_2;
	QLineEdit *leNumVis;
	QSpacerItem *verticalSpacer;
	QHBoxLayout *horizontalLayout_3;
	QSpacerItem *horizontalSpacer;
	QPushButton *btnAdd;
	QPushButton *btnCancel;
	QSpacerItem *horizontalSpacer_2;
	QCheckBox *chbVis;
	QLabel *label_3;
	QComboBox *cbCats;
	QHBoxLayout *horizontalLayout_4;
};

#endif // DLGADDTEST_H
