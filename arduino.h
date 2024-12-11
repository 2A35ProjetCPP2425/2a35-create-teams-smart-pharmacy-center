#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>

class Arduino : public QObject {
    Q_OBJECT
public:
    explicit Arduino(QObject *parent = nullptr);
    ~Arduino();

    bool connectArduino();    // Connecter Arduino
    void disconnectArduino(); // Déconnecter Arduino
    QString readData();       // Lire les données

private:
    QSerialPort *serial;      // Port série
    QString portName;         // Nom du port
    int baudRate;             // Baudrate
};

#endif // ARDUINO_H
