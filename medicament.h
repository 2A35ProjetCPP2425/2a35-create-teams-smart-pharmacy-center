#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class medicament
{
private:
    int id_medicament,stock;
    QString nom_medicament;


public:
    // Constructeurs
    medicament();  // Constructeur par défaut
    medicament(int id_medicament, QString nom_medicament, int stock);

    // Getters
    int getId_medicament() { return id_medicament; }
    QString getNom_medicament() { return nom_medicament; }
    int getStock() { return stock; }

    // Setters
    void setId_medicament(int idm) { id_medicament = idm; }
    void setNom_medicament(QString nm) { nom_medicament = nm; }
    void setStock(int s) { stock = s; }


    // Méthodes

    QSqlQueryModel * afficher ();


};


#endif // MEDICAMENT_H
