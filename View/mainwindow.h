#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include "list.h"
#include "enemylist.h"
#include "lineedit.h"
#include "Model/model.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    List* getEquipArmorList();
    List* getEquipWeaponList();
    List* getArmorList();
    List* getWeaponList();
    LineEdit* getDamageValue();
    LineEdit* getDefenceValue();
    LineEdit* getMoneyValue();
    LineEdit* getHpValue();
    LineEdit* getStrValue();
    LineEdit* getDexValue();
    EnemyList* getEnemyList();
    QGroupBox* getStatsBox();
    QGroupBox* getEquipBox();
    QGroupBox* getItemsListBox();
    QPushButton* getFightButton();
    QSpinBox* getStatPoints();

public slots:
    void setSpinBox();
    void reset();
    void resetEnemies();

signals:
    void signalRemoveArmorItem();
    void signalRemoveWeaponItem();
    void signalAddWeaponItem();
    void signalAddArmorItem();
    void signalReset();
    void signalFight();
    void signalLock();
    void signalQuit();

private:
    QGroupBox *equipArmorBox, *equipWeaponBox, *statsBox, *enemyBox, *buttonsBox, *weaponBox, *armorBox, *equipmentBox, *itemsListBox;
    QBoxLayout *equipArmorBoxLayout, *equipWeaponBoxLayout, *enemyBoxLayout, *weaponBoxLayout, *armorBoxLayout;
    QHBoxLayout *wrapperHLayout, *buttonsBoxLayout;
    QGridLayout *equipLayout, *statsLayout, *itemsLayout;
    QVBoxLayout *wrapLeftLayout, *wrapRightLayout;
    List *equipArmorList, *equipWeaponList, *weaponList, *armorList;
    EnemyList *enemyList;
    QPushButton *resetButton, *fightButton, *removeArmorButton, *removeWeaponButton, *lockButton, *addArmorButton, *addWeaponButton, *quitButton;
    QSlider *hpSlider, *strSlider, *dexSlider;
    QLabel *hpLabel, *strLabel, *dexLabel, *statPointsLabel, *moneyLabel, *damageLabel, *defenceLabel;
    LineEdit *hpValue, *strValue, *dexValue, *moneyValue, *damageValue, *defenceValue;
    QSpinBox *statPoints;

};

#endif // MAINWINDOW_H
