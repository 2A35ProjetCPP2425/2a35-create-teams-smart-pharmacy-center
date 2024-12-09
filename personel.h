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
    QString prenom,email,poste,mdp,sexe,id_emp,raison_conge,raison;


public:
    Personel();
    Personel(int,float,QString,QString,QString,QString,QString,QString,QDate);
    int generateIdentifiant();
    QString generateNumericPassword();
    QDate dateembauche, date_d ,date_f ,type_conge;
    bool idExists(QString id);
    bool supprimer(QString id_p);
    QString poste_conge;
    int generateId();
    QString generateConseilMessage();
    QString generateLeaveDecision();
    QSqlQueryModel *afficherconge();
    bool ajouterconge(const QString &id_emp, const QString &nom, const QString &prenom,
                      const QString &email, const QString &raison, const QString &poste,
                      const QDate &date_dep, const QDate &date_fin);
    bool updateCongeStatus(const QString &id_conge, const QString &etat);







    int getid_personel(){return id_personnel;}
    float getsalaire(){return salaire;}
    QString getnom (){return nom;};
    QString getprenom(){return prenom;};
    QString getemail(){return email;};
    QString getposte(){return poste;};
    QString getmdp(){return mdp;};
    QString getsexe(){return sexe;};
    bool getemployeemailpassword(const QString &id, const QString &mdp);
    bool getEmployeeDetailsById(const QString &id_emp, QString &nom, QString &prenom, QString &email, QString &poste);






    void setidpersonnel(int id){id_personnel=id;}
    void setsalaire(int sal){salaire=sal;}
    void setnom(QString n){nom=n;}
    void setprenom(QString pre){prenom=pre;}
    void setemail(QString mail ){email=mail;}
    void setposte( QString post){poste=post;}
    void setsexe(QString sex){sexe=sex;}
    void setmdp(QString pass){mdp=pass;}
    bool ajouterconge();





    bool ajouter ();
    QSqlQueryModel * afficher ();
    //bool supprimer (int id_achat);
   bool modifier(QString nom, QString prenom, QString sexe, QString email, float salaire, QString poste, QDate date_emboche, QString id);
   QSqlQueryModel* rechercher(QString id);
   QSqlQueryModel* tri(Qt::SortOrder order, int columnIndex1, int columnIndex2);
   void telechargerPDF();
};

#endif // PERSONEL_H
