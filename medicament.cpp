#include "medicament.h"
#include "QSqlError"



medicament::medicament(int idm, QString nm, int s) {
    this->id_medicament = idm;
    this->nom_medicament = nm;
    this->stock = s;
}

// Définition du constructeur par défaut
medicament::medicament() {
    id_medicament = 0;
    nom_medicament = "";
    stock = 0;
}


QSqlQueryModel* medicament::afficher() {
    QSqlQueryModel* modelMedicament = new QSqlQueryModel();
    modelMedicament->setQuery("SELECT * FROM medicament");

    if (modelMedicament->lastError().isValid()) {
        qDebug() << "Erreur lors de la requête d'affichage des médicaments :"
                 << modelMedicament->lastError().text();
    }

    return modelMedicament;
}
