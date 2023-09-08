/********************************************************************************
** Form generated from reading UI file 'progressdialor.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOR_H
#define UI_PROGRESSDIALOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_progressDialor
{
public:
    QProgressBar *progressBar;
    QPushButton *pushButton;

    void setupUi(QDialog *progressDialor)
    {
        if (progressDialor->objectName().isEmpty())
            progressDialor->setObjectName(QString::fromUtf8("progressDialor"));
        progressDialor->resize(469, 81);
        progressBar = new QProgressBar(progressDialor);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 20, 441, 16));
        progressBar->setValue(24);
        pushButton = new QPushButton(progressDialor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 50, 75, 23));

        retranslateUi(progressDialor);

        QMetaObject::connectSlotsByName(progressDialor);
    } // setupUi

    void retranslateUi(QDialog *progressDialor)
    {
        progressDialor->setWindowTitle(QCoreApplication::translate("progressDialor", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("progressDialor", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class progressDialor: public Ui_progressDialor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOR_H
