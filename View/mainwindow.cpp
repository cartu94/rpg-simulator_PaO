#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent), equipArmorList(new List(this)), equipWeaponList(new List(this)) {
    wrapperHLayout = new QHBoxLayout(this);

    wrapLeftLayout = new QVBoxLayout();
    wrapperHLayout->addLayout(wrapLeftLayout);

    wrapRightLayout = new QVBoxLayout();
    wrapperHLayout->addLayout(wrapRightLayout);

// LEFT ---------------------------------------------------------------
// stats --------------------------------------------------------------
    statsBox = new QGroupBox("Stats");
    wrapLeftLayout->addWidget(statsBox);

    statsLayout = new QGridLayout();
    statsLayout->setColumnMinimumWidth(4, 60);
    statsLayout->setRowMinimumHeight(4, 30);
    statsBox->setLayout(statsLayout);

    statPointsLabel = new QLabel("Stat Points: ");
    statPointsLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statsLayout->addWidget(statPointsLabel, 0, 5);
    statPoints = new QSpinBox();
    statPoints->setValue(25);
    statPoints->setMaximum(25);
    statPoints->setMinimum(0);
    statPoints->setReadOnly(true);
    statsLayout->addWidget(statPoints, 0, 6);

    moneyLabel = new QLabel("Money: ");
    moneyLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statsLayout->addWidget(moneyLabel, 1, 5);
    moneyValue = new LineEdit("50");
    statsLayout->addWidget(moneyValue, 1 , 6);

    lockButton = new QPushButton("Lock");
    statsLayout->addWidget(lockButton, 6, 6);


    // health row -----------------------------------------------------
    hpLabel = new QLabel("Health: ");
    hpLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statsLayout->addWidget(hpLabel, 0, 0);
    hpValue = new LineEdit("50");
    hpValue->setReadOnly(true);
    statsLayout->addWidget(hpValue, 0, 1);
    hpSlider = new QSlider();
    hpSlider->setRange(0, 25);
    hpSlider->setOrientation(Qt::Horizontal);
    hpSlider->setMinimumWidth(100);
    statsLayout->addWidget(hpSlider, 0, 2);

    // strength row ---------------------------------------------------
    strLabel = new QLabel("Strength: ");
    strLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statsLayout->addWidget(strLabel, 1, 0);
    strValue = new LineEdit("0");
    strValue->setReadOnly(true);
    statsLayout->addWidget(strValue, 1, 1);
    strSlider = new QSlider();
    strSlider->setRange(0, 25);
    strSlider->setOrientation(Qt::Horizontal);
    statsLayout->addWidget(strSlider, 1, 2);

    // dexterity row --------------------------------------------------
    dexLabel = new QLabel("Dexterity: ");
    dexLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statsLayout->addWidget(dexLabel, 2, 0);
    dexValue = new LineEdit("0");
    dexValue->setReadOnly(true);
    statsLayout->addWidget(dexValue, 2, 1);
    dexSlider = new QSlider();
    dexSlider->setRange(0, 25);
    dexSlider->setOrientation(Qt::Horizontal);
    statsLayout->addWidget(dexSlider, 2, 2);

    // damage row -----------------------------------------------------
    damageLabel = new QLabel("Damage: ");
    damageLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statsLayout->addWidget(damageLabel, 5, 0);
    damageValue = new LineEdit("0");
    damageValue->setReadOnly(true);
    statsLayout->addWidget(damageValue, 5, 1);

    // defence row ----------------------------------------------------
    defenceLabel = new QLabel("Defence: ");
    defenceLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statsLayout->addWidget(defenceLabel, 6, 0);
    defenceValue = new LineEdit("0");
    defenceValue->setReadOnly(true);
    statsLayout->addWidget(defenceValue, 6, 1);

// equip --------------------------------------------------------------
    equipmentBox = new QGroupBox("Equipment");
    equipLayout = new QGridLayout();
    equipmentBox->setLayout(equipLayout);
    wrapLeftLayout->addWidget(equipmentBox);

    // armor list -----------------------------------------------------
    equipArmorBox = new QGroupBox("Armors");
    equipLayout->addWidget(equipArmorBox, 0, 0);
    equipArmorBoxLayout = new QVBoxLayout();
    equipArmorBoxLayout->addWidget(equipArmorList);
    equipArmorBox->setLayout(equipArmorBoxLayout);
    removeArmorButton = new QPushButton("Remove");
    equipLayout->addWidget(removeArmorButton, 1, 0);

    // weapon list ----------------------------------------------------
    equipWeaponBox = new QGroupBox("Weapons");
    equipLayout->addWidget(equipWeaponBox, 0, 1);
    equipWeaponBoxLayout = new QVBoxLayout();
    equipWeaponBoxLayout->addWidget(equipWeaponList);
    equipWeaponBox->setLayout(equipWeaponBoxLayout);
    removeWeaponButton = new QPushButton("Remove");
    equipLayout->addWidget(removeWeaponButton, 1, 1);

    equipmentBox->setEnabled(false);


