#include "mylineedit.h"
#define MAX_SHORTCUTS 3

MyLineEdit::MyLineEdit(QWidget* parent)
    :QLineEdit (parent)
{
}

/**
* @method        MyLineEdit::keyPressEvent
* @brief         监控键盘输入
* @param         QKeyEvent
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void MyLineEdit::keyPressEvent(QKeyEvent *e)
{
    QString text =QString();
    int keyInt = e->key();
    bool modifiers = e->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier | Qt::AltModifier | Qt::MetaModifier);

    if (!modifiers && (keyInt == Qt::Key_Delete || keyInt == Qt::Key_Backspace)) {
        setText("");
        return;
    }

    QString sequenceStr = keyEventToString(e);
    if (sequenceStr == "") {
        QLineEdit::keyPressEvent(e);
        return;
    }

    if (text.split(", ").size() >= MAX_SHORTCUTS)
        text = "";

    if (!text.isEmpty())
        text += ", ";

    setText(text + sequenceStr);
}

/**
* @method        MyLineEdit::keyEventToString
* @brief         按键转为QString
* @param         QKeyEvent
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
QString MyLineEdit::keyEventToString(QKeyEvent *e)
{
    int keyInt = e->key();
    QString seqStr = QKeySequence(e->key()).toString();

    if (seqStr.isEmpty() ||
            keyInt == Qt::Key_Control ||
            keyInt == Qt::Key_Alt || keyInt == Qt::Key_AltGr ||
            keyInt == Qt::Key_Meta ||
            keyInt == Qt::Key_Shift)
    {
        return "";
    }

    QStringList sequenceStr;
    if (e->modifiers() & Qt::ControlModifier)
        sequenceStr << "Ctrl";
    if (e->modifiers() & Qt::AltModifier)
        sequenceStr << "Alt";
    if (e->modifiers() & Qt::ShiftModifier)
        sequenceStr << "Shift";
    if (e->modifiers() & Qt::MetaModifier)
        sequenceStr << "Meta";

    return sequenceStr.join("+") + (sequenceStr.isEmpty() ? "" : "+") + seqStr;
}
