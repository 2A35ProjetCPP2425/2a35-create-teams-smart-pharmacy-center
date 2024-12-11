#include "service.h"

service::service(QString n, QString d, float ps) {
    this->nom_service = n;
    this->description = d;
    this->prix_service = ps;
}

bool service::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO Service (nom_service, description, prix_service) "
                  "VALUES (:nom_service, :description, :prix_service)");
    query.bindValue(":nom_service", nom_service);
    query.bindValue(":description", description);
    query.bindValue(":prix_service", prix_service);

    return query.exec();
}

QSqlQueryModel* service::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Service");

    return model;
}

bool service::supprimer(QString nom_service) {
    QSqlQuery query;
    query.prepare("DELETE FROM Service WHERE nom_service = :nom_service");
    query.bindValue(":nom_service", nom_service);

    return query.exec();  // Exécute la requête et retourne `true` si la suppression réussit, sinon `false`
}

bool service::modifier() {  // Implémentation de la méthode modifier
    QSqlQuery query;
    query.prepare("UPDATE Service SET description = :description, prix_service = :prix_service WHERE nom_service = :nom_service");
    query.bindValue(":nom_service", nom_service);
    query.bindValue(":description", description);
    query.bindValue(":prix_service", prix_service);

    return query.exec();  // Exécute la requête et retourne `true` si la modification réussit, sinon `false`
}
