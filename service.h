#ifndef SERVICE_H
#define SERVICE_H
#include<QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QTableView>

class service
{
private:
    QString nom_service,description;
    float prix_service;
public:
    service(){}
    service(QString nom_serive,QString description,float prix_service);
    QString getNom_service(){return nom_service;}
    QString getDescription(){return description;}
    float getPrix_service(){return prix_service;}
    void setNom(QString n){nom_service=n;}
    void setDescription(QString d){description=d;}
    void setPrix_service(float ps){this->prix_service=ps;}

    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer(QString nom_service);
    bool modifier();
    bool genererPDF(const QTableView* tableView, const QString& filePath);




};

#endif // SERVICE_H
