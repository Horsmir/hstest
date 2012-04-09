#ifndef hstestcfg_H
#define hstestcfg_H

#include <QtCore/QCoreApplication>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QTreeWidget>
#include <QtGui/QPushButton>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QCloseEvent>
#include <QtGui/QInputDialog>
#include <QtGui/QMessageBox>
#include "testmanager.h"
#include "dlgaddtest.h"
#include "dlgdeletetest.h"
#include "dlgedittest.h"
#include "dlgeditgroups.h"
#include "dlgeditmarks.h"
#include "dlgaddbintest.h"

class hstestcfg : public QDialog
{
	Q_OBJECT
public:
	hstestcfg();
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
	QHBoxLayout *horizontalLayout;
	QPlainTextEdit *teTests;
	QVBoxLayout *verticalLayout;
	QPushButton *btnAddCat;
	QPushButton *btnAddTest;
	QPushButton *btnAddBinTest;
	QPushButton *btnDelCat;
	QPushButton *btnDelTest;
	QPushButton *btnEditTest;
	QPushButton *btnEditGroups;
	QPushButton *btnEditMarks;
	QPushButton *btnClose;
	QSpacerItem *verticalSpacer;

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
