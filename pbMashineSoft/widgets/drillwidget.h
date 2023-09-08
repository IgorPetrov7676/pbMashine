#ifndef DRILLWIDGET_H
#define DRILLWIDGET_H

#include <QWidget>

namespace Ui {
class drillWidget;
}

class drillWidget : public QWidget
{
    Q_OBJECT

public:
    explicit drillWidget(QWidget *parent = nullptr);
    ~drillWidget();

private:
    Ui::drillWidget *ui;
};

#endif // DRILLWIDGET_H
