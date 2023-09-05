/********************************************************************************
** Form generated from reading UI file 'drawwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWWIDGET_H
#define UI_DRAWWIDGET_H

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

class Ui_drawWidget
{
public:
    gCodeEditWidget *gCodeTextEdit;
    viewWidget *vWidget;
    QGroupBox *groupBox_5;
    QDoubleSpinBox *zPosSpinBox;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *penSizeSpinBox;
    QPushButton *reParseButton;
    QLabel *label_3;
    QDoubleSpinBox *forceSpinBox;
    QDoubleSpinBox *moveSpinBox;
    QLabel *label_4;
    QPushButton *openFileButton;
    QPushButton *runButton;
    QPushButton *stopButton;

    void setupUi(QWidget *drawWidget)
    {
        if (drawWidget->objectName().isEmpty())
            drawWidget->setObjectName(QString::fromUtf8("drawWidget"));
        drawWidget->resize(1191, 471);
        gCodeTextEdit = new gCodeEditWidget(drawWidget);
        gCodeTextEdit->setObjectName(QString::fromUtf8("gCodeTextEdit"));
        gCodeTextEdit->setGeometry(QRect(20, 10, 231, 371));
        vWidget = new viewWidget(drawWidget);
        vWidget->setObjectName(QString::fromUtf8("vWidget"));
        vWidget->setGeometry(QRect(270, 10, 901, 371));
        groupBox_5 = new QGroupBox(drawWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(170, 390, 811, 71));
        zPosSpinBox = new QDoubleSpinBox(groupBox_5);
        zPosSpinBox->setObjectName(QString::fromUtf8("zPosSpinBox"));
        zPosSpinBox->setGeometry(QRect(100, 30, 61, 26));
        zPosSpinBox->setMaximum(10.000000000000000);
        zPosSpinBox->setValue(2.000000000000000);
        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 35, 121, 17));
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 35, 101, 17));
        penSizeSpinBox = new QDoubleSpinBox(groupBox_5);
        penSizeSpinBox->setObjectName(QString::fromUtf8("penSizeSpinBox"));
        penSizeSpinBox->setGeometry(QRect(240, 30, 61, 26));
        penSizeSpinBox->setValue(1.000000000000000);
        reParseButton = new QPushButton(groupBox_5);
        reParseButton->setObjectName(QString::fromUtf8("reParseButton"));
        reParseButton->setGeometry(QRect(700, 30, 101, 21));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 35, 101, 17));
        forceSpinBox = new QDoubleSpinBox(groupBox_5);
        forceSpinBox->setObjectName(QString::fromUtf8("forceSpinBox"));
        forceSpinBox->setGeometry(QRect(410, 30, 61, 26));
        forceSpinBox->setValue(20.000000000000000);
        moveSpinBox = new QDoubleSpinBox(groupBox_5);
        moveSpinBox->setObjectName(QString::fromUtf8("moveSpinBox"));
        moveSpinBox->setGeometry(QRect(610, 30, 61, 26));
        moveSpinBox->setValue(40.000000000000000);
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 35, 131, 17));
        QFont font;
        font.setFamilies({QString::fromUtf8("Serif")});
        label_4->setFont(font);
        openFileButton = new QPushButton(drawWidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));
        openFileButton->setGeometry(QRect(20, 400, 111, 25));
        runButton = new QPushButton(drawWidget);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setGeometry(QRect(990, 395, 81, 65));
        stopButton = new QPushButton(drawWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1090, 395, 81, 65));

        retranslateUi(drawWidget);

        QMetaObject::connectSlotsByName(drawWidget);
    } // setupUi

    void retranslateUi(QWidget *drawWidget)
    {
        drawWidget->setWindowTitle(QCoreApplication::translate("drawWidget", "Form", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("drawWidget", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("drawWidget", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\320\276 Z", nullptr));
        label_2->setText(QCoreApplication::translate("drawWidget", "\320\250\320\270\321\200\320\270\320\275\320\260 \320\277\320\265\321\200\320\260", nullptr));
        reParseButton->setText(QCoreApplication::translate("drawWidget", "\320\237\320\265\321\200\320\265\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("drawWidget", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\276\320\264\320\260\321\207\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("drawWidget", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        openFileButton->setText(QCoreApplication::translate("drawWidget", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        runButton->setText(QCoreApplication::translate("drawWidget", "\320\237\321\203\321\201\320\272", nullptr));
        stopButton->setText(QCoreApplication::translate("drawWidget", "\320\241\321\202\320\276\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class drawWidget: public Ui_drawWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWWIDGET_H
