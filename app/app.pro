QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Déclaration des fichiers sources
SOURCES += \
    main.cpp \
    ui/mainwindow.cpp

HEADERS += \
    ui/mainwindow.hpp

FORMS += \
    ui/mainwindow.ui

# Fichiers de traduction
TRANSLATIONS += \
    languages/QT-CI-Template_fr_FR.ts

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
