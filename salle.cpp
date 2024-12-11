#include "salle.h"
#include "QSqlError"


salle::salle(int ns, QString nsl, QString s) {
    this->num_salle = ns;
    this->nom_salle = nsl;
    this->statut = s;
}

// Définition du constructeur par défaut
salle::salle() {
    num_salle = 0;
    nom_salle = "";
    statut = "";
}


QSqlQueryModel* salle::afficher() {
    QSqlQueryModel* modelSalle = new QSqlQueryModel();
    modelSalle->setQuery("SELECT * FROM salle");

    if (modelSalle->lastError().isValid()) {
        qDebug() << "Erreur lors de la requête d'affichage des salles :"
                 << modelSalle->lastError().text();
    }

    return modelSalle;
}
