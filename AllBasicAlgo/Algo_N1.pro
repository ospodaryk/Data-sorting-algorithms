QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LAb2.cpp \
    array.cpp \
    lab4.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    LAb2.h \
    array.h \
    lab4.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Algo_N1_uk_UA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
