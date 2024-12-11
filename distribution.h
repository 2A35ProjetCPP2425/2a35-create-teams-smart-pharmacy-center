#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "qstandarditemmodel.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QVector>
#include <QPair>
#include <QLabel>
class Distribution {
public:
    Distribution();
    Distribution(int id, int qte, QString aboratoire, QDate dated, int medist);
    int getId() const;
    int getQte() const;
    QString getaboratoire() const;
    QDate getDated() const;
    int getMedist() const;

    // Méthodes pour la gestion des distributions
    bool ajouter();
    bool idExiste(int id);
    QSqlTableModel* afficher();
    bool supprimer(int id);
    bool modifier(int id, int qte,QDate dated,int medist);
    // Ajoutez cette signature dans distribution.h
    QSqlQueryModel* rech(int id, const QString& aboratoire, int qte);    // Fonctions de tri par critère
    QSqlQueryModel* trierById();
    QSqlQueryModel* trierByQte();
    QSqlQueryModel* trierByAboratoire();
    QSqlQueryModel* trierByDate();
    //QStandardItemModel* statistiquesParMedist();
    //QSqlQueryModel* getDistributionsParLaboratoire(const QString& nomLaboratoire);
    QMap<QString, int> obtenirNombreDeDistributions();
    QStandardItemModel* statistiquesParMedist();


private:
    int id;
    int qte;
    QString aboratoire;
    QDate dated;
    int medist;
};

#endif // DISTRIBUTION_H
