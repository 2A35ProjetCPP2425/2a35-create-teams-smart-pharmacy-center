QT       += core gui sql network
QT += printsupport
QT += charts
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    medicament.cpp \
    mainwindow.cpp \
    rendezvous.cpp \
    salle.cpp \
    service.cpp

HEADERS += \
    arduino.h \
    connection.h \
    medicament.h \
    mainwindow.h \
    rendezvous.h \
    salle.h \
    service.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc

DISTFILES += \
    ../../Auto Ecole (1)/3.jpg \
    ../../Auto Ecole (1)/3.jpg
