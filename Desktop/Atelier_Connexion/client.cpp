#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// Static member initialization
QSqlDatabase Client::db = QSqlDatabase();

Client::Client() : clientId(0) {}

Client::Client(int clientId, const QString &nom, const QString &email, const QString &telephone, const QDate &dateCreation)
    : clientId(clientId), nom(nom), email(email), telephone(telephone), dateCreation(dateCreation) {}

int Client::getClientId() const { return clientId; }
void Client::setClientId(int clientId) { this->clientId = clientId; }

QString Client::getNom() const { return nom; }
void Client::setNom(const QString &nom) { this->nom = nom; }

QString Client::getEmail() const { return email; }
void Client::setEmail(const QString &email) { this->email = email; }

QString Client::getTelephone() const { return telephone; }
void Client::setTelephone(const QString &telephone) { this->telephone = telephone; }

QDate Client::getDateCreation() const { return dateCreation; }
void Client::setDateCreation(const QDate &dateCreation) { this->dateCreation = dateCreation; }


bool Client::insertClient(const Client &client) {
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTS (CLIENT_ID, NOM, EMAIL, TELEPHONE, DATE_CREATION) "
                  "VALUES (:clientId, :nom, :email, :telephone, :dateCreation)");
    query.bindValue(":clientId", client.getClientId());
    query.bindValue(":nom", client.getNom());
    query.bindValue(":email", client.getEmail());
    query.bindValue(":telephone", client.getTelephone());
    query.bindValue(":dateCreation", client.getDateCreation());

    if (!query.exec()) {
        qDebug() << "Insert failed: " << query.lastError().text();
        return false;
    }
    return true;
}

bool Client::updateClient(const Client &client) {
    QSqlQuery query;
    query.prepare("UPDATE CLIENTS SET NOM = :nom, EMAIL = :email, TELEPHONE = :telephone, "
                  "DATE_CREATION = :dateCreation WHERE CLIENT_ID = :clientId");
    query.bindValue(":clientId", client.getClientId());
    query.bindValue(":nom", client.getNom());
    query.bindValue(":email", client.getEmail());
    query.bindValue(":telephone", client.getTelephone());
    query.bindValue(":dateCreation", client.getDateCreation());

    if (!query.exec()) {
        qDebug() << "Update failed: " << query.lastError().text();
        return false;
    }
    return true;
}

bool Client::deleteClient(int clientId) {
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTS WHERE CLIENT_ID = :clientId");
    query.bindValue(":clientId", clientId);

    if (!query.exec()) {
        qDebug() << "Delete failed: " << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Client::getAllClients() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query("SELECT CLIENT_ID, NOM, EMAIL, TELEPHONE, DATE_CREATION FROM CLIENTS");
    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Error fetching clients: " << model->lastError().text();
    }

    return model;
}

QSqlQueryModel* Client::searchClients(const QString &name) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :name");
    query.bindValue(":name", name);

    // Exécution de la requête
    if (query.exec()) {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);
        return model;
    } else {
        return nullptr;
    }
}

QSqlQueryModel* Client::sortClients(const QString &column) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryString = "SELECT CLIENT_ID, NOM, EMAIL, TELEPHONE, DATE_CREATION FROM CLIENTS ORDER BY " + column;
    model->setQuery(queryString);

    if (model->lastError().isValid()) {
        qDebug() << "Error sorting clients: " << model->lastError().text();
    }

    return model;
}
bool Client::clientExists(int clientId) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM CLIENTS WHERE CLIENT_ID = :clientId");
    query.bindValue(":clientId", clientId);

    if (query.exec()) {
        query.next();
        return query.value(0).toInt() > 0;  // If count is greater than 0, client exists
    } else {
        qDebug() << "Error checking client existence: " << query.lastError().text();
        return false;
    }
}
// In the Client class implementation
QSqlQueryModel* Client::getSortedClientsById() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT CLIENT_ID, NOM, EMAIL, TELEPHONE, DATE_CREATION "
                  "FROM CLIENTS "
                  "ORDER BY CLIENT_ID ASC");  // Sort by CLIENT_ID in ascending order
    query.exec();
    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Error sorting clients by ID: " << model->lastError().text();
    }

    return model;
}

QSqlQueryModel* Client::getSortedClientsByName() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT CLIENT_ID, NOM, EMAIL, TELEPHONE, DATE_CREATION "
                  "FROM CLIENTS "
                  "ORDER BY NOM ASC");  // Sort by NOM in ascending order
    query.exec();
    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Error sorting clients by name: " << model->lastError().text();
    }

    return model;
}
int Client::getNumberOfClients() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM CLIENTS");  // Use COUNT(*) to get the number of rows

    if (query.exec()) {
        query.next();  // Move to the first (and only) result row
        return query.value(0).toInt();  // Return the count as an integer
    } else {
        qDebug() << "Error getting number of clients: " << query.lastError().text();
        return 0;  // Return 0 if there was an error
    }
}
Client Client::getClientById(int clientId) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
    query.bindValue(":id", clientId);
    query.exec();

    if (query.next()) {
        int id = query.value("CLIENT_ID").toInt();
        QString nom = query.value("NOM").toString();
        QString email = query.value("EMAIL").toString();
        QString telephone = query.value("TELEPHONE").toString();
        QDate dateCreation = query.value("DATE_CREATION").toDate();
        return Client(id, nom, email, telephone, dateCreation);
    } else {
        return Client();  // Si le client n'est pas trouvé, retourner un client vide
    }
}
Client Client::getMostLoyalClient()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS ORDER BY DATE_CREATION ASC");

    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL: " << query.lastError().text();  // Afficher l'erreur de la requête
    }

    if (query.next()) {
        int id = query.value("CLIENT_ID").toInt();
        QString nom = query.value("NOM").toString();
        QString email = query.value("EMAIL").toString();
        QString telephone = query.value("TELEPHONE").toString();
        QDate dateCreation = query.value("DATE_CREATION").toDate();

        qDebug() << "Client le plus fidèle trouvé : " << nom;  // Afficher le nom du client trouvé
        return Client(id, nom, email, telephone, dateCreation);
    }

    qDebug() << "Aucun client trouvé";  // Si aucun client n'est trouvé
    return Client();  // Si aucun client fidèle n'est trouvé
}

QString explainSoftware()
{
    // Expliquer le logiciel, en donnant une description détaillée de son objectif et de son fonctionnement
    return "Ce logiciel est un système de gestion des clients. Il permet de gérer les informations des clients, "
           "de rechercher des clients par ID, de voir le nombre total de clients, d'ajouter, supprimer et mettre à jour "
           "les informations des clients. Il est conçu pour aider à organiser et à traiter les données des clients de manière efficace.";
}

