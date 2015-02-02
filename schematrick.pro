#-------------------------------------------------
#
# Project created by QtCreator 2015-01-27T00:15:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT             += widgets
greaterThan(QT_MAJOR_VERSION, 4): CONFIG         += c++11
lessThan(QT_MAJOR_VERSION, 5):    QMAKE_CXXFLAGS += -std=c++0x

QMAKE_CXXFLAGS += -fvisibility-inlines-hidden -fvisibility=hidden
QMAKE_CXXFLAGS_DEBUG += -Og

TARGET   = schematrick
TEMPLATE = app

DEFINES  += QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII

SOURCES  += main.cpp\
    mainwidget.cpp \
    utils.cpp \
    abstractschemaitem.cpp \
    gridscene.cpp

HEADERS  += mainwidget.h \
    utils.h \
    abstractschemaitem.h \
    gridscene.h

FORMS    += mainwidget.ui
