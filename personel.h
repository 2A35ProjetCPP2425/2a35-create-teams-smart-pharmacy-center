#ifndef PERSONEL_H
#define PERSONEL_H
#include "qdatetime.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Personel
{
private:
    int id_personnel;
    float salaire;
    QString nom;
    QString prenom,email,poste,mdp,sexe;


public:
    Personel();
    Personel(int,float,QString,QString,QString,QString,QString,QString,QDate);
    int generateIdentifiant();
    QString generateNumericPassword();
    QDate dateembauche;
    bool idExists(QString id);
    bool supprimer(QString id_p);






    int getid_personel(){return id_personnel;}
    float getsalaire(){return salaire;}
    QString getnom (){return nom;};
    QString getprenom(){return prenom;};
    QString getemail(){return email;};
    QString getposte(){return poste;};
    QString getmdp(){return mdp;};
    QString getsexe(){return sexe;};






    void setidpersonnel(int id){id_personnel=id;}
    void setsalaire(int sal){salaire=sal;}
    void setnom(QString n){nom=n;}
    void setprenom(QString pre){prenom=pre;}
    void setemail(QString mail ){email=mail;}
    void setposte( QString post){poste=post;}
    void setsexe(QString sex){sexe=sex;}
    void setmdp(QString pass){mdp=pass;}





    bool ajouter ();
    QSqlQueryModel * afficher ();
    //bool supprimer (int id_achat);
   bool modifier(QString nom, QString prenom, QString sexe, QString email, float salaire, QString poste, QDate date_emboche, QString id);
};

#endif // PERSONEL_H
