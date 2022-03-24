#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    LineEdit(const QString &contents, QWidget *parent = nullptr);

public slots:
    void setText(int i);
    void setTextHp(int i);
};

#endif // LINEEDIT_H
