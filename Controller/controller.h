#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Model/model.h"
#include "View/mainwindow.h"

class Controller: public QObject{
        Q_OBJECT

public:
    explicit Controller(QObject* parent = nullptr);
    ~Controller();
    Character* getCharacter() const;

public slots:
    void slotRemoveArmorItem();
    void slotRemoveWeaponItem();
    void slotAddArmorItem();
    void slotAddWeaponItem();
    void slotReset();
    void slotLock();
    void slotFight();
    void slotQuit();

private:
    void updateView();

    Model* model;
    MainWindow* view;
};
#endif // CONTROLLER_H
