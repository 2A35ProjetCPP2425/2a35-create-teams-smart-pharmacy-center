QT += sql
QT += charts
<<<<<<< HEAD
=======
QT += serialport

>>>>>>> 8fb8c24 (Deuxieme commit)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
<<<<<<< HEAD
           connection.cpp \
           distributeur.cpp \
           mainwindow.cpp \
           distribution.cpp

HEADERS += \
    connection.h \
    distributeur.h \
    distribution.h \
    mainwindow.h
=======
           arduino.cpp \
           connection.cpp \
           distributeur.cpp \
           mainwindow.cpp \
           distribution.cpp \
           medicament.cpp

HEADERS += \
    arduino.h \
    connection.h \
    distributeur.h \
    distribution.h \
    mainwindow.h \
    medicament.h
>>>>>>> 8fb8c24 (Deuxieme commit)

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
