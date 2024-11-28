#include "connexion.h"
#include <QDebug>
#include <QSqlError>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("CPP.Project"); // Insert the data source name (DSN)
    db.setUserName("taherr");          // Insert username
    db.setPassword("oracle");          // Insert password

    if (!db.open()) {  // Explicitly try to open the database
        qDebug() << "Database connection error:" << db.lastError().text();
    } else {
        qDebug() << "Connection successful!";
        test = true;
    }

    return test;
}
