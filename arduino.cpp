#include "arduino.h"
#include <QDebug>
#include <QStringList>

Arduino::Arduino(QObject *parent) : QObject(parent) {
    serial = new QSerialPort(this);  // Initialiser le port série
}

void Arduino::startCommunication() {
    // Configuration du port série
    serial->setPortName("COM4");  // Remplacez par le port COM utilisé par votre Arduino
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // Ouvrir le port série
    if (serial->open(QIODevice::ReadOnly)) {
        qDebug() << "Connexion au port série établie.";
        connect(serial, &QSerialPort::readyRead, this, &Arduino::readSerialData);
    } else {
        qDebug() << "Échec de la connexion au port série:" << serial->errorString();
    }
}
void Arduino::readSerialData() {
    while (serial->canReadLine()) {
        QByteArray data = serial->readLine().trimmed();
        QString dataStr = QString::fromUtf8(data);

        qDebug() << "Données reçues : " << dataStr;

        // Chercher "Température" et extraire la valeur numérique
        if (dataStr.startsWith("Température:")) {
            // Extraire la partie numérique de la température
            QString temperatureStr = dataStr.section(":", 1, 1).trimmed();  // "21.00 C"
            temperatureStr = temperatureStr.split(" ")[0];  // "21.00"
            bool ok;
            float temperature = temperatureStr.toFloat(&ok);  // Convertir en float

            if (ok) {
                // Si la conversion est réussie, émettre un signal avec la température
                emit temperatureChanged(temperature);
            } else {
                qDebug() << "Erreur lors de la conversion de la température.";
            }
        }
    }
}

