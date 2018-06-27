#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T12:03:13
#
#-------------------------------------------------

QT       += core gui \
multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceShooter
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
        main.cpp \
    game.cpp \
    player.cpp \
    enemy.cpp \
    score.cpp \
    health.cpp \
    meteor.cpp \
    shot.cpp \
    shield.cpp \
    life.cpp \
    enemy_bullet.cpp \
    enemy_shot.cpp \
    player_bullet.cpp \
    bonus.cpp \
    boss.cpp

HEADERS += \
    game.h \
    player.h \
    enemy.h \
    score.h \
    health.h \
    meteor.h \
    shot.h \
    shield.h \
    life.h \
    enemy_bullet.h \
    enemy_shot.h \
    player_bullet.h \
    bonus.h \
    boss.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc
