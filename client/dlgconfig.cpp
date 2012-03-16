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


#include "dlgconfig.h"

DlgConfig::DlgConfig(QWidget *parent, Qt::WindowFlags f): 
	QDialog(parent), ui(new Ui::DlgConfig)
{
	ui->setupUi(this);
	
	ui->btnFonts->setText(trUtf8("Шрифты"));
	
	editFontsDialog = new DlgEditFonts(this);
	
	connect(ui->btnOk, SIGNAL(clicked(bool)), SLOT(accept()));
	connect(ui->btnCancel, SIGNAL(clicked(bool)), SLOT(reject()));
}

DlgConfig::~DlgConfig()
{
	delete ui;
}

void DlgConfig::setServerParm(const QString &server_name, quint16 server_port)
{
	ui->leServerName->setText(server_name);
	ui->leServerPort->setText(QString().number(server_port));
}

void DlgConfig::setViewPanel(bool view_panel)
{
	ui->chbPanelTools->setChecked(view_panel);
}

void DlgConfig::setCreateReport(bool creport)
{
	ui->chbCreateReport->setChecked(creport);
}

QString DlgConfig::getServerName() const
{
	return ui->leServerName->text();
}

quint16 DlgConfig::getServerPort() const
{
	return ui->leServerPort->text().toUShort();
}

bool DlgConfig::getViewPanel() const
{
	return ui->chbPanelTools->isChecked();
}

bool DlgConfig::getCreateReport() const
{
	return ui->chbCreateReport->isChecked();
}

void DlgConfig::setCreateReportVisible(bool dis)
{
	ui->chbCreateReport->setVisible(dis);
}

void DlgConfig::on_btnFonts_clicked()
{
	editFontsDialog->setFonts(fontTask, fontQuest, fontAnsw);
	if(editFontsDialog->exec() == QDialog::Accepted)
		editFontsDialog->getFonts(fontTask, fontQuest, fontAnsw);
}

void DlgConfig::setFonts(QFont fTask, QFont fQuest, QFont fAnsw)
{
	fontTask = fTask;
	fontQuest = fQuest;
	fontAnsw = fAnsw;
}

void DlgConfig::getFonts(QFont &fTask, QFont &fQuest, QFont &fAnsw)
{
	fTask = fontTask;
	fQuest = fontQuest;
	fAnsw = fontAnsw;
}

#include "dlgconfig.moc"