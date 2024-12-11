#include "rendezvous.h"
#include "QSqlError"
#include "QMessageBox"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDateTime>
#include <QTime>
#include <QSqlDatabase>  // Ajouté pour s'assurer que la base de données est incluse
#include <QSqlError>     // Ajouté pour capturer les erreurs de la requête SQL

// Constructeur
rendezvous::rendezvous(int num, QString nc, QString n, QDate d, QDateTime h)
    : num_rendezvous(num), nom_client(nc), nom_service(n), date_rendezvous(d), heure_rendezvous(h) {}

// Définition du constructeur par défaut
rendezvous::rendezvous()
    : num_rendezvous(0), nom_client(""), nom_service(""), date_rendezvous(QDate::currentDate()), heure_rendezvous(QDateTime::currentDateTime()) {}

// Méthode pour ajouter un rendez-vous
bool rendezvous::ajouter() {
    // Vérifie le stock en fonction du service
    QSqlQuery checkQuery;  // Vérification de l'existence de la table et de la requête
    QString medicament = "";
    if (nom_service == "injection") {
        medicament = "seringues";
    } else if (nom_service == "test covid") {
        medicament = "test covid";
    } else if (nom_service == "piercing") {
        medicament = "piercing";
    } else {
        QMessageBox::warning(nullptr, "Service non géré", "Le service spécifié ne nécessite pas de vérification de stock.");
        return false;
    }

    // Exécute la requête de vérification du stock
    checkQuery.prepare("SELECT stock FROM medicament WHERE nom_medicament = :medicament");
    checkQuery.bindValue(":medicament", medicament);

    if (checkQuery.exec()) {
        if (checkQuery.next()) {
            int stock = checkQuery.value(0).toInt();
            if (stock > 0) {
                // Stock disponible, ajoute le rendez-vous
                QSqlQuery query;
                query.prepare("INSERT INTO rendezvous (num_rendezvous, nom_client, nom_service, date_rendezvous, heure_rendezvous) "
                              "VALUES (:num_rendezvous, :nom_client, :nom_service, :date_rendezvous, :heure_rendezvous)");
                query.bindValue(":num_rendezvous", num_rendezvous);
                query.bindValue(":nom_client", nom_client);
                query.bindValue(":nom_service", nom_service);
                query.bindValue(":date_rendezvous", date_rendezvous);
                query.bindValue(":heure_rendezvous", heure_rendezvous);

                if (query.exec()) {
                    return true;
                } else {
                    QMessageBox::warning(nullptr, "Erreur d'insertion", query.lastError().text());
                    return false;
                }
            } else {
                QMessageBox::warning(nullptr, "Stock insuffisant", "Le stock du médicament requis est insuffisant.");
                return false;
            }
        } else {
            QMessageBox::warning(nullptr, "Erreur de vérification", "Impossible de vérifier le stock du médicament.");
            return false;
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur de requête", checkQuery.lastError().text());
        return false;
    }

    return false;
}

// Afficher tous les rendez-vous
QSqlQueryModel* rendezvous::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Exécution de la requête pour récupérer tous les rendez-vous
    query.prepare("SELECT * FROM rendezvous");
    query.exec();

    model->setQuery(query);

    return model;
}

// Supprimer un rendez-vous
bool rendezvous::supprimer(int num_rendezvous) {
    QSqlQuery query;

    query.prepare("DELETE FROM rendezvous WHERE num_rendezvous = :num_rendezvous");
    query.bindValue(":num_rendezvous", num_rendezvous);

    if (query.exec()) {
        return true;
    } else {
        QMessageBox::warning(nullptr, "Erreur de suppression", query.lastError().text());
        return false;
    }
}

// Modifier un rendez-vous
bool rendezvous::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE rendezvous SET nom_client = :nom_client, nom_service = :nom_service , date_rendezvous = :date_rendezvous , heure_rendezvous= :heure_rendezvous WHERE num_rendezvous = :num_rendezvous");
    query.bindValue(":num_rendezvous", num_rendezvous);
    query.bindValue(":nom_client", nom_client);
    query.bindValue(":nom_service", nom_service);
    query.bindValue(":date_rendezvous", date_rendezvous);
    query.bindValue(":heure_rendezvous", heure_rendezvous);

    return query.exec();
}

// Mettre à jour le statut d'un rendez-vous
bool rendezvous::mettreAJourStatut(int num_rendezvous, const QString &nouveauStatut) {
    QSqlQuery query;
    query.prepare("UPDATE rendezvous SET statut = :statut WHERE num_rendezvous = :num_rendezvous");
    query.bindValue(":statut", nouveauStatut);
    query.bindValue(":num_rendezvous", num_rendezvous);

    if (query.exec()) {
        if (nouveauStatut == "passé") {
            QString service = "";
            QSqlQuery serviceQuery;
            serviceQuery.prepare("SELECT nom_service FROM rendezvous WHERE num_rendezvous = :num_rendezvous");
            serviceQuery.bindValue(":num_rendezvous", num_rendezvous);

            if (serviceQuery.exec() && serviceQuery.next()) {
                service = serviceQuery.value(0).toString();
            } else {
                QMessageBox::warning(nullptr, "Erreur", "Impossible de récupérer le service du rendez-vous.");
                return false;
            }

            if (service == "injection") {
                QSqlQuery stockQuery;
                stockQuery.prepare("UPDATE medicament SET stock = stock - 1 WHERE nom_medicament = 'seringues'");
                if (!stockQuery.exec()) {
                    QMessageBox::warning(nullptr, "Erreur de mise à jour du stock", stockQuery.lastError().text());
                    return false;
                }
            } else if (service == "test covid") {
                QSqlQuery stockQuery;
                stockQuery.prepare("UPDATE medicament SET stock = stock - 1 WHERE nom_medicament = 'test covid'");
                if (!stockQuery.exec()) {
                    QMessageBox::warning(nullptr, "Erreur de mise à jour du stock", stockQuery.lastError().text());
                    return false;
                }
            } else if (service == "piercing") {
                QSqlQuery stockQuery;
                stockQuery.prepare("UPDATE medicament SET stock = stock - 1 WHERE nom_medicament = 'piercing'");
                if (!stockQuery.exec()) {
                    QMessageBox::warning(nullptr, "Erreur de mise à jour du stock", stockQuery.lastError().text());
                    return false;
                }
            }
        }
        return true;
    } else {
        QMessageBox::warning(nullptr, "Erreur de mise à jour", query.lastError().text());
        return false;
    }
}


