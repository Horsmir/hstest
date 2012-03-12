/********************************************************************************
** Form generated from reading UI file 'mainwindowAm2010.ui'
**
** Created: Fri Mar 2 18:52:10 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWAM2010_H
#define MAINWINDOWAM2010_H

#include <QtCore/QVariant>
#include <QDir>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoadTests;
    QAction *actionExit;
    QAction *actionAdvance;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionBack;
    QAction *actionForvard;
    QAction *action_AboutQt;
    QAction *actionShowResult;
    QAction *actionRepit;
    QAction *actionReturn;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageFirst;
    QGridLayout *gridLayout;
    QListWidget *listCatTestView;
    QWidget *pageNodeClose;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelTaskClose;
    QLabel *labelQuestClose;
    QGroupBox *groupBoxClose;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cbAnswer_1;
    QCheckBox *cbAnswer_2;
    QCheckBox *cbAnswer_3;
    QCheckBox *cbAnswer_4;
    QCheckBox *cbAnswer_5;
    QCheckBox *cbAnswer_6;
    QCheckBox *cbAnswer_7;
    QCheckBox *cbAnswer_8;
    QSpacerItem *verticalSpacer;
    QWidget *pageNodeOpen;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelTaskOpen;
    QLabel *labelQuestOpen;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelAnswer;
    QLineEdit *leAnswer;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageNodeConformity;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelTaskConformity;
    QSplitter *splitter;
    QTextEdit *teQuestions;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout;
    QPushButton *btnConfAnswer_1;
    QLabel *labelConfAnswer_1;
    QFormLayout *formLayout_2;
    QPushButton *btnConfAnswer_2;
    QLabel *labelConfAnswer_2;
    QFormLayout *formLayout_3;
    QPushButton *btnConfAnswer_3;
    QLabel *labelConfAnswer_3;
    QFormLayout *formLayout_4;
    QPushButton *btnConfAnswer_4;
    QLabel *labelConfAnswer_4;
    QFormLayout *formLayout_5;
    QPushButton *btnConfAnswer_5;
    QLabel *labelConfAnswer_5;
    QSpacerItem *verticalSpacer_3;
    QWidget *pageNodeRegulating;
    QVBoxLayout *verticalLayout_7;
    QLabel *labelTaskRegulating;
    QFormLayout *formLayout_6;
    QPushButton *btnRegAnswer_1;
    QLabel *labelRegAnswer_1;
    QPushButton *btnRegAnswer_7;
    QLabel *labelRegAnswer_7;
    QPushButton *btnRegAnswer_8;
    QLabel *labelRegAnswer_8;
    QPushButton *btnRegAnswer_9;
    QLabel *labelRegAnswer_9;
    QPushButton *btnRegAnswer_10;
    QLabel *labelRegAnswer_10;
    QPushButton *btnRegAnswer_11;
    QLabel *labelRegAnswer_11;
    QPushButton *btnRegAnswer_12;
    QLabel *labelRegAnswer_12;
    QPushButton *btnRegAnswer_13;
    QLabel *labelRegAnswer_13;
    QWidget *pageResult;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelResultTest;
    QLabel *labelResultPrec;
    QLabel *labelResultOcenk;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelResultImg;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBarCurTest;
    QLCDNumber *preResultView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuHsTester;
    QMenu *menu;
    QMenu *menuAdvance;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
	QLabel *labelResultTime;
	QString iconsPath;

    void setupUi(QMainWindow *MainWindow)
    {
        QString appDir = QCoreApplication::applicationDirPath();
	    QDir iconsDir(appDir);
	    iconsDir.cdUp();
		iconsPath = iconsDir.absolutePath() + "/share/hstest/icons/";
	
	if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(801, 725);
        QFont font;
        font.setFamily(QString::fromUtf8("Droid Sans"));
        MainWindow->setFont(font);
		QIcon icon9;
		icon9.addFile(iconsPath + QString::fromUtf8("hstest.svg"), QSize(), QIcon::Normal, QIcon::Off);
		MainWindow->setWindowIcon(icon9);
        actionLoadTests = new QAction(MainWindow);
        actionLoadTests->setObjectName(QString::fromUtf8("actionLoadTests"));
        QIcon icon;
        icon.addFile(iconsPath + QString::fromUtf8("load_tests.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadTests->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(iconsPath + QString::fromUtf8("exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionAdvance = new QAction(MainWindow);
        actionAdvance->setObjectName(QString::fromUtf8("actionAdvance"));
        QIcon icon2;
        icon2.addFile(iconsPath + QString::fromUtf8("tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdvance->setIcon(icon2);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
		QIcon icon10;
		icon10.addFile(iconsPath + QString::fromUtf8("help.png"), QSize(), QIcon::Normal, QIcon::Off);
		actionHelp->setIcon(icon10);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon3;
        icon3.addFile(iconsPath + QString::fromUtf8("about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon3);
        actionBack = new QAction(MainWindow);
        actionBack->setObjectName(QString::fromUtf8("actionBack"));
        QIcon icon4;
        icon4.addFile(iconsPath + QString::fromUtf8("go-previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBack->setIcon(icon4);
        actionForvard = new QAction(MainWindow);
        actionForvard->setObjectName(QString::fromUtf8("actionForvard"));
        QIcon icon5;
        icon5.addFile(iconsPath + QString::fromUtf8("go-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionForvard->setIcon(icon5);
        action_AboutQt = new QAction(MainWindow);
        action_AboutQt->setObjectName(QString::fromUtf8("action_AboutQt"));
        actionShowResult = new QAction(MainWindow);
        actionShowResult->setObjectName(QString::fromUtf8("actionShowResult"));
        QIcon icon6;
        icon6.addFile(iconsPath + QString::fromUtf8("view_result.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowResult->setIcon(icon6);
        actionRepit = new QAction(MainWindow);
        actionRepit->setObjectName(QString::fromUtf8("actionRepit"));
        QIcon icon7;
        icon7.addFile(iconsPath + QString::fromUtf8("repit_test.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRepit->setIcon(icon7);
        actionReturn = new QAction(MainWindow);
        actionReturn->setObjectName(QString::fromUtf8("actionReturn"));
        QIcon icon8;
        icon8.addFile(iconsPath + QString::fromUtf8("new_test.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReturn->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pageFirst = new QWidget();
        pageFirst->setObjectName(QString::fromUtf8("pageFirst"));
        gridLayout = new QGridLayout(pageFirst);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listCatTestView = new QListWidget(pageFirst);
        listCatTestView->setObjectName(QString::fromUtf8("listCatTestView"));
        QFont font1;
        font1.setPointSize(12);
        listCatTestView->setFont(font1);
        listCatTestView->setEditTriggers(QAbstractItemView::SelectedClicked);
        listCatTestView->setIconSize(QSize(128, 128));
        listCatTestView->setResizeMode(QListView::Adjust);
        listCatTestView->setSpacing(5);
        listCatTestView->setViewMode(QListView::ListMode);
        listCatTestView->setSortingEnabled(true);

        gridLayout->addWidget(listCatTestView, 0, 0, 1, 1);

        stackedWidget->addWidget(pageFirst);
        pageNodeClose = new QWidget();
        pageNodeClose->setObjectName(QString::fromUtf8("pageNodeClose"));
        verticalLayout_3 = new QVBoxLayout(pageNodeClose);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelTaskClose = new QLabel(pageNodeClose);
        labelTaskClose->setObjectName(QString::fromUtf8("labelTaskClose"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Droid Serif"));
        font2.setBold(true);
        font2.setWeight(75);
        labelTaskClose->setFont(font2);

        verticalLayout_3->addWidget(labelTaskClose);

        labelQuestClose = new QLabel(pageNodeClose);
        labelQuestClose->setObjectName(QString::fromUtf8("labelQuestClose"));
        labelQuestClose->setFont(font2);

        verticalLayout_3->addWidget(labelQuestClose);

        groupBoxClose = new QGroupBox(pageNodeClose);
        groupBoxClose->setObjectName(QString::fromUtf8("groupBoxClose"));
        verticalLayout_2 = new QVBoxLayout(groupBoxClose);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cbAnswer_1 = new QCheckBox(groupBoxClose);
        cbAnswer_1->setObjectName(QString::fromUtf8("cbAnswer_1"));

        verticalLayout_2->addWidget(cbAnswer_1);

        cbAnswer_2 = new QCheckBox(groupBoxClose);
        cbAnswer_2->setObjectName(QString::fromUtf8("cbAnswer_2"));

        verticalLayout_2->addWidget(cbAnswer_2);

        cbAnswer_3 = new QCheckBox(groupBoxClose);
        cbAnswer_3->setObjectName(QString::fromUtf8("cbAnswer_3"));

        verticalLayout_2->addWidget(cbAnswer_3);

        cbAnswer_4 = new QCheckBox(groupBoxClose);
        cbAnswer_4->setObjectName(QString::fromUtf8("cbAnswer_4"));

        verticalLayout_2->addWidget(cbAnswer_4);

        cbAnswer_5 = new QCheckBox(groupBoxClose);
        cbAnswer_5->setObjectName(QString::fromUtf8("cbAnswer_5"));

        verticalLayout_2->addWidget(cbAnswer_5);

        cbAnswer_6 = new QCheckBox(groupBoxClose);
        cbAnswer_6->setObjectName(QString::fromUtf8("cbAnswer_6"));

        verticalLayout_2->addWidget(cbAnswer_6);

        cbAnswer_7 = new QCheckBox(groupBoxClose);
        cbAnswer_7->setObjectName(QString::fromUtf8("cbAnswer_7"));

        verticalLayout_2->addWidget(cbAnswer_7);

        cbAnswer_8 = new QCheckBox(groupBoxClose);
        cbAnswer_8->setObjectName(QString::fromUtf8("cbAnswer_8"));

        verticalLayout_2->addWidget(cbAnswer_8);


        verticalLayout_3->addWidget(groupBoxClose);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        stackedWidget->addWidget(pageNodeClose);
        pageNodeOpen = new QWidget();
        pageNodeOpen->setObjectName(QString::fromUtf8("pageNodeOpen"));
        verticalLayout_4 = new QVBoxLayout(pageNodeOpen);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelTaskOpen = new QLabel(pageNodeOpen);
        labelTaskOpen->setObjectName(QString::fromUtf8("labelTaskOpen"));
        labelTaskOpen->setFont(font2);

        verticalLayout_4->addWidget(labelTaskOpen);

        labelQuestOpen = new QLabel(pageNodeOpen);
        labelQuestOpen->setObjectName(QString::fromUtf8("labelQuestOpen"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Droid Serif"));
        labelQuestOpen->setFont(font3);

        verticalLayout_4->addWidget(labelQuestOpen);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelAnswer = new QLabel(pageNodeOpen);
        labelAnswer->setObjectName(QString::fromUtf8("labelAnswer"));

        horizontalLayout_3->addWidget(labelAnswer);

        leAnswer = new QLineEdit(pageNodeOpen);
        leAnswer->setObjectName(QString::fromUtf8("leAnswer"));

        horizontalLayout_3->addWidget(leAnswer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        stackedWidget->addWidget(pageNodeOpen);
        pageNodeConformity = new QWidget();
        pageNodeConformity->setObjectName(QString::fromUtf8("pageNodeConformity"));
        verticalLayout_6 = new QVBoxLayout(pageNodeConformity);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        labelTaskConformity = new QLabel(pageNodeConformity);
        labelTaskConformity->setObjectName(QString::fromUtf8("labelTaskConformity"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTaskConformity->sizePolicy().hasHeightForWidth());
        labelTaskConformity->setSizePolicy(sizePolicy);
        labelTaskConformity->setFont(font2);

        verticalLayout_6->addWidget(labelTaskConformity);

        splitter = new QSplitter(pageNodeConformity);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        teQuestions = new QTextEdit(splitter);
        teQuestions->setObjectName(QString::fromUtf8("teQuestions"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Droid Serif"));
        font4.setPointSize(12);
        teQuestions->setFont(font4);
        teQuestions->setReadOnly(true);
        teQuestions->setOverwriteMode(false);
        splitter->addWidget(teQuestions);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnConfAnswer_1 = new QPushButton(layoutWidget);
        btnConfAnswer_1->setObjectName(QString::fromUtf8("btnConfAnswer_1"));
        btnConfAnswer_1->setCheckable(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, btnConfAnswer_1);

        labelConfAnswer_1 = new QLabel(layoutWidget);
        labelConfAnswer_1->setObjectName(QString::fromUtf8("labelConfAnswer_1"));
        labelConfAnswer_1->setFont(font3);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelConfAnswer_1);


        verticalLayout_5->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnConfAnswer_2 = new QPushButton(layoutWidget);
        btnConfAnswer_2->setObjectName(QString::fromUtf8("btnConfAnswer_2"));
        btnConfAnswer_2->setCheckable(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btnConfAnswer_2);

        labelConfAnswer_2 = new QLabel(layoutWidget);
        labelConfAnswer_2->setObjectName(QString::fromUtf8("labelConfAnswer_2"));
        labelConfAnswer_2->setFont(font3);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, labelConfAnswer_2);


        verticalLayout_5->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnConfAnswer_3 = new QPushButton(layoutWidget);
        btnConfAnswer_3->setObjectName(QString::fromUtf8("btnConfAnswer_3"));
        btnConfAnswer_3->setCheckable(true);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, btnConfAnswer_3);

        labelConfAnswer_3 = new QLabel(layoutWidget);
        labelConfAnswer_3->setObjectName(QString::fromUtf8("labelConfAnswer_3"));
        labelConfAnswer_3->setFont(font3);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, labelConfAnswer_3);


        verticalLayout_5->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnConfAnswer_4 = new QPushButton(layoutWidget);
        btnConfAnswer_4->setObjectName(QString::fromUtf8("btnConfAnswer_4"));
        btnConfAnswer_4->setCheckable(true);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, btnConfAnswer_4);

        labelConfAnswer_4 = new QLabel(layoutWidget);
        labelConfAnswer_4->setObjectName(QString::fromUtf8("labelConfAnswer_4"));
        labelConfAnswer_4->setFont(font3);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, labelConfAnswer_4);


        verticalLayout_5->addLayout(formLayout_4);

        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnConfAnswer_5 = new QPushButton(layoutWidget);
        btnConfAnswer_5->setObjectName(QString::fromUtf8("btnConfAnswer_5"));
        btnConfAnswer_5->setCheckable(true);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, btnConfAnswer_5);

        labelConfAnswer_5 = new QLabel(layoutWidget);
        labelConfAnswer_5->setObjectName(QString::fromUtf8("labelConfAnswer_5"));
        labelConfAnswer_5->setFont(font3);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, labelConfAnswer_5);


        verticalLayout_5->addLayout(formLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        splitter->addWidget(layoutWidget);

        verticalLayout_6->addWidget(splitter);

        stackedWidget->addWidget(pageNodeConformity);
        pageNodeRegulating = new QWidget();
        pageNodeRegulating->setObjectName(QString::fromUtf8("pageNodeRegulating"));
        verticalLayout_7 = new QVBoxLayout(pageNodeRegulating);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        labelTaskRegulating = new QLabel(pageNodeRegulating);
        labelTaskRegulating->setObjectName(QString::fromUtf8("labelTaskRegulating"));
        sizePolicy.setHeightForWidth(labelTaskRegulating->sizePolicy().hasHeightForWidth());
        labelTaskRegulating->setSizePolicy(sizePolicy);
        labelTaskRegulating->setFont(font2);

        verticalLayout_7->addWidget(labelTaskRegulating);

        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnRegAnswer_1 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_1->setObjectName(QString::fromUtf8("btnRegAnswer_1"));
        btnRegAnswer_1->setCheckable(true);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, btnRegAnswer_1);

        labelRegAnswer_1 = new QLabel(pageNodeRegulating);
        labelRegAnswer_1->setObjectName(QString::fromUtf8("labelRegAnswer_1"));
        labelRegAnswer_1->setFont(font3);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, labelRegAnswer_1);

        btnRegAnswer_7 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_7->setObjectName(QString::fromUtf8("btnRegAnswer_7"));
        btnRegAnswer_7->setCheckable(true);

        formLayout_6->setWidget(1, QFormLayout::LabelRole, btnRegAnswer_7);

        labelRegAnswer_7 = new QLabel(pageNodeRegulating);
        labelRegAnswer_7->setObjectName(QString::fromUtf8("labelRegAnswer_7"));
        labelRegAnswer_7->setFont(font3);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, labelRegAnswer_7);

        btnRegAnswer_8 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_8->setObjectName(QString::fromUtf8("btnRegAnswer_8"));
        btnRegAnswer_8->setCheckable(true);

        formLayout_6->setWidget(2, QFormLayout::LabelRole, btnRegAnswer_8);

        labelRegAnswer_8 = new QLabel(pageNodeRegulating);
        labelRegAnswer_8->setObjectName(QString::fromUtf8("labelRegAnswer_8"));
        labelRegAnswer_8->setFont(font3);

        formLayout_6->setWidget(2, QFormLayout::FieldRole, labelRegAnswer_8);

        btnRegAnswer_9 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_9->setObjectName(QString::fromUtf8("btnRegAnswer_9"));
        btnRegAnswer_9->setCheckable(true);

        formLayout_6->setWidget(3, QFormLayout::LabelRole, btnRegAnswer_9);

        labelRegAnswer_9 = new QLabel(pageNodeRegulating);
        labelRegAnswer_9->setObjectName(QString::fromUtf8("labelRegAnswer_9"));
        labelRegAnswer_9->setFont(font3);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, labelRegAnswer_9);

        btnRegAnswer_10 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_10->setObjectName(QString::fromUtf8("btnRegAnswer_10"));
        btnRegAnswer_10->setCheckable(true);

        formLayout_6->setWidget(4, QFormLayout::LabelRole, btnRegAnswer_10);

        labelRegAnswer_10 = new QLabel(pageNodeRegulating);
        labelRegAnswer_10->setObjectName(QString::fromUtf8("labelRegAnswer_10"));
        labelRegAnswer_10->setFont(font3);

        formLayout_6->setWidget(4, QFormLayout::FieldRole, labelRegAnswer_10);

        btnRegAnswer_11 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_11->setObjectName(QString::fromUtf8("btnRegAnswer_11"));
        btnRegAnswer_11->setCheckable(true);

        formLayout_6->setWidget(5, QFormLayout::LabelRole, btnRegAnswer_11);

        labelRegAnswer_11 = new QLabel(pageNodeRegulating);
        labelRegAnswer_11->setObjectName(QString::fromUtf8("labelRegAnswer_11"));
        labelRegAnswer_11->setFont(font3);

        formLayout_6->setWidget(5, QFormLayout::FieldRole, labelRegAnswer_11);

        btnRegAnswer_12 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_12->setObjectName(QString::fromUtf8("btnRegAnswer_12"));
        btnRegAnswer_12->setCheckable(true);

        formLayout_6->setWidget(6, QFormLayout::LabelRole, btnRegAnswer_12);

        labelRegAnswer_12 = new QLabel(pageNodeRegulating);
        labelRegAnswer_12->setObjectName(QString::fromUtf8("labelRegAnswer_12"));
        labelRegAnswer_12->setFont(font3);

        formLayout_6->setWidget(6, QFormLayout::FieldRole, labelRegAnswer_12);

        btnRegAnswer_13 = new QPushButton(pageNodeRegulating);
        btnRegAnswer_13->setObjectName(QString::fromUtf8("btnRegAnswer_13"));
        btnRegAnswer_13->setCheckable(true);

        formLayout_6->setWidget(7, QFormLayout::LabelRole, btnRegAnswer_13);

        labelRegAnswer_13 = new QLabel(pageNodeRegulating);
        labelRegAnswer_13->setObjectName(QString::fromUtf8("labelRegAnswer_13"));
        labelRegAnswer_13->setFont(font3);

        formLayout_6->setWidget(7, QFormLayout::FieldRole, labelRegAnswer_13);


        verticalLayout_7->addLayout(formLayout_6);

        stackedWidget->addWidget(pageNodeRegulating);
        pageResult = new QWidget();
        pageResult->setObjectName(QString::fromUtf8("pageResult"));
        verticalLayout_8 = new QVBoxLayout(pageResult);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        labelResultTest = new QLabel(pageResult);
        labelResultTest->setObjectName(QString::fromUtf8("labelResultTest"));
        sizePolicy.setHeightForWidth(labelResultTest->sizePolicy().hasHeightForWidth());
        labelResultTest->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        labelResultTest->setFont(font5);
        labelResultTest->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelResultTest);

        labelResultPrec = new QLabel(pageResult);
        labelResultPrec->setObjectName(QString::fromUtf8("labelResultPrec"));
        sizePolicy.setHeightForWidth(labelResultPrec->sizePolicy().hasHeightForWidth());
        labelResultPrec->setSizePolicy(sizePolicy);
        labelResultPrec->setFont(font1);
        labelResultPrec->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelResultPrec);
		
		labelResultTime = new QLabel(pageResult);
		sizePolicy.setHeightForWidth(labelResultTime->sizePolicy().hasHeightForWidth());
		labelResultTime->setSizePolicy(sizePolicy);
		labelResultTime->setFont(font1);
		labelResultTime->setAlignment(Qt::AlignCenter);
		verticalLayout_8->addWidget(labelResultTime);

        labelResultOcenk = new QLabel(pageResult);
        labelResultOcenk->setObjectName(QString::fromUtf8("labelResultOcenk"));
        sizePolicy.setHeightForWidth(labelResultOcenk->sizePolicy().hasHeightForWidth());
        labelResultOcenk->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        labelResultOcenk->setFont(font6);
        labelResultOcenk->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelResultOcenk);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        labelResultImg = new QLabel(pageResult);
        labelResultImg->setObjectName(QString::fromUtf8("labelResultImg"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelResultImg->sizePolicy().hasHeightForWidth());
        labelResultImg->setSizePolicy(sizePolicy1);
        labelResultImg->setPixmap(QPixmap(QString::fromUtf8(":/images/2.svg")));
        labelResultImg->setScaledContents(false);
        labelResultImg->setAlignment(Qt::AlignCenter);
        labelResultImg->setWordWrap(false);
        labelResultImg->setOpenExternalLinks(false);

        horizontalLayout_5->addWidget(labelResultImg);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_8->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(pageResult);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBarCurTest = new QProgressBar(centralWidget);
        progressBarCurTest->setObjectName(QString::fromUtf8("progressBarCurTest"));
        progressBarCurTest->setMaximum(100);
        progressBarCurTest->setValue(24);

        horizontalLayout->addWidget(progressBarCurTest);

        preResultView = new QLCDNumber(centralWidget);
        preResultView->setObjectName(QString::fromUtf8("preResultView"));
        preResultView->setNumDigits(1);
        preResultView->setProperty("intValue", QVariant(5));

        horizontalLayout->addWidget(preResultView);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));

        horizontalLayout_2->addWidget(btnNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 801, 20));
        menuBar->setDefaultUp(false);
        menuHsTester = new QMenu(menuBar);
        menuHsTester->setObjectName(QString::fromUtf8("menuHsTester"));
        menu = new QMenu(menuHsTester);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuAdvance = new QMenu(menuBar);
        menuAdvance->setObjectName(QString::fromUtf8("menuAdvance"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHsTester->menuAction());
        menuBar->addAction(menuAdvance->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHsTester->addAction(actionLoadTests);
        menuHsTester->addSeparator();
        menuHsTester->addAction(actionShowResult);
        menuHsTester->addAction(actionRepit);
        menuHsTester->addAction(actionReturn);
        menuHsTester->addSeparator();
        menuHsTester->addAction(menu->menuAction());
        menuHsTester->addSeparator();
        menuHsTester->addAction(actionExit);
        menu->addAction(actionBack);
        menu->addAction(actionForvard);
        menuAdvance->addAction(actionAdvance);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(action_AboutQt);
        mainToolBar->addAction(actionBack);
        mainToolBar->addAction(actionForvard);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoadTests);
        mainToolBar->addAction(actionRepit);
        mainToolBar->addAction(actionReturn);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShowResult);
        mainToolBar->addAction(actionAdvance);
        mainToolBar->addSeparator();
		mainToolBar->addAction(actionHelp);
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hs Test", 0, QApplication::UnicodeUTF8));
        actionLoadTests->setText(QApplication::translate("MainWindow", "&\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\321\213", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "&\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Alt+X", 0, QApplication::UnicodeUTF8));
        actionAdvance->setText(QApplication::translate("MainWindow", "\320\237&\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213...", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "&\320\241\320\277\321\200\320\260\320\262\320\272\320\260...", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "\320\236 \320\277&\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265...", 0, QApplication::UnicodeUTF8));
        actionBack->setText(QApplication::translate("MainWindow", "&\320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
        actionForvard->setText(QApplication::translate("MainWindow", "\320\222\320\277&\320\265\321\200\321\221\320\264", 0, QApplication::UnicodeUTF8));
        action_AboutQt->setText(QApplication::translate("MainWindow", "\320\236 &Qt...", 0, QApplication::UnicodeUTF8));
        actionShowResult->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\276\321\202\320\262\320\265\321\202\321\213...", 0, QApplication::UnicodeUTF8));
        actionRepit->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        actionReturn->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\321\200\321\203\320\263\320\276\320\271", 0, QApplication::UnicodeUTF8));
        labelTaskClose->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        labelQuestClose->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupBoxClose->setTitle(QApplication::translate("MainWindow", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202\321\213 \320\276\321\202\320\262\320\265\321\202\320\260", 0, QApplication::UnicodeUTF8));
        cbAnswer_1->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        cbAnswer_2->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        cbAnswer_3->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        cbAnswer_4->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        cbAnswer_5->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        cbAnswer_6->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        cbAnswer_7->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        cbAnswer_8->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        labelTaskOpen->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        labelQuestOpen->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        labelAnswer->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202: ", 0, QApplication::UnicodeUTF8));
        labelTaskConformity->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        btnConfAnswer_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelConfAnswer_1->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnConfAnswer_2->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelConfAnswer_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnConfAnswer_3->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelConfAnswer_3->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnConfAnswer_4->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelConfAnswer_4->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnConfAnswer_5->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelConfAnswer_5->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        labelTaskRegulating->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_1->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_7->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_7->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_8->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_8->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_9->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_9->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_10->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_10->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_11->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_11->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_12->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_12->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        btnRegAnswer_13->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        labelRegAnswer_13->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", 0, QApplication::UnicodeUTF8));
        labelResultTest->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202", 0, QApplication::UnicodeUTF8));
        labelResultPrec->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\213\321\205 \320\276\321\202\320\262\320\265\321\202\320\276\320\262: 00,00%", 0, QApplication::UnicodeUTF8));
        labelResultOcenk->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\260 \320\276\321\206\320\265\320\275\320\272\320\260:", 0, QApplication::UnicodeUTF8));
        progressBarCurTest->setFormat(QApplication::translate("MainWindow", "%v", 0, QApplication::UnicodeUTF8));
        btnNext->setText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271", 0, QApplication::UnicodeUTF8));
        menuHsTester->setTitle(QApplication::translate("MainWindow", "&\320\242\320\265\321\201\321\202", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        menuAdvance->setTitle(QApplication::translate("MainWindow", "&\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\320\237&\320\276\320\274\320\276\321\211\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWAM2010_H
