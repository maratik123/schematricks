#-------------------------------------------------
#
# Project created by QtCreator 2015-01-27T00:15:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = schematrick
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    abstractschemaitem.cpp

HEADERS  += mainwidget.h \
    abstractschemaitem.h

FORMS    += mainwidget.ui