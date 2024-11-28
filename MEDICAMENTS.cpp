#include "MEDICAMENTS.h"
#include "qsqlerror.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QMessageBox>

#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

MEDICAMENTS::MEDICAMENTS() {
    ID = 0;
    QTESTOCK = 0;
    CATEGORIE = "";
    NOM = "";
    DATDEXP = QDate();
    PRIX = 0;
}

void MEDICAMENTS::fset(int ID, int QTESTOCK, QString CATEGORIE, QDate DATDEXP, QString NOM, float PRIX) {
    this->ID = ID;
    this->QTESTOCK = QTESTOCK;
    this->CATEGORIE = CATEGORIE;
    this->DATDEXP = DATDEXP;
    this->NOM = NOM;
    this->PRIX = PRIX;
}

bool MEDICAMENTS::ajout() {
    QSqlQuery query;
    query.prepare("INSERT INTO MEDICAMENTS (ID, NOM, DATDEXP, QTESTOCK, PRIX, CATEGORIE) "
                  "VALUES (:ID, :NOM, :DATDEXP, :QTESTOCK, :PRIX, :CATEGORIE)");
    query.bindValue(":ID", ID);
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATDEXP", DATDEXP);
    query.bindValue(":QTESTOCK", QTESTOCK);
    query.bindValue(":PRIX", PRIX);
    query.bindValue(":CATEGORIE", CATEGORIE);

    return query.exec();
}

bool MEDICAMENTS::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE MEDICAMENTS SET NOM = :NOM, DATDEXP = :DATDEXP, QTESTOCK = :QTESTOCK, PRIX = :PRIX, CATEGORIE = :CATEGORIE WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATDEXP", DATDEXP);
    query.bindValue(":QTESTOCK", QTESTOCK);
    query.bindValue(":PRIX", PRIX);
    query.bindValue(":CATEGORIE", CATEGORIE);

    return query.exec();
}

bool MEDICAMENTS::supprimer() {
    QSqlQuery query;
    query.prepare("DELETE FROM MEDICAMENTS WHERE ID = :ID");
    query.bindValue(":ID", ID);

    return query.exec();
}

QSqlQueryModel* MEDICAMENTS::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDICAMENTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATDEXP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QTESTOCK"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CATEGORIE"));

    return model;
}
bool MEDICAMENTS::existe() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM MEDICAMENTS WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if (query.exec()) {
        query.next();
        int count = query.value(0).toInt();
        return count > 0;  // Si le count est supérieur à 0, l'ID existe
    }
    return false;  // Si la requête échoue ou que l'ID n'existe pas
}
// Trier par ID (ascendant)
QSqlQueryModel* MEDICAMENTS::trierParID() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDICAMENTS ORDER BY ID ASC");  // Tri ascendant par ID
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATDEXP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QTESTOCK"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CATEGORIE"));

    return model;
}

// Trier par NOM (alphabétique)
QSqlQueryModel* MEDICAMENTS::trierParNom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDICAMENTS ORDER BY NOM ASC");  // Tri alphabétique par NOM
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATDEXP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QTESTOCK"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CATEGORIE"));

    return model;
}
QSqlQueryModel* MEDICAMENTS::statistiquesParCategorie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // SQL pour obtenir les statistiques par catégorie
    QString queryStr = "SELECT CATEGORIE, "
                       "COUNT(ID) AS NbMeds, "
                       "SUM(QTESTOCK) AS TotalStock, "
                       "SUM(PRIX) AS TotalPrix "
                       "FROM MEDICAMENTS "
                       "GROUP BY CATEGORIE";

    // Exécution de la requête SQL
    model->setQuery(queryStr);

    // Définition des noms des colonnes pour l'affichage
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Catégorie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de Médicaments"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Total Prix"));

    return model;
}
QSqlQueryModel* MEDICAMENTS::rechercheParID(int idRecherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Requête SQL pour rechercher un médicament par ID
    QString queryStr = "SELECT * FROM MEDICAMENTS WHERE ID = :id";
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":id", idRecherche); // Recherche par l'ID exact

    // Exécution de la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche par ID: " << query.lastError();
        return nullptr;
    }

    // Affecter le résultat de la requête au modèle
    model->setQuery(query);

    // Définir les en-têtes des colonnes pour l'affichage dans la QTableView
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date d'expiration"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité en stock"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Catégorie"));

    return model;
}
bool MEDICAMENTS::consommer(int id, int quantiteConsommee)
{
    QSqlQuery query;

// Vérifier si le médicament existe et récupérer ses informations
query.prepare("SELECT QTESTOCK, DATDEXP FROM MEDICAMENTS WHERE ID = :id");
query.bindValue(":id", id);

if (!query.exec()) {
    qDebug() << "Erreur lors de la récupération des informations : " << query.lastError();
    return false;
}

// Si le médicament existe, récupérer la quantité en stock et la date d'expiration
if (query.next()) {
    int qteActuelle = query.value(0).toInt();  // Quantité en stock
    QDate dateExpiration = query.value(1).toDate();  // Date d'expiration

    // Vérifier si la date d'expiration est dépassée
    if (dateExpiration < QDate::currentDate()) {
        QMessageBox::warning(nullptr, "Alerte Péremption",
                             "Le médicament est périmé ! Veuillez vérifier avant de procéder.");
        return false; // Annuler la consommation si le médicament est périmé
    }

    // Vérifier si la quantité demandée est valide
    if (quantiteConsommee <= 0) {
        qDebug() << "La quantité à consommer doit être supérieure à zéro.";
        return false;
    }

    if (quantiteConsommee > qteActuelle) {
        qDebug() << "Quantité demandée supérieure à la quantité en stock.";
        return false;
    }

    // Mise à jour de la quantité en stock
    int nouvelleQte = qteActuelle - quantiteConsommee;
    query.prepare("UPDATE MEDICAMENTS SET QTESTOCK = :qte WHERE ID = :id");
    query.bindValue(":qte", nouvelleQte);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour de la quantité : " << query.lastError();
        return false;
    }

    // Retourner true si la mise à jour a réussi
    return true;
}

// Si le médicament n'existe pas
qDebug() << "Médicament introuvable.";
return false;
 }
bool MEDICAMENTS::ajouterQuantite(int id, int quantiteAjoutee)
{
    QSqlQuery query;

    // Vérifier d'abord si le médicament existe et récupérer la quantité en stock
    query.prepare("SELECT QTESTOCK FROM MEDICAMENTS WHERE ID = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération de la quantité : " << query.lastError();
        return false;
    }

    // Si le médicament existe, récupérer la quantité en stock actuelle
    if (query.next()) {
        int qteActuelle = query.value(0).toInt();

        // Ajouter la quantité au stock actuel
        int nouvelleQte = qteActuelle + quantiteAjoutee;
        query.prepare("UPDATE MEDICAMENTS SET QTESTOCK = :qte WHERE ID = :id");
        query.bindValue(":qte", nouvelleQte);
        query.bindValue(":id", id);

        if (!query.exec()) {
            qDebug() << "Erreur lors de la mise à jour de la quantité : " << query.lastError();
            return false;
        }

        // Retourner true si la mise à jour a réussi
        return true;
    }

    // Si le médicament n'existe pas
    qDebug() << "Médicament introuvable.";
    return false;
}
