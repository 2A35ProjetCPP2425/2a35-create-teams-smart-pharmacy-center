#include "connexion.h"

Connection::Connection() {}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Pharmadesk");//inserer le nom de la source de données
    db.setUserName("BASE");//inserer nom de l'utilisateur
    db.setPassword("Pharmadesk 2025");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
