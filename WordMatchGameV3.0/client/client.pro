#-------------------------------------------------
#
# Project created by QtCreator 2023-04-30T22:15:46
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WordMatchGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    addwordpage.cpp \
    gamepage.cpp \
        main.cpp \
    playerpage.cpp \
    registration.cpp \
    searchpage.cpp \
    testerpage.cpp \
        widget.cpp \
    player.cpp \
    member.cpp \
    tester.cpp

HEADERS += \
    addwordpage.h \
    gamepage.h \
    playerpage.h \
    registration.h \
    searchpage.h \
    testerpage.h \
        widget.h \
    player.h \
    member.h \
    tester.h

FORMS += \
        addwordpage.ui \
        gamepage.ui \
        playerpage.ui \
        registration.ui \
        searchpage.ui \
        testerpage.ui \
        widget.ui

RESOURCES += \
    pic.qrc

QT += sql
QT += core gui sql
