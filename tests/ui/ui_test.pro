QT += core gui widgets testlib
TEMPLATE = app
TARGET = ui_test
INCLUDEPATH += ../../src

# Configuration des sources
SOURCES += ui_test.cpp\
    ../../src/ui/mainwindow.cpp

HEADERS += ../../src/ui/mainwindow.hpp

FORMS += ../../src/ui/mainwindow.ui