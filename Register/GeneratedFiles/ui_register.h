/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterClass
{
public:
    QWidget *centralWidget;
    QPushButton *clickedPushButton;
    QLabel *label;
    QPlainTextEdit *outputPlainTextEdit;
    QPushButton *clearPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RegisterClass)
    {
        if (RegisterClass->objectName().isEmpty())
            RegisterClass->setObjectName(QStringLiteral("RegisterClass"));
        RegisterClass->resize(320, 240);
        RegisterClass->setMinimumSize(QSize(320, 240));
        RegisterClass->setMaximumSize(QSize(320, 240));
        centralWidget = new QWidget(RegisterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        clickedPushButton = new QPushButton(centralWidget);
        clickedPushButton->setObjectName(QStringLiteral("clickedPushButton"));
        clickedPushButton->setGeometry(QRect(200, 30, 41, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 54, 20));
        outputPlainTextEdit = new QPlainTextEdit(centralWidget);
        outputPlainTextEdit->setObjectName(QStringLiteral("outputPlainTextEdit"));
        outputPlainTextEdit->setGeometry(QRect(20, 50, 281, 131));
        clearPushButton = new QPushButton(centralWidget);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));
        clearPushButton->setGeometry(QRect(250, 30, 41, 20));
        RegisterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RegisterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 320, 23));
        RegisterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RegisterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RegisterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RegisterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RegisterClass->setStatusBar(statusBar);

        retranslateUi(RegisterClass);

        QMetaObject::connectSlotsByName(RegisterClass);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterClass)
    {
        RegisterClass->setWindowTitle(QApplication::translate("RegisterClass", "Register", 0));
        clickedPushButton->setText(QApplication::translate("RegisterClass", "\345\274\200\345\247\213", 0));
        label->setText(QApplication::translate("RegisterClass", "\345\272\217\345\210\227\345\217\267", 0));
        clearPushButton->setText(QApplication::translate("RegisterClass", "\346\270\205\351\231\244", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterClass: public Ui_RegisterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
