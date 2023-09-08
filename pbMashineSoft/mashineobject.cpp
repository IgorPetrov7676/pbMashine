#include "mashineobject.h"

mashineObject::mashineObject(QWidget *parent)
{
    parentWidget=parent;
}
//////////////////////////////////////////////////////////////////////
QString mashineObject::getLastError(){
    QString tmp=lastError;
    lastError.clear();
    return tmp;
}
