/********************************************************************************
** Form generated from reading UI file 'drillwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRILLWIDGET_H
#define UI_DRILLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <widgets/gcodeeditwidget.h>
#include <widgets/viewwidget.h>

QT_BEGIN_NAMESPACE

class Ui_drillWidget
{
public:
    QGroupBox *groupBox;
    QDoubleSpinBox *zPosSpinBox;
    QLabel *label;
    QPushButton *reParseButton;
    QDoubleSpinBox *moveSpinBox;
    QLabel *label_4;
    viewWidget *vWidget;
    gCodeEditWidget *gCodeTextEdit;
    QPushButton *openFileButton;
    QPushButton *runButton;
    QPushButton *stopButton;

    void setupUi(QWidget *drillWidget)
    {
        if (drillWidget->objectName().isEmpty())
            drillWidget->setObjectName(QString::fromUtf8("drillWidget"));
        drillWidget->resize(1191, 471);
        groupBox = new QGroupBox(drillWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(160, 390, 521, 71));
        zPosSpinBox = new QDoubleSpinBox(groupBox);
        zPosSpinBox->setObjectName(QString::fromUtf8("zPosSpinBox"));
        zPosSpinBox->setGeometry(QRect(100, 30, 61, 26));
        zPosSpinBox->setMaximum(10.000000000000000);
        zPosSpinBox->setValue(2.000000000000000);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 35, 121, 17));
        reParseButton = new QPushButton(groupBox);
        reParseButton->setObjectName(QString::fromUtf8("reParseButton"));
        reParseButton->setGeometry(QRect(400, 30, 101, 21));
        moveSpinBox = new QDoubleSpinBox(groupBox);
        moveSpinBox->setObjectName(QString::fromUtf8("moveSpinBox"));
        moveSpinBox->setGeometry(QRect(310, 30, 61, 26));
        moveSpinBox->setValue(40.000000000000000);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 35, 131, 17));
        vWidget = new viewWidget(drillWidget);
        vWidget->setObjectName(QString::fromUtf8("vWidget"));
        vWidget->setGeometry(QRect(260, 10, 901, 371));
        gCodeTextEdit = new gCodeEditWidget(drillWidget);
        gCodeTextEdit->setObjectName(QString::fromUtf8("gCodeTextEdit"));
        gCodeTextEdit->setGeometry(QRect(10, 10, 231, 371));
        openFileButton = new QPushButton(drillWidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));
        openFileButton->setGeometry(QRect(10, 400, 111, 25));
        runButton = new QPushButton(drillWidget);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setGeometry(QRect(980, 390, 81, 65));
        stopButton = new QPushButton(drillWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1080, 390, 81, 65));

        retranslateUi(drillWidget);

        QMetaObject::connectSlotsByName(drillWidget);
    } // setupUi

    void retranslateUi(QWidget *drillWidget)
    {
        drillWidget->setWindowTitle(QCoreApplication::translate("drillWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("drillWidget", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("drillWidget", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\320\276 Z", nullptr));
        reParseButton->setText(QCoreApplication::translate("drillWidget", "\320\237\320\265\321\200\320\265\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("drillWidget", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        openFileButton->setText(QCoreApplication::translate("drillWidget", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        runButton->setText(QCoreApplication::translate("drillWidget", "\320\237\321\203\321\201\320\272", nullptr));
        stopButton->setText(QCoreApplication::translate("drillWidget", "\320\241\321\202\320\276\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class drillWidget: public Ui_drillWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRILLWIDGET_H
