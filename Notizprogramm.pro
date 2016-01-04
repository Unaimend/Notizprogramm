#-------------------------------------------------
#
# Project created by QtCreator 2016-01-03T16:38:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notizprogramm
TEMPLATE = app
LIBS += /usr/lib/x86_64-linux-gnu/libGL.so.1


SOURCES += main.cpp\
        mainwindow.cpp \
    Note.cpp

HEADERS  += mainwindow.h \
    Note.h

FORMS    += mainwindow.ui
