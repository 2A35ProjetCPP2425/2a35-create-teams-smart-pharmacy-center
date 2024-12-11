#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQueryModel>

class Client {
public:
    // Constructors
    Client();
    Client(int clientId, const QString &nom, const QString &email, const QString &telephone, const QDate &dateCreation);
    bool clientExists(int clientId);
    // Getters and Setters
    int getClientId() const;
    void setClientId(int clientId);

    QString getNom() const;
    void setNom(const QString &nom);

    QString getEmail() const;
    void setEmail(const QString &email);

    QString getTelephone() const;
    void setTelephone(const QString &telephone);

    QDate getDateCreation() const;
    void setDateCreation(const QDate &dateCreation);

    // Database Operations (Static Methods)
    static bool connectDatabase();
    static bool insertClient(const Client &client);
    static bool updateClient(const Client &client);
    static bool deleteClient(int clientId);

    static QSqlQueryModel* getAllClients();
    static QSqlQueryModel* searchClients(const QString &name);
    static QSqlQueryModel* sortClients(const QString &column);
    static QSqlQueryModel* getSortedClientsById();
    static QSqlQueryModel* getSortedClientsByName();
    static int getNumberOfClients();
    static Client getClientById(int clientId);
    static Client getMostLoyalClient();



private:
    // Attributes of the Client
    int clientId;
    QString nom;
    QString email;
    QString telephone;
    QDate dateCreation;

    static QSqlDatabase db; // Static database connection object
};

#endif // CLIENT_H
