#ifndef STANOKOBJECT_H
#define STANOKOBJECT_H

#include <QObject>
#include <QWidget>

class mashineObject : public QObject
{

    Q_OBJECT

public:
    mashineObject(QWidget *parent = nullptr);
    QString getLastError();


protected:
    QString lastError;
    QWidget *parentWidget;


};

#endif // STANOKOBJECT_H
