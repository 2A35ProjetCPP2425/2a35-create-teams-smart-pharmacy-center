    #include "connection.h"
#include <QDebug>
#include <QSqlError>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Distrubution");
    db.setUserName("Yota");
    db.setPassword("oracle");
}

bool Connection::connection() {
    if (!db.open()) {
        qDebug() << "Connection failed:" << db.lastError().text();
        return false;
    }
    qDebug() << "Connection successful!";
    return true;
}

void Connection::closeConnection() {
    db.close();
    qDebug() << "Database connection closed.";
}