// RIGHT --------------------------------------------------------------
    // enemies --------------------------------------------------------
    enemyBox = new QGroupBox("Enemies");
    enemyBox->setMinimumHeight(150);
    enemyBox->setMaximumHeight(150);
    enemyBoxLayout = new QVBoxLayout();
    enemyBox->setLayout(enemyBoxLayout);
    wrapRightLayout->addWidget(enemyBox);
    enemyList = new EnemyList();
    enemyBoxLayout->addWidget(enemyList);

    // items list -----------------------------------------------------
    itemsListBox = new QGroupBox("Items List");
    itemsListBox->setMinimumHeight(550);
    itemsLayout = new QGridLayout();
    itemsListBox->setLayout(itemsLayout);
    wrapRightLayout->addWidget(itemsListBox);

    // armor list ----------------------------------------------------
    armorBox = new QGroupBox("Armors");
    armorBox->setMinimumWidth(210);
    itemsLayout->addWidget(armorBox, 0, 0);
    armorBoxLayout = new QVBoxLayout();
    ListItem *lArmor = new ListItem(new LightArmor("Leather", 10, 10));
    ListItem *mArmor = new ListItem(new MediumArmor("Hide", 12, 20, 15));
    ListItem *hArmor = new ListItem(new HeavyArmor("Plate", 18, 30, 18));
    ListItem *shield = new ListItem(new Shield("Shield", 8, 12));
    armorList = new List();
    armorList->addItem(lArmor);
    armorList->addItem(mArmor);
    armorList->addItem(hArmor);
    armorList->addItem(shield);
    armorBoxLayout->addWidget(armorList);
    armorBox->setLayout(armorBoxLayout);
    addArmorButton = new QPushButton("Add");
    itemsLayout->addWidget(addArmorButton, 1, 0);

    // weapon list -----------------------------------------------------
    weaponBox = new QGroupBox("Weapons");    
    weaponBox->setMinimumWidth(210);
    itemsLayout->addWidget(weaponBox, 0, 1);
    weaponBoxLayout = new QVBoxLayout();
    ListItem *lWeapon = new ListItem(new LightWeapon("Dagger", 10, 6, 16));
    ListItem *mWeapon = new ListItem(new MediumWeapon("Longsword", 10, 13));
    ListItem *hWeapon = new ListItem(new HeavyWeapon("Greataxe", 10, 20, 18));
    weaponList = new List();
    weaponList->addItem(lWeapon);
    weaponList->addItem(mWeapon);
    weaponList->addItem(hWeapon);
    weaponBoxLayout->addWidget(weaponList);
    weaponBox->setLayout(weaponBoxLayout);
    addWeaponButton = new QPushButton("Add");
    itemsLayout->addWidget(addWeaponButton, 1, 1);
    resetEnemies();
    itemsListBox->setEnabled(false);

    // buttons --------------------------------------------------------
    buttonsBox = new QGroupBox();
    buttonsBox->setMaximumHeight(75);
    buttonsBoxLayout = new QHBoxLayout();
    buttonsBox->setLayout(buttonsBoxLayout);
    wrapRightLayout->addWidget(buttonsBox);
    fightButton = new QPushButton("FIGHT!");
    buttonsBoxLayout->addWidget(fightButton);
    fightButton->setEnabled(false);
    resetButton = new QPushButton("RESET");
    buttonsBoxLayout->addWidget(resetButton);
    quitButton = new QPushButton("QUIT");
    buttonsBoxLayout->addWidget(quitButton);



