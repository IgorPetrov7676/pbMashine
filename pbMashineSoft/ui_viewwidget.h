/********************************************************************************
** Form generated from reading UI file 'viewwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWIDGET_H
#define UI_VIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewWidget
{
public:

    void setupUi(QWidget *viewWidget)
    {
        if (viewWidget->objectName().isEmpty())
            viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        viewWidget->resize(400, 300);

        retranslateUi(viewWidget);

        QMetaObject::connectSlotsByName(viewWidget);
    } // setupUi

    void retranslateUi(QWidget *viewWidget)
    {
        viewWidget->setWindowTitle(QCoreApplication::translate("viewWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewWidget: public Ui_viewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWIDGET_H
