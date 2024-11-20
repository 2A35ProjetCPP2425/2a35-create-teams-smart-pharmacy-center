#ifndef GESTION_ACHAT_H
#define GESTION_ACHAT_H
#include "qdatetime.h"
#include <qstring.h>
#include <QSqlQuery>
#include <QSqlQueryModel>

class gestion_achat
{
    int id_achat;
    QString nom;
    QString nouveauNom;
    int quantite;
    int nouvelleQuantite;
    float prix;
    float nouveauPrix;
    QDate date_achat;
    int id_perso;


public:
    gestion_achat(){};
    gestion_achat(int,QString,int,float,QDate,int);

    int getid_achat(){return id_achat;};
    QString getnom (){return nom;};
    int getquantite(){return quantite;};
    float getprix(){return prix;};
    QDate getdate_achat(){return date_achat;};
    int getid_perso(){return id_perso;};

    void setid_ahat(int id){id_achat=id;}
    void setnom(QString n){nom=n;}
    void setquantite(int q){quantite=q;}
    void setprix(float prixa){prix=prixa;}
    void setdate_achat( QDate datea){date_achat=datea;}
    void setid_perso(int id_p){id_perso=id_p;}





    bool ajouter ();
    QSqlQueryModel * afficher ();
    bool supprimer (int id_achat);
    bool modifier(int id_achat, const QString& nom, int quantite, float prix, QDate &date_achat, int id_perso);
};

#endif // GESTION_ACHAT_H
