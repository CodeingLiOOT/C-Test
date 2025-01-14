#-------------------------------------------------
#
# Project created by QtCreator 2020-05-19T20:33:39
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = baoshimizhen
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
    chessboard.cpp \
    helpdialog.cpp \
    login.cpp \
        main.cpp \
        mainwindow.cpp \
    menu.cpp \
    rankwindow.cpp \
    registerwindow.cpp \
    startpage.cpp \
    thread.cpp \
    mainwindow1.cpp

HEADERS += \
    chessboard.h \
    helpdialog.h \
    login.h \
        mainwindow.h \
    menu.h \
    rankwindow.h \
    registerwindow.h \
    startpage.h \
    thread.h \
    mainwindow1.h

FORMS += \
    helpdialog.ui \
        login.ui \
        mainwindow.ui \
        menu.ui \
        rankwindow.ui \
        registerwindow.ui \
        startpage.ui \
    mainwindow1.ui

RESOURCES += \
    pic.qrc
