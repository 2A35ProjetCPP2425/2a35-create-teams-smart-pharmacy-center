#include "gestion_achat.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

gestion_achat::gestion_achat(int id_achat ,QString nom ,int quantite , float prix ,QDate date_achat,int id_preso)
{
    this->id_achat=id_achat;
    this->nom=nom;
    this->quantite=quantite;
    this->prix=prix;
    this ->date_achat=date_achat;
    this ->id_perso=id_preso;



}


bool gestion_achat::ajouter ()
{
 QSqlQuery query;
 QString res = QString :: number(id_achat);
 QString res1 = QString :: number(id_perso);
 QString res2 = QString::number(prix, 'f', 3);
 query.prepare("INSERT INTO gestion_achat (ID_ACHAT, NOM, QUANTITE, PRIX, DATE_ACHAT, ID_PERSO) "
                   "VALUES (:id_achat, :nom, :quantite, :prix, :date_achat, :id_perso)");


 query.bindValue(":id_achat",res);
 query.bindValue(":nom",nom);
 query.bindValue(":prix",res2);
 query.bindValue(":quantite",quantite);
 query.bindValue(":date_achat", date_achat);
 query.bindValue(":id_perso",res1);
 return query.exec();

}
QSqlQueryModel * gestion_achat::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select *from gestion_achat");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_achat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_achat"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_perso"));




   return model;

}
bool gestion_achat::supprimer(int id_achat)
{

   QSqlQuery query;
   QString res=QString::number(id_achat);
   query.prepare("delete from gestion_achat where id_achat =:id_achat");
   query.bindValue(":id_achat",res);
   return query.exec();


}
bool gestion_achat::modifier(int id_achat, const QString &nouveauNom, int nouvelleQuantite, float nouveauPrix,  QDate &date_achat, int id_perso)
{
    QSqlQuery query;

    query.prepare("UPDATE gestion_achat SET nom = :nom, quantite = :quantite, prix = :prix, date_achat = :date_achat, id_perso = :id_perso WHERE id_achat = :id_achat");

    // Lier les valeurs
    query.bindValue(":nom", nouveauNom);
    query.bindValue(":quantite", nouvelleQuantite);
    query.bindValue(":prix", nouveauPrix);
    query.bindValue(":date_achat", date_achat);
    query.bindValue(":id_perso", id_perso);
    query.bindValue(":id_achat", id_achat); // Condition pour identifier la ligne à modifier

    return query.exec(); // Exécute la requête et renvoie vrai si l'exécution réussit
}

