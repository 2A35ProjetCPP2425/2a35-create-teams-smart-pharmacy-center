#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "distributeur.h"

class Arduino : public QObject {
    Q_OBJECT

public:
    explicit Arduino(QObject *parent = nullptr);  // Constructeur
    void startCommunication();
signals:
    void temperatureChanged(float temperature);        // Démarrer la communication série

private slots:
    void readSerialData();                        // Lire les données reçues du port série

private:
    QSerialPort *serial;                          // Instance du port série
};

#endif // ARDUINO_H
