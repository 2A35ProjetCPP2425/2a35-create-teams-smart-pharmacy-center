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
<<<<<<< HEAD
    Distribution(int id, int qte, QString aboratoire, QDate dated, int medist);
=======
    Distribution(int id, int qte, QString aboratoire, QDate dated, int medist );
>>>>>>> 8fb8c24 (Deuxieme commit)
    int getId() const;
    int getQte() const;
    QString getaboratoire() const;
    QDate getDated() const;
    int getMedist() const;
<<<<<<< HEAD
=======
    //float getTemperature() const;
   // void setTemperature(float temp);
>>>>>>> 8fb8c24 (Deuxieme commit)

    // Méthodes pour la gestion des distributions
    bool ajouter();
    bool idExiste(int id);
    QSqlTableModel* afficher();
    bool supprimer(int id);
<<<<<<< HEAD
    bool modifier(int id, int qte);
    // Ajoutez cette signature dans distribution.h
    QSqlQueryModel* rech(int id, const QString& aboratoire, int qte);
    // Fonctions de tri par critère
=======
    bool modifier(int id, int qte,QDate dated,int medist);
    // Ajoutez cette signature dans distribution.h
    QSqlQueryModel* rech(int id, const QString& aboratoire, int qte);    // Fonctions de tri par critère
>>>>>>> 8fb8c24 (Deuxieme commit)
    QSqlQueryModel* trierById();
    QSqlQueryModel* trierByQte();
    QSqlQueryModel* trierByAboratoire();
    QSqlQueryModel* trierByDate();
<<<<<<< HEAD
    QStandardItemModel* statistiquesParMedist();
    //QSqlQueryModel* getDistributionsParLaboratoire(const QString& nomLaboratoire);
    QMap<QString, int> obtenirNombreDeDistributions();
=======
    //QStandardItemModel* statistiquesParMedist();
    //QSqlQueryModel* getDistributionsParLaboratoire(const QString& nomLaboratoire);
    QMap<QString, int> obtenirNombreDeDistributions();
    QStandardItemModel* statistiquesParMedist();
    bool modifierTemperature(int id, float temperature);
>>>>>>> 8fb8c24 (Deuxieme commit)


private:
    int id;
    int qte;
    QString aboratoire;
    QDate dated;
    int medist;
<<<<<<< HEAD
=======
    //float temperature;
>>>>>>> 8fb8c24 (Deuxieme commit)
};

#endif // DISTRIBUTION_H