// connect ------------------------------------------------------------
    connect(hpSlider, SIGNAL(valueChanged(int)), this, SLOT(setSpinBox()));
    connect(strSlider, SIGNAL(valueChanged(int)), this, SLOT(setSpinBox()));
    connect(dexSlider, SIGNAL(valueChanged(int)), this, SLOT(setSpinBox()));
    connect(hpSlider, SIGNAL(valueChanged(int)), hpValue, SLOT(setTextHp(int)));
    connect(strSlider, SIGNAL(valueChanged(int)), strValue, SLOT(setText(int)));
    connect(dexSlider, SIGNAL(valueChanged(int)), dexValue, SLOT(setText(int)));
    connect(lockButton, SIGNAL(clicked(bool)), this, SIGNAL(signalLock()));

    connect(removeArmorButton, SIGNAL(clicked(bool)), this, SIGNAL(signalRemoveArmorItem()));
    connect(equipArmorList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SIGNAL(signalRemoveArmorItem()));

    connect(removeWeaponButton, SIGNAL(clicked(bool)), this, SIGNAL(signalRemoveWeaponItem()));
    connect(equipWeaponList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SIGNAL(signalRemoveWeaponItem()));

    connect(addArmorButton, SIGNAL(clicked(bool)), this, SIGNAL(signalAddArmorItem()));
    connect(armorList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SIGNAL(signalAddArmorItem()));

    connect(addWeaponButton, SIGNAL(clicked(bool)), this, SIGNAL(signalAddWeaponItem()));
    connect(weaponList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SIGNAL(signalAddWeaponItem()));

    connect(resetButton, SIGNAL(clicked(bool)), this, SIGNAL(signalReset()));
    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(reset()));
    connect(fightButton, SIGNAL(clicked(bool)), this, SIGNAL(signalFight()));
    connect(quitButton, SIGNAL(clicked(bool)), this, SIGNAL(signalQuit()));
}

List *MainWindow::getEquipArmorList() { return equipArmorList; }
List *MainWindow::getEquipWeaponList() { return equipWeaponList; }
List *MainWindow::getArmorList() { return armorList; }
List *MainWindow::getWeaponList() { return weaponList; }
LineEdit *MainWindow::getDamageValue() { return damageValue; }
LineEdit *MainWindow::getDefenceValue() { return defenceValue; }
LineEdit *MainWindow::getMoneyValue() { return moneyValue; }
LineEdit *MainWindow::getHpValue() { return hpValue; }
LineEdit *MainWindow::getStrValue() { return strValue; }
LineEdit *MainWindow::getDexValue() { return dexValue; }
EnemyList *MainWindow::getEnemyList() { return enemyList; }
QGroupBox *MainWindow::getStatsBox() { return statsBox; }
QGroupBox *MainWindow::getEquipBox() { return equipmentBox; }
QGroupBox *MainWindow::getItemsListBox() { return itemsListBox; }
QPushButton *MainWindow::getFightButton() { return fightButton; }
QSpinBox *MainWindow::getStatPoints() { return statPoints; }

void MainWindow::setSpinBox() {
    int hp = hpSlider->value();
    int str = strSlider->value();
    int dex = dexSlider->value();

    int stats = 25 - (hp+str+dex);
    hpSlider->setMaximum(25-(str+dex));
    strSlider->setMaximum(25-(hp+dex));
    dexSlider->setMaximum(25-(hp+str));
    statPoints->setValue(stats);
}

void MainWindow::reset() {
    statPoints->setValue(25);

    hpValue->setTextHp(0);
    hpSlider->setMaximum(25);
    hpSlider->setValue(0);

    strValue->setText(0);
    strSlider->setMaximum(25);
    strSlider->setValue(0);

    dexValue->setText(0);
    dexSlider->setMaximum(25);
    dexSlider->setValue(0);

    enemyList->selectionModel()->clear();
    weaponList->selectionModel()->clear();
    armorList->selectionModel()->clear();
}

void MainWindow::resetEnemies() {
    enemyList->clear();

    EnemyListItem *goblin = new EnemyListItem(new Enemy("Goblin", 20, 8, 5, 13, 2));
    enemyList->addItem(goblin);
    EnemyListItem *orc = new EnemyListItem(new Enemy("Orc", 85, 18, 15, 8, 6));
    enemyList->addItem(orc);
    EnemyListItem *troll = new EnemyListItem(new Enemy("Troll", 150, 30, 25, 5, 12));
    enemyList->addItem(troll);
    EnemyListItem *elf = new EnemyListItem(new Enemy("Elf", 40, 25, 8, 18, 8));
    enemyList->addItem(elf);
    EnemyListItem *dragon = new EnemyListItem(new Enemy("Dragon", 400, 40, 40, 30, 100));
    enemyList->addItem(dragon);
}
