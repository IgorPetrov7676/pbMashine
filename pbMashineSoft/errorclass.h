#ifndef ERRORCLASS_H
#define ERRORCLASS_H

#include <QObject>
#include <QString>

enum error{
    ERROR_NO_ERROR = 0,
    ERROR_ERROR_CRC,
    ERROR_UNCKNOW_MESSAGE_TYPE,
    ERROR_WRONG_FIRST_BYTE,
    ERROR_OUT_OF_WORKPLACE_X,
    ERROR_OUT_OF_WORKPLACE_Y,
    ERROR_OUT_OF_WORKPLACE_Z,
    ERROR_UNKNOW_ERROR
};


class errorClass
{
public:
    errorClass();
    static QString getErrorString(error currentError);

};

#endif // ERRORCLASS_H
