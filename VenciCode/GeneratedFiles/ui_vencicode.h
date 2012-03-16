/********************************************************************************
** Form generated from reading UI file 'vencicode.ui'
**
** Created: Fri Mar 16 09:18:27 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENCICODE_H
#define UI_VENCICODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VenciCodeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VenciCodeClass)
    {
        if (VenciCodeClass->objectName().isEmpty())
            VenciCodeClass->setObjectName(QString::fromUtf8("VenciCodeClass"));
        VenciCodeClass->resize(600, 400);
        menuBar = new QMenuBar(VenciCodeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        VenciCodeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VenciCodeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VenciCodeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(VenciCodeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        VenciCodeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(VenciCodeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VenciCodeClass->setStatusBar(statusBar);

        retranslateUi(VenciCodeClass);

        QMetaObject::connectSlotsByName(VenciCodeClass);
    } // setupUi

    void retranslateUi(QMainWindow *VenciCodeClass)
    {
        VenciCodeClass->setWindowTitle(QApplication::translate("VenciCodeClass", "VenciCode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VenciCodeClass: public Ui_VenciCodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENCICODE_H
