#-------------------------------------------------
#
# Project created by QtCreator 2021-06-04T13:35:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progetto
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Controller/controller.cpp \
    Model/armor.cpp \
    Model/character.cpp \
    Model/enemy.cpp \
    Model/heavyarmor.cpp \
    Model/heavyweapon.cpp \
    Model/item.cpp \
    Model/lightarmor.cpp \
    Model/lightweapon.cpp \
    Model/mediumarmor.cpp \
    Model/mediumweapon.cpp \
    Model/model.cpp \
    Model/shield.cpp \
    Model/weapon.cpp \
    View/mainwindow.cpp \
    main.cpp \
    View/listitem.cpp \
    View/list.cpp \
    View/lineedit.cpp \
    View/enemylistitem.cpp \
    View/enemylist.cpp


HEADERS += \
    Controller/controller.h \
    Model/armor.h \
    Model/character.h \
    Model/deepptr.h \
    Model/dlist.h \
    Model/enemy.h \
    Model/heavyarmor.h \
    Model/heavyweapon.h \
    Model/item.h \
    Model/lightarmor.h \
    Model/lightweapon.h \
    Model/mediumarmor.h \
    Model/mediumweapon.h \
    Model/model.h \
    Model/shield.h \
    Model/weapon.h \
    View/mainwindow.h \
    View/listitem.h \
    View/list.h \
    View/lineedit.h \
    View/enemylistitem.h \
    View/enemylist.h


FORMS +=
