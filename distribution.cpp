#include "distribution.h"
#include <QDebug>
#include "QSqlQuery"
#include <QFileDialog>
#include <QPdfWriter>
#include <QPageSize>
#include <QTextDocument>
#include <QTextCursor>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlError>
#include <QVector>
#include <QPair>
Distribution::Distribution() {
    id = 0;
    qte = 0;
    aboratoire = "";
    dated = QDate(2023, 2, 1);  // Exemple de date par défaut
    medist = 0;
}

Distribution::Distribution(int id, int qte, QString aboratoire, QDate dated, int medist) {
    this->id = id;
    this->qte = qte;
    this->aboratoire = aboratoire;
    this->dated = dated;
    this->medist = medist;
}

// Accesseurs
int Distribution::getId() const { return id; }
int Distribution::getQte() const { return qte; }
QString Distribution::getaboratoire() const { return aboratoire; }
QDate Distribution::getDated() const { return dated; }
int Distribution::getMedist() const { return medist; }

// Ajouter une nouvelle distribution

bool Distribution::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO DISTRIBUTION (ID, QTE, ABORATOIRE, DATED, MEDIST) "
                  "VALUES (:ID, :QTE, :ABORATOIRE, :DATED, :MEDIST)");

    query.bindValue(":ID", id);
    query.bindValue(":QTE", qte);
    query.bindValue(":ABORATOIRE", aboratoire);
    query.bindValue(":DATED", dated);
    query.bindValue(":MEDIST", medist);

    return query.exec();
}

// Méthode pour obtenir le nombre de distributions par laboratoire
QMap<QString, int> Distribution::obtenirNombreDeDistributions() {
    QMap<QString, int> countMap;

    QSqlQuery query("SELECT ABORATOIRE, COUNT(*) as count FROM DISTRIBUTION GROUP BY ABORATOIRE");

    while (query.next()) {
        QString aboratoire = query.value("ABORATOIRE").toString();
        int count = query.value("count").toInt();

        countMap[aboratoire] = count;
    }

    return countMap;
}

bool Distribution::idExiste(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM distribution WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        if (query.next()) {
            int count = query.value(0).toInt();
            return (count > 0); // Retourne true si l'ID existe
        }
    }
    return false; // En cas d'erreur ou si l'ID n'existe pas
}

// Afficher les distributions
QSqlTableModel* Distribution::afficher()
{
    // Créer un modèle QSqlTableModel
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("DISTRIBUTION");  // Spécifier la table
    model->select();  // Sélectionner toutes les lignes
    // Facultatif : définir les en-têtes de colonne si nécessaire
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ABORATOIRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATED"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MEDIST"));
    return model;  // Retourner le modèle avec les données
}

bool Distribution::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM DISTRIBUTION WHERE ID = :id");
    query.bindValue(":id", res);
    return query.exec();
}

bool Distribution::modifier(int id, int qte)
{
    QSqlQuery query;
    query.prepare("UPDATE distribution SET qte = :qte, dated = :dated WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":qte", qte);
   // query.bindValue(":aboratoire", aboratoire);
    query.bindValue(":dated", dated);

    if (query.exec()) {
        // Si la mise à jour réussit, on recharge les données pour refléter la modification
        return true;
    } else {
        return false;
    }
}

QSqlQueryModel* Distribution::rech(int id, const QString& aboratoire, int qte)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    // Construire la requête avec les filtres sur id, aboratoire et qte
    QString queryString = "SELECT * FROM DISTRIBUTION WHERE 1=1"; // Base de la requête

    if (id != 0) {
        queryString += " AND ID = :ID"; // Ajouter la condition pour l'ID si non nul
    }
    if (!aboratoire.isEmpty()) {
        queryString += " AND ABORATOIRE = :ABORATOIRE"; // Ajouter la condition pour l'aboratoire
    }
    if (qte != 0) {
        queryString += " AND QTE = :QTE"; // Ajouter la condition pour la quantité
    }
    query.prepare(queryString); // Préparer la requête
    // Lier les valeurs des paramètres si elles sont non nulles
    if (id != 0) {
        query.bindValue(":ID", id);
    }
    if (!aboratoire.isEmpty()) {
        query.bindValue(":ABORATOIRE", aboratoire);
    }
    if (qte != 0) {
        query.bindValue(":QTE", qte);
    }
    query.exec(); // Exécuter la requête
    model->setQuery(query); // Appliquer la requête au modèle
    return model; // Retourner le modèle avec les résultats
}
QSqlQueryModel* Distribution::trierById() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM DISTRIBUTION ORDER BY ID");
    return model;
}

QSqlQueryModel* Distribution::trierByQte() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM DISTRIBUTION ORDER BY QTE");
    return model;
}

QSqlQueryModel* Distribution::trierByAboratoire() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM DISTRIBUTION ORDER BY ABORATOIRE");
    return model;
}

QSqlQueryModel* Distribution::trierByDate() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM DISTRIBUTION ORDER BY DATED");
    return model;
}

QStandardItemModel* Distribution::statistiquesParMedist() {
    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"ID Médicament", "Total Quantité"});

    QSqlQuery query;
    // Requête pour grouper par 'medist' et trier par quantité totale
    query.prepare("SELECT medist, SUM(qte) AS total_qte FROM distribution GROUP BY medist ORDER BY total_qte DESC");

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            int medist = query.value("medist").toInt();       // Récupère l'ID du médicament
            int totalQte = query.value("total_qte").toInt(); // Récupère la quantité totale

            model->setItem(row, 0, new QStandardItem(QString::number(medist)));
            model->setItem(row, 1, new QStandardItem(QString::number(totalQte)));
            row++;
        }
    } else {
        qWarning() << "Erreur statistiquesParMedist :" << query.lastError().text();
    }

    return model;
}
