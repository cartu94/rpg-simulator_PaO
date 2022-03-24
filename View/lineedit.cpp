#include "lineedit.h"

LineEdit::LineEdit(const QString &contents, QWidget *parent): QLineEdit(contents, parent) {
    setReadOnly(true);
}

void LineEdit::setText(int i) {
    QLineEdit::setText(QString::fromStdString(std::to_string(i)));
}

void LineEdit::setTextHp(int i) {
    i = 50 + i * 5;
    QLineEdit::setText(QString::fromStdString(std::to_string(i)));
}
