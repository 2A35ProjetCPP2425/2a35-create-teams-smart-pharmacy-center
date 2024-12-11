#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class salle
{
private:
    int num_salle;
    QString nom_salle,statut;


public:
    // Constructeurs
    salle();  // Constructeur par défaut
    salle(int num_salle, QString nom_salle, QString statut);

    // Getters
    int getNum_salle() { return num_salle; }
    QString getNomsalle() { return nom_salle; }
    QString getStatut() { return statut; }

    // Setters
    void setNum_salle(int ns) { num_salle = ns; }
    void setNom_salle(QString nsl) { nom_salle = nsl; }
    void setStatut(QString s) { statut = s; }


    // Méthodes

    QSqlQueryModel * afficher ();


};


#endif // SALLE_H
