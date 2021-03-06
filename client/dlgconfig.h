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


#ifndef DLGCONFIG_H
#define DLGCONFIG_H

#include <QDialog>
#include "ui_dlgconfig.h"
#include "dlgeditfonts.h"

namespace Ui {
	class DlgConfig;
}

class DlgConfig : public QDialog
{
	Q_OBJECT
public:
    explicit DlgConfig(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~DlgConfig();
	
	void setServerParm(const QString &server_name, quint16 server_port);
	void setViewPanel(bool view_panel);
	void setCreateReport(bool creport);
	void setCreateReportVisible(bool dis);
	void setFonts(QFont fTask, QFont fQuest, QFont fAnsw);
	
	QString getServerName() const;
	quint16 getServerPort() const;
	bool getViewPanel() const;
	bool getCreateReport() const;
	void getFonts(QFont &fTask, QFont &fQuest, QFont &fAnsw);
	
private slots:
	void on_btnFonts_clicked();

private:
	Ui::DlgConfig *ui;
	DlgEditFonts *editFontsDialog;
	
	QFont fontTask;
	QFont fontQuest;
	QFont fontAnsw;
};

#endif // DLGCONFIG_H
