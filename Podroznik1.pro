QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataBase/maindb.cpp \
    Mapa/mapa.cpp \
    Zasoby/addlanguage.cpp \
    Zasoby/language.cpp \
    Zasoby/plecak.cpp \
    Zasoby/zasoby.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DataBase/maindb.h \
    Mapa/mapa.h \
    Zasoby/addlanguage.h \
    Zasoby/language.h \
    Zasoby/plecak.h \
    Zasoby/zasoby.h \
    mainwindow.h

FORMS += \
    Mapa/mapa.ui \
    Zasoby/addlanguage.ui \
    Zasoby/plecak.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
