#ifndef LIST_H
#define LIST_H

#include <QWidget>
#include <QListWidget>
#include "listitem.h"

class List : public QListWidget
{
private:
    Q_OBJECT
    QWidget* parent;

public:
    List(QWidget* p = nullptr);
    ListItem* currentItem() const;

public slots:
    void removeItem(QListWidgetItem* i);
};

#endif // LIST_H
