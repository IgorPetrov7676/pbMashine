/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <widgets/directmanagewidget.h>
#include <widgets/drawwidget.h>
#include "widgets/consoletextwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *conntcnAction;
    QAction *openAction;
    QWidget *centralWidget;
    consoleTextWidget *consoleWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    directManageWidget *DMWidget;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QDoubleSpinBox *penDSpinBox;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *ZSpinBox;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *FSpinBox;
    QGroupBox *groupBox_4;
    QDoubleSpinBox *FMSpinBox;
    drawWidget *dWidget;
    QWidget *tab_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1207, 716);
        QFont font;
        MainWindow->setFont(font);
        conntcnAction = new QAction(MainWindow);
        conntcnAction->setObjectName(QString::fromUtf8("conntcnAction"));
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        consoleWidget = new consoleTextWidget(centralWidget);
        consoleWidget->setObjectName(QString::fromUtf8("consoleWidget"));
        consoleWidget->setGeometry(QRect(0, 520, 1191, 131));
        consoleWidget->setReadOnly(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 1191, 501));
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        DMWidget = new directManageWidget(tab);
        DMWidget->setObjectName(QString::fromUtf8("DMWidget"));
        DMWidget->setGeometry(QRect(0, 0, 1131, 421));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(260, 520, 111, 51));
        penDSpinBox = new QDoubleSpinBox(groupBox);
        penDSpinBox->setObjectName(QString::fromUtf8("penDSpinBox"));
        penDSpinBox->setGeometry(QRect(10, 20, 91, 22));
        penDSpinBox->setValue(0.000000000000000);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(380, 520, 111, 51));
        ZSpinBox = new QDoubleSpinBox(groupBox_2);
        ZSpinBox->setObjectName(QString::fromUtf8("ZSpinBox"));
        ZSpinBox->setGeometry(QRect(10, 20, 91, 22));
        ZSpinBox->setMinimum(-99.000000000000000);
        ZSpinBox->setValue(0.000000000000000);
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(500, 520, 120, 51));
        FSpinBox = new QDoubleSpinBox(groupBox_3);
        FSpinBox->setObjectName(QString::fromUtf8("FSpinBox"));
        FSpinBox->setGeometry(QRect(10, 20, 91, 22));
        FSpinBox->setValue(0.000000000000000);
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(630, 520, 141, 51));
        FMSpinBox = new QDoubleSpinBox(groupBox_4);
        FMSpinBox->setObjectName(QString::fromUtf8("FMSpinBox"));
        FMSpinBox->setGeometry(QRect(20, 20, 91, 22));
        FMSpinBox->setValue(0.000000000000000);
        dWidget = new drawWidget(tab_2);
        dWidget->setObjectName(QString::fromUtf8("dWidget"));
        dWidget->setGeometry(QRect(0, 0, 1191, 471));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1207, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(conntcnAction);
        menu_2->addAction(openAction);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        conntcnAction->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        openAction->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\265 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\270\320\260\320\274\320\265\321\202\321\200 \320\277\320\265\321\200\320\260", nullptr));
#if QT_CONFIG(tooltip)
        penDSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\321\213\321\201\320\276\321\202\320\260 \320\277\320\276\320\264\321\212\320\265\320\274\320\260 \320\277\320\276 \320\276\321\201\320\270 Z.</p><p>\320\236\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202, \320\275\320\260 \321\201\320\272\320\276\320\273\321\214\320\272\320\276 \320\277\320\276\320\264\320\275\320\270\320\274\320\265\321\202\321\201\321\217 </p><p>\320\277\320\265\321\200\320\276 \320\277\321\200\320\270 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\265 \320\272 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\271 </p><p>\320\273\320\270\320\275\320\270\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Z \320\277\320\276\320\264\321\212\320\265\320\274\320\260 \320\277\320\265\321\200\320\260", nullptr));
#if QT_CONFIG(tooltip)
        ZSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\321\213\321\201\320\276\321\202\320\260 \320\277\320\276\320\264\321\212\320\265\320\274\320\260 \320\277\320\276 \320\276\321\201\320\270 Z.</p><p>\320\236\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202, \320\275\320\260 \321\201\320\272\320\276\320\273\321\214\320\272\320\276 \320\277\320\276\320\264\320\275\320\270\320\274\320\265\321\202\321\201\321\217 </p><p>\320\277\320\265\321\200\320\276 \320\277\321\200\320\270 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\265 \320\272 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\271 </p><p>\320\273\320\270\320\275\320\270\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\200\320\260\320\261\320\276\321\207\320\260\321\217", nullptr));
#if QT_CONFIG(tooltip)
        FSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\276\320\264\320\260\321\207\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
#if QT_CONFIG(tooltip)
        FMSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\276\320\264\320\260\321\207\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\241\320\262\320\265\321\200\320\273\320\265\320\275\320\270\320\265", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\262\321\217\320\267\321\214", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
