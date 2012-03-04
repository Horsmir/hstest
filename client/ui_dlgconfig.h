/********************************************************************************
** Form generated from reading UI file 'dlgconfigh27723.ui'
**
** Created: Tue Feb 28 18:25:31 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLGCONFIGH27723_H
#define DLGCONFIGH27723_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgConfig
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *leServerName;
    QLabel *label_2;
    QLineEdit *leServerPort;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chbPanelTools;
    QCheckBox *chbCreateReport;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgConfig)
    {
        if (DlgConfig->objectName().isEmpty())
            DlgConfig->setObjectName(QString::fromUtf8("DlgConfig"));
        DlgConfig->resize(350, 279);
        verticalLayout_3 = new QVBoxLayout(DlgConfig);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(DlgConfig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        leServerName = new QLineEdit(groupBox);
        leServerName->setObjectName(QString::fromUtf8("leServerName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leServerName);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        leServerPort = new QLineEdit(groupBox);
        leServerPort->setObjectName(QString::fromUtf8("leServerPort"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leServerPort);


        verticalLayout->addLayout(formLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DlgConfig);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chbPanelTools = new QCheckBox(groupBox_2);
        chbPanelTools->setObjectName(QString::fromUtf8("chbPanelTools"));

        verticalLayout_2->addWidget(chbPanelTools);

        chbCreateReport = new QCheckBox(groupBox_2);
        chbCreateReport->setObjectName(QString::fromUtf8("chbCreateReport"));

        verticalLayout_2->addWidget(chbCreateReport);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(DlgConfig);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(DlgConfig);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(DlgConfig);

        QMetaObject::connectSlotsByName(DlgConfig);
    } // setupUi

    void retranslateUi(QDialog *DlgConfig)
    {
        DlgConfig->setWindowTitle(QApplication::translate("DlgConfig", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DlgConfig", "\320\241\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgConfig", "\320\230\320\274\321\217: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DlgConfig", "\320\237\320\276\321\200\321\202: ", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DlgConfig", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        chbPanelTools->setText(QApplication::translate("DlgConfig", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\270\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        chbCreateReport->setText(QApplication::translate("DlgConfig", "\320\227\320\260\320\277\320\270\321\201\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\260", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("DlgConfig", "\320\236\320\232", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("DlgConfig", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgConfig: public Ui_DlgConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLGCONFIGH27723_H
