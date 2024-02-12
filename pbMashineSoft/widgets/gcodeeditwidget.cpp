#include "gcodeeditwidget.h"

gCodeEditWidget::gCodeEditWidget(QWidget *parent):
    QTextEdit(parent)
{
    currentString=0;
    connect(this,SIGNAL(cursorPositionChanged()),this,SLOT(cursorPosChangedSlot()));
}
//////////////////////////////////////////////////////////////////////////////////////////
void gCodeEditWidget::setCurrentString(int number){
    QTextCursor cursor=this->textCursor();
    QTextBlock block;
    int startPos=0;
    int endPos=0;
    QTextCharFormat fmt;
    if(number>=0){
        block=this->document()->findBlockByNumber(currentString);
        startPos=block.position();
        endPos=startPos+block.length()-1;
        fmt.setBackground(Qt::white);
        cursor.setPosition(startPos, QTextCursor::MoveAnchor);
        cursor.setPosition(endPos, QTextCursor::KeepAnchor);
        cursor.setCharFormat(fmt);

        block=this->document()->findBlockByNumber(number);
        startPos=block.position();
        endPos=startPos+block.length()-1;
        fmt.setBackground(Qt::yellow);
        cursor.setPosition(startPos, QTextCursor::MoveAnchor);
        cursor.setPosition(endPos, QTextCursor::KeepAnchor);
        cursor.setCharFormat(fmt);
        currentString=number;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
void gCodeEditWidget::setPenDiameter(float diameter){
    parser.setPenDiameter(diameter);
}
///////////////////////////////////////////////////////////////////////////////////
void gCodeEditWidget::reset(){
    this->clear();
    parser.reset();
    currentString = 0;
}
////////////////////////////////////////////////////////////////////////////////////
QStringList *gCodeEditWidget::getProgramm(){
    if(checkSyntaxis() == true){
        QStringList *tmpList = new QStringList();//за удаление отвечает вызывающий
        QString text = this->toPlainText();
        int lastIndex = 0;
        int index = 0;
        do{
            index = text.indexOf("\n", lastIndex);
            if(index != -1){
                QString tmpString = text.mid(lastIndex, index - lastIndex + 1);
                if( !tmpString.isEmpty()){
                    tmpList->append(tmpString);
                    lastIndex = index + 1;
                }
            }
        }while(index != -1);
        return tmpList;
    }
    return nullptr;
}
//////////////////////////////////////////////////////////////////////////////////
bool gCodeEditWidget::checkSyntaxis(){
    //TODO добавить проверку синтаксиса в окне G кода


    return true;
}
//////////////////////////////////////////////////////////////////////////////////
void gCodeEditWidget::textChangedSlot(){
    this->cursor().setPos(0,0);
}
///////////////////////////////////////////////////////////////////////////////////
void gCodeEditWidget::cursorPosChangedSlot(){
    QTextCursor cursor=this->textCursor();
    QTextBlock block=cursor.block();
    int number=block.blockNumber();
    parser.shineDrawCommand(number);
    emit updateViewSignal();
}
