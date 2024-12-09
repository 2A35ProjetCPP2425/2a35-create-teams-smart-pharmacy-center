#include "dialog.h"
#include "personel.h"
#include "qthread.h"
#include "qtimer.h"
#include "ui_dialog.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QVariant>
#include "dialog.h"
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    serial(new QSerialPort(this))
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &Dialog::on_loginButton_clicked);

    // Initialiser la fonction de connexion à l'application
    connecttoapp();

    // Set up the serial port for communication with Arduino
    setupSerial();
}

Dialog::~Dialog()
{
    delete ui;
    if (serial->isOpen()) {
        serial->close();
    }
}

void Dialog::setupSerial() {
    // Trouver et ouvrir le premier port série disponible
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.hasVendorIdentifier() && info.hasProductIdentifier()) {
            serial->setPort(info);
            if (serial->open(QIODevice::ReadWrite)) {
                qDebug() << "Serial port opened: " << info.portName();
                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);
                break;
            }
        }
    }
}

void Dialog::on_loginButton_clicked()
{
    QString identifiant = ui->id->text().trimmed();
    QString mdp = ui->password->text().trimmed();

    qDebug() << "Identifiant:" << identifiant;
    qDebug() << "Mot de passe:" << mdp;

    if (identifiant.isEmpty()) {
        showError("Identifiant is empty.");
        return;
    }

    if (mdp.isEmpty()) {
        showError("Password is empty.");
        return;
    }

    // Instancier un objet Personel pour valider les informations d'identification
    Personel emp;
    bool loginSuccess = emp.getemployeemailpassword(identifiant, mdp);
    qDebug() << "Mot de passe:" << mdp;

    if (loginSuccess) {
        // Connexion réussie
        QString welcomeMessage = getEmployeName();
        if (!welcomeMessage.isEmpty()) {
            showSuccess(welcomeMessage);

            // Vérifier si l'utilisateur est le manager ou si l'identifiant est 1
            int userId = getUserId(identifiant);  // Récupérer l'ID de l'utilisateur
            if (userId == 1) {
                // Envoi de 4 bips de 250 ms, avec un délai de 100 ms entre chaque bip
                activateMultipleBuzzerBeep();
            } else {
                // Envoi d'un bip court pour la connexion réussie (0.5 seconde)
                activateBuzzer(500);
            }

            // Fermer la fenêtre après 1 seconde
            QTimer::singleShot(1000, this, &Dialog::accept);
        } else {
            showError("Failed to retrieve user name.");
        }
    } else {
        // Connexion échouée
        showError("Incorrect username or password.");
        // Envoi d'un bip long pour la connexion échouée (2 secondes)
        activateBuzzer(2000);
    }
}

void Dialog::activateBuzzer(int durationMs)
{
    if (serial->isOpen()) {
        // Envoyer la durée au Arduino sous forme de chaîne avec un caractère de nouvelle ligne
        serial->write(QString::number(durationMs).toUtf8() + "\n");
    } else {
        qDebug() << "Serial port is not open.";
    }
}

void Dialog::activateMultipleBuzzerBeep()
{
    if (serial->isOpen()) {

        for (int i = 0; i < 2; ++i) {
        serial->write(QString::number(250).toUtf8() + "\n");
            QThread::msleep(300); // Attendre un peu entre chaque bip
        }
    } else {
        qDebug() << "Serial port is not open.";
    }
}

QString Dialog::getEmployeName()
{
    QString userName;
    QString login = ui->id->text();  // Récupère l'email (ID) de l'utilisateur

    qDebug() << "Login input:" << login;

    QSqlQuery query;
    query.prepare("SELECT nom FROM personnels WHERE id_personnel = :login");
    query.bindValue(":login", login);

    if (query.exec()) {
        if (query.next()) {
            userName = query.value("nom").toString();
        } else {
            qDebug() << "No user found with the provided ID.";
            return "Aucun utilisateur trouvé avec cet ID.";
        }
    } else {
        qDebug() << "Database query failed:" << query.lastError().text();
        return "Erreur lors de la récupération des données.";
    }

    QString welcomeMessage = "Bienvenue " + userName + " dans notre application!";
    qDebug() << "Welcome message:" << welcomeMessage;
    return welcomeMessage;
}

QString Dialog::getEmail() const {
    return ui->id->text();  // Retourne l'email saisi dans le QLineEdit
}

int Dialog::getUserId(const QString &identifiant) const {
    // Récupérer l'ID de l'utilisateur depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT id_personnel FROM personnels WHERE id_personnel = :identifiant");
    query.bindValue(":identifiant", identifiant);

    if (query.exec()) {
        if (query.next()) {
            return query.value("id_personnel").toInt();  // Retourne l'ID de l'utilisateur
        }
    }

    return -1;  // Retourne -1 si l'utilisateur n'est pas trouvé
}

void Dialog::showError(const QString &message)
{
    ui->label_3->setText(message);
    ui->label_3->setStyleSheet("color: red;");
}

void Dialog::showSuccess(const QString &message)
{
    ui->label_3->setText(message);
    ui->label_3->setStyleSheet("color: green;");
}

void Dialog::connecttoapp() {
    // Code pour se connecter à l'application ou pour initialiser des configurations
    qDebug() << "Connecting to application...";
}

