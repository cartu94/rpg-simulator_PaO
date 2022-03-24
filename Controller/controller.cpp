#include "controller.h"

#include <QMessageBox>

Controller::Controller(QObject* parent): QObject(parent), model(new Model()),  view(new MainWindow()) {
    connect(view, SIGNAL(signalRemoveArmorItem()), this, SLOT(slotRemoveArmorItem()));
    connect(view, SIGNAL(signalRemoveWeaponItem()), this, SLOT(slotRemoveWeaponItem()));
    connect(view, SIGNAL(signalAddArmorItem()), this, SLOT(slotAddArmorItem()));
    connect(view, SIGNAL(signalAddWeaponItem()), this, SLOT(slotAddWeaponItem()));
    connect(view, SIGNAL(signalReset()), this, SLOT(slotReset()));
    connect(view, SIGNAL(signalLock()), this, SLOT(slotLock()));
    connect(view, SIGNAL(signalFight()), this, SLOT(slotFight()));
    connect(view, SIGNAL(signalQuit()), this, SLOT(slotQuit()));

    view->show();
}

Controller::~Controller() {
    delete model;
    delete view;
}

Character *Controller::getCharacter() const {
    return model->getCharacter();
}

void Controller::slotRemoveArmorItem() {
    List *l = view->getEquipArmorList();
    ListItem *li = l->currentItem();
    if(li) {
        Item *i = li->getItem();
        if(model->getCharacter()->removeEquip(*i)) {
            l->removeItem(li);
            updateView();
        }
    }
}

void Controller::slotRemoveWeaponItem() {
    List *l = view->getEquipWeaponList();
    ListItem *li = l->currentItem();
    if(li) {
        Item *i = li->getItem();
        if(model->getCharacter()->removeEquip(*i)) {
            l->removeItem(li);
            updateView();
        }
    }
}

void Controller::slotAddArmorItem() {
    List *l = view->getArmorList();
    ListItem *li = l->currentItem();
    if(li) {
        Item *i = li->getItem();
        int err = model->getCharacter()->addEquip(*i);
        QMessageBox *msg;
        switch (err) {
        case 1:
            updateView();
            view->getEquipArmorList()->addItem(new ListItem(i->clone()));
            break;
        case 0:
            msg = new QMessageBox(QMessageBox::Warning, "Error", "Not enough money remove something first", QMessageBox::Ok);
            msg->exec();
            break;
        case -1:
            msg = new QMessageBox(QMessageBox::Warning, "Error", "Couldn't add the shield, be sure to have only 1 light or medium weapon equipped", QMessageBox::Ok);
            msg->exec();
            break;
        case -2:
            msg = new QMessageBox(QMessageBox::Warning, "Error", "Couldn't add the armor, remove the previously equipped one first", QMessageBox::Ok);
            msg->exec();
            break;
        }
    }
}

void Controller::slotAddWeaponItem() {
    List *l = view->getWeaponList();
    ListItem *li = l->currentItem();
    if(li) {
        Item *i = li->getItem();
        int err = model->getCharacter()->addEquip(*i->clone());
        QMessageBox *msg;
        switch (err) {
        case 1:
            updateView();
            view->getEquipWeaponList()->addItem(new ListItem(i->clone()));
            break;
        case 0:
            msg = new QMessageBox(QMessageBox::Warning, "Error", "Not enough money remove something first", QMessageBox::Ok);
            msg->exec();
            break;
        case -3:
            msg = new QMessageBox(QMessageBox::Warning, "Error", "Couldn't add the heavy weapon, remove all equipped weapons and shields first", QMessageBox::Ok);
            msg->exec();
            break;
        case -4:
            msg = new QMessageBox(QMessageBox::Warning, "Error", "Couldn't add the medium weapon, remove all equipped weapons first", QMessageBox::Ok);
            msg->exec();
            break;
        case -5:
            msg = new QMessageBox(QMessageBox::Warning, "Error", "Couldn't add the light weapon, remove the surplus equipment first \n(you can have 2 light weapons or a light weapon and a shield)", QMessageBox::Ok);
            msg->exec();
            break;
        }
    }
}

void Controller::slotReset() {
    delete model;
    model = new Model();
    view->getEquipArmorList()->clear();
    view->getEquipWeaponList()->clear();
    updateView();

    //enable-disable ---------------------------------------
    QGroupBox *stats = view->getStatsBox();
    QGroupBox *equip = view->getEquipBox();
    QGroupBox *itemsList = view->getItemsListBox();
    QPushButton *fightB = view->getFightButton();

    stats->setEnabled(true);
    equip->setEnabled(false);
    itemsList->setEnabled(false);
    fightB->setEnabled(false);
}

void Controller::slotLock() {
    if(view->getStatPoints()->value() > 0){
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning, "Error", "Use all your stat points before locking", QMessageBox::Ok);
        msg->exec();
    } else {
    //enable-disable ----------------------------------------
        QGroupBox *stats = view->getStatsBox();
        QGroupBox *equip = view->getEquipBox();
        QGroupBox *itemsList = view->getItemsListBox();
        QPushButton *fightB = view->getFightButton();

        stats->setEnabled(false);
        equip->setEnabled(true);
        itemsList->setEnabled(true);
        fightB->setEnabled(true);
        //--------------------------------------------------------
        model->getCharacter()->setHealth(view->getHpValue()->text().toInt());
        model->getCharacter()->setStrength(view->getStrValue()->text().toInt());
        model->getCharacter()->setDexterity(view->getDexValue()->text().toInt());
        model->getCharacter()->setStatPoints(view->getStatPoints()->text().toInt());
    }
}

void Controller::slotFight() {
    EnemyListItem *enemyListItem = view->getEnemyList()->currentItem();
    QMessageBox *msg;
    if(enemyListItem){
        model->setEnemy(enemyListItem->getItem());
        std::string result;
        while(model->getCharacter()->getHealth() > 0 && model->getEnemy()->getHealth() > 0){
            result = model->fight();
            view->getHpValue()->setText(model->getCharacter()->getHealth());
            msg = new QMessageBox(QMessageBox::NoIcon, "FIGHT", QString::fromStdString(result), QMessageBox::Ok);
            msg->exec();
        }
        if(model->getEnemy()->getHealth() <= 0){
            model->getCharacter()->addMoney(model->getEnemy()->getValue());
            updateView();
            view->resetEnemies();
        }
        if(model->getCharacter()->getHealth() <= 0){
            slotReset();
            view->reset();
            view->resetEnemies();
        }
    } else {
        msg = new QMessageBox(QMessageBox::Warning, "Error", "Select an enemy first", QMessageBox::Ok);
        msg->exec();
    }
}

void Controller::slotQuit() {
    delete model;
    view->close();
}

void Controller::updateView() {
    LineEdit *damage = view->getDamageValue();
    LineEdit *defence = view->getDefenceValue();
    LineEdit *money = view->getMoneyValue();

    damage->setText(model->getCharacter()->calcDamage());
    defence->setText(model->getCharacter()->calcDefence());
    money->setText(model->getCharacter()->getMoney());
}
