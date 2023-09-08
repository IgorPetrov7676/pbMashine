/********************************************************************************
** Form generated from reading UI file 'serialportsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTSDIALOG_H
#define UI_SERIALPORTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_serialPortsDialog
{
public:
    QGroupBox *groupBox;
    QComboBox *flowControl;
    QLabel *label_5;
    QComboBox *stopBits_1;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *parity;
    QComboBox *baudRate;
    QComboBox *dataBits;
    QLabel *label_2;
    QLabel *label_7;
    QComboBox *portName;
    QPushButton *okButton;
    QPushButton *canselButton;

    void setupUi(QDialog *serialPortsDialog)
    {
        if (serialPortsDialog->objectName().isEmpty())
            serialPortsDialog->setObjectName(QString::fromUtf8("serialPortsDialog"));
        serialPortsDialog->resize(273, 254);
        groupBox = new QGroupBox(serialPortsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 251, 211));
        flowControl = new QComboBox(groupBox);
        flowControl->setObjectName(QString::fromUtf8("flowControl"));
        flowControl->setGeometry(QRect(140, 170, 101, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 170, 131, 16));
        stopBits_1 = new QComboBox(groupBox);
        stopBits_1->setObjectName(QString::fromUtf8("stopBits_1"));
        stopBits_1->setGeometry(QRect(140, 140, 101, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 61, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 91, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 61, 16));
        parity = new QComboBox(groupBox);
        parity->setObjectName(QString::fromUtf8("parity"));
        parity->setGeometry(QRect(140, 110, 101, 22));
        baudRate = new QComboBox(groupBox);
        baudRate->setObjectName(QString::fromUtf8("baudRate"));
        baudRate->setGeometry(QRect(140, 50, 101, 22));
        dataBits = new QComboBox(groupBox);
        dataBits->setObjectName(QString::fromUtf8("dataBits"));
        dataBits->setGeometry(QRect(140, 80, 101, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 71, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 71, 16));
        portName = new QComboBox(groupBox);
        portName->setObjectName(QString::fromUtf8("portName"));
        portName->setGeometry(QRect(140, 20, 101, 22));
        okButton = new QPushButton(serialPortsDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(190, 220, 75, 23));
        canselButton = new QPushButton(serialPortsDialog);
        canselButton->setObjectName(QString::fromUtf8("canselButton"));
        canselButton->setGeometry(QRect(10, 220, 75, 23));

        retranslateUi(serialPortsDialog);

        QMetaObject::connectSlotsByName(serialPortsDialog);
    } // setupUi

    void retranslateUi(QDialog *serialPortsDialog)
    {
        serialPortsDialog->setWindowTitle(QCoreApplication::translate("serialPortsDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("serialPortsDialog", "\320\237\320\276\321\200\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("serialPortsDialog", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\321\202\320\276\320\272\320\276\320\274", nullptr));
        label->setText(QCoreApplication::translate("serialPortsDialog", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("serialPortsDialog", "\320\241\321\202\320\276\320\277\320\276\320\262\321\213\320\265 \320\261\320\270\321\202\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("serialPortsDialog", "\320\247\320\265\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("serialPortsDialog", "\320\221\320\270\321\202\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_7->setText(QCoreApplication::translate("serialPortsDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        okButton->setText(QCoreApplication::translate("serialPortsDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        canselButton->setText(QCoreApplication::translate("serialPortsDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serialPortsDialog: public Ui_serialPortsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTSDIALOG_H
