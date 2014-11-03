#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T09:05:22
#
#-------------------------------------------------

QT += core gui
QT += network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_receiver_rewrite
TEMPLATE = app


SOURCES += main.cpp \
    receiver.cpp \
    ../gpp_qt/wfunction/wfunction.cpp

HEADERS  += \
    receiver.h \
    ../gpp_qt/wfunction/wfunction.h

FORMS    += mainwindow.ui
