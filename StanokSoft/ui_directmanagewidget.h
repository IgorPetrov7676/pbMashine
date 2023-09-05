/********************************************************************************
** Form generated from reading UI file 'directmanagewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRECTMANAGEWIDGET_H
#define UI_DIRECTMANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <widgets/gpushbutton.h>

QT_BEGIN_NAMESPACE

class Ui_directManageWidget
{
public:
    QPushButton *refPosButton;
    QPushButton *disSteppersButton;
    QGroupBox *groupBox;
    QLabel *label_7;
    QLabel *posXLable;
    QLabel *label_8;
    QLabel *posYLable;
    QLabel *posZLable;
    GPushButton *zeroAllButton;
    QLabel *label_9;
    GPushButton *zeroXButton;
    GPushButton *zeroYButton;
    GPushButton *zeroZButton;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QDoubleSpinBox *speedSpinBox;
    QLabel *label_10;
    QLabel *speedLable;
    QGroupBox *groupBox_4;
    QLineEdit *GlineEdit;
    QPushButton *sendGCode;
    GPushButton *Yp10Button;
    GPushButton *Yp1Button;
    GPushButton *Yp01Button;
    GPushButton *Ym01Button;
    GPushButton *Ym10Button;
    GPushButton *Ym1Button;
    GPushButton *Xp01Button;
    GPushButton *Xp1Button;
    GPushButton *Xp10Button;
    GPushButton *Xm1Button;
    GPushButton *Xm10Button;
    GPushButton *Xm01Button;
    GPushButton *Zm1Button;
    GPushButton *Zm10Button;
    GPushButton *Zp10Button;
    GPushButton *Zp01Button;
    GPushButton *Zp1Button;
    GPushButton *Zm01Button;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *swXLable;
    QLabel *swYLable;
    QLabel *swZLable;
    QPushButton *zeroPosButton;
    QPushButton *stopButton;
    QGroupBox *groupBox_5;
    QLabel *endPosYLable;
    QLabel *label_11;
    QLabel *endPosXLable;
    QLabel *label_12;
    QLabel *endPosZLable;
    QLabel *label_13;
    GPushButton *setEndPosButton;
    GPushButton *drawWorkZoneButton;
    GPushButton *resetWorkZoneButton;

    void setupUi(QWidget *directManageWidget)
    {
        if (directManageWidget->objectName().isEmpty())
            directManageWidget->setObjectName(QString::fromUtf8("directManageWidget"));
        directManageWidget->resize(705, 371);
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        directManageWidget->setFont(font);
        refPosButton = new QPushButton(directManageWidget);
        refPosButton->setObjectName(QString::fromUtf8("refPosButton"));
        refPosButton->setGeometry(QRect(10, 130, 91, 23));
        disSteppersButton = new QPushButton(directManageWidget);
        disSteppersButton->setObjectName(QString::fromUtf8("disSteppersButton"));
        disSteppersButton->setGeometry(QRect(10, 100, 91, 23));
        groupBox = new QGroupBox(directManageWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(150, 0, 261, 101));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 21, 16));
        posXLable = new QLabel(groupBox);
        posXLable->setObjectName(QString::fromUtf8("posXLable"));
        posXLable->setGeometry(QRect(40, 20, 31, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 20, 21, 16));
        posYLable = new QLabel(groupBox);
        posYLable->setObjectName(QString::fromUtf8("posYLable"));
        posYLable->setGeometry(QRect(130, 20, 51, 16));
        posZLable = new QLabel(groupBox);
        posZLable->setObjectName(QString::fromUtf8("posZLable"));
        posZLable->setGeometry(QRect(220, 20, 31, 16));
        zeroAllButton = new GPushButton(groupBox);
        zeroAllButton->setObjectName(QString::fromUtf8("zeroAllButton"));
        zeroAllButton->setGeometry(QRect(70, 70, 121, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(190, 20, 21, 16));
        zeroXButton = new GPushButton(groupBox);
        zeroXButton->setObjectName(QString::fromUtf8("zeroXButton"));
        zeroXButton->setGeometry(QRect(10, 40, 61, 21));
        zeroYButton = new GPushButton(groupBox);
        zeroYButton->setObjectName(QString::fromUtf8("zeroYButton"));
        zeroYButton->setGeometry(QRect(100, 40, 61, 21));
        zeroZButton = new GPushButton(groupBox);
        zeroZButton->setObjectName(QString::fromUtf8("zeroZButton"));
        zeroZButton->setGeometry(QRect(180, 40, 61, 21));
        groupBox_2 = new QGroupBox(directManageWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 131, 91));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 50, 41, 16));
        speedSpinBox = new QDoubleSpinBox(groupBox_2);
        speedSpinBox->setObjectName(QString::fromUtf8("speedSpinBox"));
        speedSpinBox->setGeometry(QRect(11, 50, 81, 22));
        speedSpinBox->setMaximum(999.990000000000009);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 30, 21, 16));
        speedLable = new QLabel(groupBox_2);
        speedLable->setObjectName(QString::fromUtf8("speedLable"));
        speedLable->setGeometry(QRect(50, 30, 51, 16));
        groupBox_4 = new QGroupBox(directManageWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 300, 401, 51));
        GlineEdit = new QLineEdit(groupBox_4);
        GlineEdit->setObjectName(QString::fromUtf8("GlineEdit"));
        GlineEdit->setGeometry(QRect(10, 20, 301, 20));
        sendGCode = new QPushButton(groupBox_4);
        sendGCode->setObjectName(QString::fromUtf8("sendGCode"));
        sendGCode->setGeometry(QRect(320, 20, 71, 23));
        Yp10Button = new GPushButton(directManageWidget);
        Yp10Button->setObjectName(QString::fromUtf8("Yp10Button"));
        Yp10Button->setGeometry(QRect(430, 310, 41, 41));
        Yp1Button = new GPushButton(directManageWidget);
        Yp1Button->setObjectName(QString::fromUtf8("Yp1Button"));
        Yp1Button->setGeometry(QRect(430, 260, 41, 41));
        Yp01Button = new GPushButton(directManageWidget);
        Yp01Button->setObjectName(QString::fromUtf8("Yp01Button"));
        Yp01Button->setGeometry(QRect(430, 210, 41, 41));
        Ym01Button = new GPushButton(directManageWidget);
        Ym01Button->setObjectName(QString::fromUtf8("Ym01Button"));
        Ym01Button->setGeometry(QRect(430, 110, 41, 41));
        Ym10Button = new GPushButton(directManageWidget);
        Ym10Button->setObjectName(QString::fromUtf8("Ym10Button"));
        Ym10Button->setGeometry(QRect(430, 10, 41, 41));
        Ym1Button = new GPushButton(directManageWidget);
        Ym1Button->setObjectName(QString::fromUtf8("Ym1Button"));
        Ym1Button->setGeometry(QRect(430, 60, 41, 41));
        Xp01Button = new GPushButton(directManageWidget);
        Xp01Button->setObjectName(QString::fromUtf8("Xp01Button"));
        Xp01Button->setGeometry(QRect(480, 160, 41, 41));
        Xp1Button = new GPushButton(directManageWidget);
        Xp1Button->setObjectName(QString::fromUtf8("Xp1Button"));
        Xp1Button->setGeometry(QRect(530, 160, 41, 41));
        Xp10Button = new GPushButton(directManageWidget);
        Xp10Button->setObjectName(QString::fromUtf8("Xp10Button"));
        Xp10Button->setGeometry(QRect(580, 160, 41, 41));
        Xm1Button = new GPushButton(directManageWidget);
        Xm1Button->setObjectName(QString::fromUtf8("Xm1Button"));
        Xm1Button->setGeometry(QRect(330, 160, 41, 41));
        Xm10Button = new GPushButton(directManageWidget);
        Xm10Button->setObjectName(QString::fromUtf8("Xm10Button"));
        Xm10Button->setGeometry(QRect(280, 160, 41, 41));
        Xm01Button = new GPushButton(directManageWidget);
        Xm01Button->setObjectName(QString::fromUtf8("Xm01Button"));
        Xm01Button->setGeometry(QRect(380, 160, 41, 41));
        Zm1Button = new GPushButton(directManageWidget);
        Zm1Button->setObjectName(QString::fromUtf8("Zm1Button"));
        Zm1Button->setGeometry(QRect(640, 60, 41, 41));
        Zm10Button = new GPushButton(directManageWidget);
        Zm10Button->setObjectName(QString::fromUtf8("Zm10Button"));
        Zm10Button->setGeometry(QRect(640, 10, 41, 41));
        Zp10Button = new GPushButton(directManageWidget);
        Zp10Button->setObjectName(QString::fromUtf8("Zp10Button"));
        Zp10Button->setGeometry(QRect(640, 310, 41, 41));
        Zp01Button = new GPushButton(directManageWidget);
        Zp01Button->setObjectName(QString::fromUtf8("Zp01Button"));
        Zp01Button->setGeometry(QRect(640, 210, 41, 41));
        Zp1Button = new GPushButton(directManageWidget);
        Zp1Button->setObjectName(QString::fromUtf8("Zp1Button"));
        Zp1Button->setGeometry(QRect(640, 260, 41, 41));
        Zm01Button = new GPushButton(directManageWidget);
        Zm01Button->setObjectName(QString::fromUtf8("Zm01Button"));
        Zm01Button->setGeometry(QRect(640, 110, 41, 41));
        groupBox_3 = new QGroupBox(directManageWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(500, 40, 131, 81));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 47, 16));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 47, 16));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 47, 16));
        swXLable = new QLabel(groupBox_3);
        swXLable->setObjectName(QString::fromUtf8("swXLable"));
        swXLable->setGeometry(QRect(60, 20, 61, 16));
        swYLable = new QLabel(groupBox_3);
        swYLable->setObjectName(QString::fromUtf8("swYLable"));
        swYLable->setGeometry(QRect(60, 40, 61, 16));
        swZLable = new QLabel(groupBox_3);
        swZLable->setObjectName(QString::fromUtf8("swZLable"));
        swZLable->setGeometry(QRect(60, 60, 61, 16));
        zeroPosButton = new QPushButton(directManageWidget);
        zeroPosButton->setObjectName(QString::fromUtf8("zeroPosButton"));
        zeroPosButton->setGeometry(QRect(10, 160, 91, 23));
        stopButton = new QPushButton(directManageWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(40, 220, 71, 61));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("1");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("../STOP.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        }
        stopButton->setIcon(icon);
        stopButton->setIconSize(QSize(81, 81));
        groupBox_5 = new QGroupBox(directManageWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(150, 210, 261, 91));
        endPosYLable = new QLabel(groupBox_5);
        endPosYLable->setObjectName(QString::fromUtf8("endPosYLable"));
        endPosYLable->setGeometry(QRect(130, 30, 51, 16));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 30, 21, 16));
        endPosXLable = new QLabel(groupBox_5);
        endPosXLable->setObjectName(QString::fromUtf8("endPosXLable"));
        endPosXLable->setGeometry(QRect(40, 30, 31, 16));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(190, 30, 21, 16));
        endPosZLable = new QLabel(groupBox_5);
        endPosZLable->setObjectName(QString::fromUtf8("endPosZLable"));
        endPosZLable->setGeometry(QRect(220, 30, 31, 16));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 30, 21, 16));
        setEndPosButton = new GPushButton(groupBox_5);
        setEndPosButton->setObjectName(QString::fromUtf8("setEndPosButton"));
        setEndPosButton->setGeometry(QRect(10, 60, 81, 21));
        drawWorkZoneButton = new GPushButton(groupBox_5);
        drawWorkZoneButton->setObjectName(QString::fromUtf8("drawWorkZoneButton"));
        drawWorkZoneButton->setGeometry(QRect(100, 60, 81, 21));
        resetWorkZoneButton = new GPushButton(groupBox_5);
        resetWorkZoneButton->setObjectName(QString::fromUtf8("resetWorkZoneButton"));
        resetWorkZoneButton->setGeometry(QRect(190, 60, 61, 21));

        retranslateUi(directManageWidget);

        QMetaObject::connectSlotsByName(directManageWidget);
    } // setupUi

    void retranslateUi(QWidget *directManageWidget)
    {
        directManageWidget->setWindowTitle(QCoreApplication::translate("directManageWidget", "Form", nullptr));
        refPosButton->setText(QCoreApplication::translate("directManageWidget", "\320\222 \321\200\320\265\321\204\320\265\321\200\320\265\320\275\321\201\320\275\321\203\321\216", nullptr));
        disSteppersButton->setText(QCoreApplication::translate("directManageWidget", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\250\320\224", nullptr));
        groupBox->setTitle(QCoreApplication::translate("directManageWidget", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217", nullptr));
        label_7->setText(QCoreApplication::translate("directManageWidget", "\320\245 = ", nullptr));
        posXLable->setText(QCoreApplication::translate("directManageWidget", "0", nullptr));
        label_8->setText(QCoreApplication::translate("directManageWidget", "Y = ", nullptr));
        posYLable->setText(QCoreApplication::translate("directManageWidget", "0", nullptr));
        posZLable->setText(QCoreApplication::translate("directManageWidget", "0", nullptr));
        zeroAllButton->setText(QCoreApplication::translate("directManageWidget", "\320\236\320\261\320\275\321\203\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        label_9->setText(QCoreApplication::translate("directManageWidget", "Z = ", nullptr));
        zeroXButton->setText(QCoreApplication::translate("directManageWidget", "\320\236\320\261\320\275\321\203\320\273\320\270\321\202\321\214", nullptr));
        zeroYButton->setText(QCoreApplication::translate("directManageWidget", "\320\236\320\261\320\275\321\203\320\273\320\270\321\202\321\214", nullptr));
        zeroZButton->setText(QCoreApplication::translate("directManageWidget", "\320\236\320\261\320\275\321\203\320\273\320\270\321\202\321\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("directManageWidget", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("directManageWidget", "\320\274\320\274/\321\201", nullptr));
        label_10->setText(QCoreApplication::translate("directManageWidget", "F = ", nullptr));
        speedLable->setText(QCoreApplication::translate("directManageWidget", "0", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("directManageWidget", "G \320\232\320\276\320\264", nullptr));
        sendGCode->setText(QCoreApplication::translate("directManageWidget", "\320\236\321\202\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214", nullptr));
        Yp10Button->setText(QCoreApplication::translate("directManageWidget", "Y+10", nullptr));
        Yp1Button->setText(QCoreApplication::translate("directManageWidget", "Y+1", nullptr));
        Yp01Button->setText(QCoreApplication::translate("directManageWidget", "Y+0.1", nullptr));
        Ym01Button->setText(QCoreApplication::translate("directManageWidget", "Y-0.1", nullptr));
        Ym10Button->setText(QCoreApplication::translate("directManageWidget", "Y-10", nullptr));
        Ym1Button->setText(QCoreApplication::translate("directManageWidget", "Y-1", nullptr));
        Xp01Button->setText(QCoreApplication::translate("directManageWidget", "X+0.1", nullptr));
        Xp1Button->setText(QCoreApplication::translate("directManageWidget", "X+1", nullptr));
        Xp10Button->setText(QCoreApplication::translate("directManageWidget", "X+10", nullptr));
        Xm1Button->setText(QCoreApplication::translate("directManageWidget", "X-1", nullptr));
        Xm10Button->setText(QCoreApplication::translate("directManageWidget", "X-10", nullptr));
        Xm01Button->setText(QCoreApplication::translate("directManageWidget", "X-0.1", nullptr));
        Zm1Button->setText(QCoreApplication::translate("directManageWidget", "Z-1", nullptr));
        Zm10Button->setText(QCoreApplication::translate("directManageWidget", "Z-10", nullptr));
        Zp10Button->setText(QCoreApplication::translate("directManageWidget", "Z+10", nullptr));
        Zp01Button->setText(QCoreApplication::translate("directManageWidget", "Z+0.1", nullptr));
        Zp1Button->setText(QCoreApplication::translate("directManageWidget", "Z+1", nullptr));
        Zm01Button->setText(QCoreApplication::translate("directManageWidget", "Z-0.1", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("directManageWidget", "\320\232\320\276\320\275\321\206\320\265\320\262\320\270\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("directManageWidget", "\320\236\321\201\321\214 \320\245 - ", nullptr));
        label_2->setText(QCoreApplication::translate("directManageWidget", "\320\236\321\201\321\214 Y -", nullptr));
        label_3->setText(QCoreApplication::translate("directManageWidget", "\320\236\321\201\321\214 Z -", nullptr));
        swXLable->setText(QCoreApplication::translate("directManageWidget", "\320\240\320\260\320\267\320\276\320\274\320\272\320\275\321\203\321\202", nullptr));
        swYLable->setText(QCoreApplication::translate("directManageWidget", "\320\240\320\260\320\267\320\276\320\274\320\272\320\275\321\203\321\202", nullptr));
        swZLable->setText(QCoreApplication::translate("directManageWidget", "\320\240\320\260\320\267\320\276\320\274\320\272\320\275\321\203\321\202", nullptr));
        zeroPosButton->setText(QCoreApplication::translate("directManageWidget", "\320\222 \320\275\321\203\320\273\320\265\320\262\321\203\321\216", nullptr));
        stopButton->setText(QCoreApplication::translate("directManageWidget", "\320\241\321\202\320\276\320\277", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("directManageWidget", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 \321\200\320\260\320\261\320\276\321\207\320\265\320\271 \320\267\320\276\320\275\321\213", nullptr));
        endPosYLable->setText(QCoreApplication::translate("directManageWidget", "0", nullptr));
        label_11->setText(QCoreApplication::translate("directManageWidget", "\320\245 = ", nullptr));
        endPosXLable->setText(QCoreApplication::translate("directManageWidget", "0", nullptr));
        label_12->setText(QCoreApplication::translate("directManageWidget", "Z = ", nullptr));
        endPosZLable->setText(QCoreApplication::translate("directManageWidget", "0", nullptr));
        label_13->setText(QCoreApplication::translate("directManageWidget", "Y = ", nullptr));
#if QT_CONFIG(tooltip)
        setEndPosButton->setToolTip(QCoreApplication::translate("directManageWidget", "<html><head/><body><p>\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\207\321\203\321\216 \320\267\320\276\320\275\321\203</p><p>\321\202\320\265\320\272\321\203\321\211\320\270\320\274\320\270 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260\320\274\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        setEndPosButton->setText(QCoreApplication::translate("directManageWidget", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        drawWorkZoneButton->setToolTip(QCoreApplication::translate("directManageWidget", "<html><head/><body><p>\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\207\321\203\321\216 \320\267\320\276\320\275\321\203</p><p>\321\202\320\265\320\272\321\203\321\211\320\270\320\274\320\270 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260\320\274\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        drawWorkZoneButton->setText(QCoreApplication::translate("directManageWidget", "\320\240\320\260\321\201\321\207\320\265\321\200\321\202\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        resetWorkZoneButton->setToolTip(QCoreApplication::translate("directManageWidget", "<html><head/><body><p>\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\207\321\203\321\216 \320\267\320\276\320\275\321\203</p><p>\321\202\320\265\320\272\321\203\321\211\320\270\320\274\320\270 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260\320\274\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        resetWorkZoneButton->setText(QCoreApplication::translate("directManageWidget", "\320\241\320\261\321\200\320\276\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class directManageWidget: public Ui_directManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTMANAGEWIDGET_H
