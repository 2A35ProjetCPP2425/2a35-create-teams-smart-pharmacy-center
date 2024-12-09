<<<<<<< HEAD
#include "connection.h"
=======
/*#include "connection.h"
>>>>>>> 8fb8c24 (Deuxieme commit)
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;  // This creates an instance of the Connection class

    bool test = c.connection();  // Use the connection method on the instance
    if(test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}

<<<<<<< HEAD
=======
*/
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "arduino.h"  // Inclure la classe Arduino

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;  // Instance de la classe Connection
    Arduino arduino; // Instance de la classe Arduino pour la communication série

    // Établir la connexion à la base de données
    bool test = c.connection();
    if (test) {
        w.show();

        // Message de confirmation pour la base de données
        QMessageBox::information(nullptr, QObject::tr("Database Opened"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        // Démarrer la communication avec l'Arduino
        arduino.startCommunication();
    } else {
        // Message d'erreur si la base de données ne s'ouvre pas
        QMessageBox::critical(nullptr, QObject::tr("Database Not Opened"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
>>>>>>> 8fb8c24 (Deuxieme commit)
