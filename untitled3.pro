#-------------------------------------------------
#
# Project created by QtCreator 2020-02-16T07:22:44
#
#-------------------------------------------------

QT       += core gui
QT       += core network
CONFIG -= console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
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
LIBS += -lws2_32
CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    copy.cpp \
    progress.cpp \
    vhod.cpp \
    registration.cpp \
    my_label.cpp \
    settings.cpp \
    prosmotr.cpp

HEADERS += \
        mainwindow.h \
    copy.h \
    progress.h \
    vhod.h \
    registration.h \
    enum.h \
    my_label.h \
    settings.h \
    prosmotr.h

FORMS += \
        mainwindow.ui \
    copy.ui \
    progress.ui \
    vhod.ui \
    registration.ui \
    settings.ui \
    prosmotr.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
