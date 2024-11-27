#ifndef DISTRIBUTEUR_H
#define DISTRIBUTEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
class Distributeur {
public:
    Distributeur();
    Distributeur(int idd, QString nom,float distance);
    int getIdd() const;
    QString getnom() const;
    float getdistance() const;

    // Méthodes pour la gestion des distributions
    bool ajouterr();
    QSqlTableModel* afficher1();
    bool supprimer1(int idd);
    bool modifier1(int idd, QString nom, float distance);
    bool idExiste(int idd);
    bool nomExiste(QString nom);
    QStringList obtenirNomsDistributeurs();

private:
    int idd;
    QString nom;
    float distance;


};

#endif // DISTRIBUTION_H
