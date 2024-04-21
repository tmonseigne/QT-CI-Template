QT += core gui widgets testlib
TEMPLATE = app
TARGET = ui_test
INCLUDEPATH += ../../app

# Configuration des sources
SOURCES += ui_test.cpp\
    ../../app/ui/mainwindow.cpp

HEADERS += ../../app/ui/mainwindow.hpp

FORMS += ../../app/ui/mainwindow.ui