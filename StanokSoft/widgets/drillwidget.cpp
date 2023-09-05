#include "drillwidget.h"
#include "ui_drillwidget.h"

drillWidget::drillWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drillWidget)
{
    ui->setupUi(this);
}

drillWidget::~drillWidget()
{
    delete ui;
}
