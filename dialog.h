#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void activateMultipleBuzzerBeep();

private slots:
    void on_loginButton_clicked();  // Slot pour le bouton de connexion

private:
    Ui::Dialog *ui;

    // Méthodes pour gérer la connexion à l'Arduino et à la base de données
    void setupSerial();
    void sendToArduino(int id);
    void activateBuzzer(int durationMs);

    void showError(const QString &message);
    void showSuccess(const QString &message);
    QString getEmployeName();
    QString getEmail() const;
    QString getUserPosition() const;

    // Nouvelle méthode pour récupérer l'ID de l'utilisateur en fonction de l'identifiant
    int getUserId(const QString &identifiant) const;

    // Objet pour gérer la communication série avec l'Arduino
    QSerialPort *serial;

    // Méthode pour établir la connexion à l'application
    void connecttoapp();
};

#endif // DIALOG_H
