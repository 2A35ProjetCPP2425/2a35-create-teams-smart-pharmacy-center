#include "arduino.h"
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent), serial(new QSerialPort(this)), portName("COM5"), baudRate(9600) {}

Arduino::~Arduino() {
    if (serial->isOpen())
        serial->close();
}

bool Arduino::connectArduino() {
    serial->setPortName(portName);
    serial->setBaudRate(baudRate);
    if (serial->open(QIODevice::ReadOnly)) {
        qDebug() << "Arduino connecté sur" << portName;
        return true;
    } else {
        qDebug() << "Erreur : Impossible de se connecter à" << portName;
        return false;
    }
}

void Arduino::disconnectArduino() {
    if (serial->isOpen())
        serial->close();
}

QString Arduino::readData() {
    if (serial->isOpen() && serial->bytesAvailable()) {
        QByteArray data = serial->readAll();
        return QString(data).trimmed(); // Retirer espaces et nouvelles lignes
    }
    return QString();
}

