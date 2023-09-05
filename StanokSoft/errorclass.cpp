#include "errorclass.h"

errorClass::errorClass()
{

}
///////////////////////////////////////////////////////////////////
QString errorClass::getErrorString(error currentError){
    switch(currentError){
        case(ERROR_NO_ERROR):{
            return QObject::tr("Без ошибок");
        }
        case(ERROR_ERROR_CRC):{
            return QObject::tr("Ошибка контрольной суммы");
        }
        case(ERROR_UNCKNOW_MESSAGE_TYPE):{
            return QObject::tr("Неизвестный тип пакета");
        }
        case(ERROR_WRONG_FIRST_BYTE):{
            return QObject::tr("Первый байт пакета не может быть нулем.");
        }
        case(ERROR_OUT_OF_WORKPLACE_X):{
            return QObject::tr("Выход за пределы рабочего поля. Срабатывание концевика оси X");
        }
        case(ERROR_OUT_OF_WORKPLACE_Y):{
            return QObject::tr("Выход за пределы рабочего поля. Срабатывание концевика оси Y");
        }
        case(ERROR_OUT_OF_WORKPLACE_Z):{
            return QObject::tr("Выход за пределы рабочего поля. Срабатывание концевика оси Z");
        }
        default:{
            return QObject::tr("Неизвестная ошибка.");
            break;
        }
    }
}
