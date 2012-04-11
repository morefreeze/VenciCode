/********************************************************************************
** Form generated from reading UI file 'vencicode.ui'
**
** Created: Sun Apr 8 12:26:39 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VenciCodeClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *GameLayout;
    QGroupBox *OpponentArea;
    QGroupBox *OwerArea;
    QVBoxLayout *DeckLayout;
    QGroupBox *DeckArea;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VenciCodeClass)
    {
        if (VenciCodeClass->objectName().isEmpty())
            VenciCodeClass->setObjectName(QString::fromUtf8("VenciCodeClass"));
        VenciCodeClass->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VenciCodeClass->sizePolicy().hasHeightForWidth());
        VenciCodeClass->setSizePolicy(sizePolicy);
        VenciCodeClass->setMouseTracking(false);
        VenciCodeClass->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(VenciCodeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        GameLayout = new QVBoxLayout();
        GameLayout->setSpacing(6);
        GameLayout->setObjectName(QString::fromUtf8("GameLayout"));
        OpponentArea = new QGroupBox(centralWidget);
        OpponentArea->setObjectName(QString::fromUtf8("OpponentArea"));

        GameLayout->addWidget(OpponentArea);

        OwerArea = new QGroupBox(centralWidget);
        OwerArea->setObjectName(QString::fromUtf8("OwerArea"));

        GameLayout->addWidget(OwerArea);


        horizontalLayout->addLayout(GameLayout);

        DeckLayout = new QVBoxLayout();
        DeckLayout->setSpacing(6);
        DeckLayout->setObjectName(QString::fromUtf8("DeckLayout"));
        DeckArea = new QGroupBox(centralWidget);
        DeckArea->setObjectName(QString::fromUtf8("DeckArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DeckArea->sizePolicy().hasHeightForWidth());
        DeckArea->setSizePolicy(sizePolicy1);
        DeckArea->setMinimumSize(QSize(84, 0));
        DeckArea->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(DeckArea);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        DeckLayout->addWidget(DeckArea);


        horizontalLayout->addLayout(DeckLayout);

        VenciCodeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VenciCodeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        VenciCodeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VenciCodeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VenciCodeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VenciCodeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VenciCodeClass->setStatusBar(statusBar);

        retranslateUi(VenciCodeClass);

        QMetaObject::connectSlotsByName(VenciCodeClass);
    } // setupUi

    void retranslateUi(QMainWindow *VenciCodeClass)
    {
        VenciCodeClass->setWindowTitle(QApplication::translate("VenciCodeClass", "VenciCode", 0, QApplication::UnicodeUTF8));
        OpponentArea->setTitle(QApplication::translate("VenciCodeClass", "Opponent", 0, QApplication::UnicodeUTF8));
        OwerArea->setTitle(QApplication::translate("VenciCodeClass", "Ower", 0, QApplication::UnicodeUTF8));
        DeckArea->setTitle(QApplication::translate("VenciCodeClass", "Decks", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VenciCodeClass: public Ui_VenciCodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENCICODE_H
