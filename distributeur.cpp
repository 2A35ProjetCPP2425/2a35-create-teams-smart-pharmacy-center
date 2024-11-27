#include "distributeur.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// Constructeur par défaut
Distributeur::Distributeur() {
    idd = 0;
    nom = "";

}

// Constructeur paramétré
Distributeur::Distributeur(int idd, QString nom,float distance ) {
    this->idd = idd;
    this->nom = nom;
    this->distance = distance;

}

// Accesseurs
int Distributeur::getIdd() const { return idd; }
QString Distributeur::getnom() const { return nom; }
float Distributeur::getdistance() const { return distance; }

// Ajouter un nouveau distributeur
bool Distributeur::ajouterr() {
    QSqlQuery query;
    query.prepare("INSERT INTO DISTRIBUTEUR (IDD, NOM, DISTANCE) VALUES (:IDD, :NOM, :DISTANCE)");

    query.bindValue(":IDD", idd);
    query.bindValue(":NOM", nom);
    query.bindValue(":DISTANCE", distance);

    return query.exec();
}

// Méthode pour vérifier si un nom de distributeur existe déjà
bool Distributeur::nomExiste(QString nom) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM DISTRIBUTEUR WHERE NOM = :nom");
    query.bindValue(":nom", nom);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0; // Retourne vrai si le nom existe
    }

    return false; // En cas d'erreur ou si le nom n'existe pas
}

// Afficher les distributeurs
QSqlTableModel* Distributeur::afficher1()
{
    // Créer un modèle QSqlTableModel
    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("DISTRIBUTEUR");  // Spécifier la table
    model->select();  // Sélectionner toutes les lignes

    // Facultatif : définir les en-têtes de colonne si nécessaire
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DISTANCE"));

    return model;  // Retourner le modèle avec les données
}

bool Distributeur::supprimer1(int idd)
{
    QSqlQuery query;
    QString res = QString::number(idd);
    query.prepare("DELETE FROM DISTRIBUTEUR WHERE IDD = :idd");
    query.bindValue(":idd", res);
    return query.exec();
}

bool Distributeur::modifier1(int idd, QString nom, float distance)
{
    QSqlQuery query;
    query.prepare("UPDATE DISTRIBUTEUR SET  distance = :distance WHERE idd = :idd");
    query.bindValue(":nom",nom);
    query.bindValue(":idd", idd);
    query.bindValue(":distance", distance);

    if (query.exec()) {
        // Si la mise à jour réussit, on recharge les données pour refléter la modification
        return true;
    } else {
        return false;
    }
}

QStringList Distributeur::obtenirNomsDistributeurs() {
    QStringList noms;
    QSqlQuery query("SELECT NOM FROM DISTRIBUTEUR");

    while (query.next()) {
        noms << query.value(0).toString(); // Ajouter le nom dans la liste
    }

    return noms;
}

