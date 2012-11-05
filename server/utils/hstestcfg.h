#ifndef hstestcfg_H
#define hstestcfg_H


#include <QtGui/QDialog>
#include "testmanager.h"
#include "dlgaddtest.h"
#include "dlgdeletetest.h"
#include "dlgedittest.h"
#include "dlgeditgroups.h"
#include "dlgeditmarks.h"
#include "dlgaddbintest.h"
#include "ui_main_dialog.h"

namespace Ui
{
	class MainDialog;
}

class hstestcfg : public QDialog
{
	Q_OBJECT
public:
	explicit hstestcfg(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~hstestcfg();

	void createTree();
	void closeEvent(QCloseEvent *event);

private slots:
	void on_btnAddCat_clicked();
	void on_btnAddTest_clicked();
	void on_btnAddBinTest_clicked();
	void on_btnDelCat_clicked();
	void on_btnDelTest_clicked();
	void on_btnEditTest_clicked();
	void on_btnEditGroups_clicked();
	void on_btnEditMarks_clicked();
	void on_btnClose_clicked();

private:
	Ui::MainDialog *ui;

	TestManager *testManager;
	DlgAddTest *addTestDialog;
	DlgDeleteTest *delTestDialog;
	DlgEditTest *editTestDialog;
	DlgEditGroups *editGroupsDialog;
	DlgEditMarks *editMarksDialog;
	DlgAddBinTest *addBintestDialog;
};

#endif // hstestcfg_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
