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
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QDialogButtonBox>


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
	QVBoxLayout *verticalLayout;
	QLabel *label_6;
	QHBoxLayout *horizontalLayout;
	QLabel *label;
	QSpacerItem *horizontalSpacer;
	QLabel *label_4;
	QDoubleSpinBox *dsbPer2;
	QHBoxLayout *horizontalLayout_2;
	QLabel *label_3;
	QLabel *labelPer2;
	QSpacerItem *horizontalSpacer_2;
	QLabel *label_2;
	QDoubleSpinBox *dsbPer3;
	QHBoxLayout *horizontalLayout_3;
	QLabel *label_5;
	QLabel *labelPer3;
	QSpacerItem *horizontalSpacer_3;
	QLabel *label_8;
	QDoubleSpinBox *dsbPer4;
	QHBoxLayout *horizontalLayout_4;
	QLabel *label_9;
	QLabel *labelPer4;
	QLabel *label_11;
	QSpacerItem *horizontalSpacer_4;
	QDialogButtonBox *buttonBox;
};

#endif // DLGEDITMARKS_H
