#ifndef MEDICAMENTS_H
#define MEDICAMENTS_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class MEDICAMENTS
{
private:
    int ID, QTESTOCK;
    QString NOM, CATEGORIE;
    QDate DATDEXP;
    float PRIX; // Ajout de l'attribut PRIX

public:
    // Constructeur par défaut
    MEDICAMENTS();

    // Constructeur avec paramètres
    MEDICAMENTS(int ID, int QTESTOCK, QString CATEGORIE, QDate DATDEXP, QString NOM, float PRIX);

    // Méthode pour définir les valeurs des attributs
    void fset(int ID, int QTESTOCK, QString CATEGORIE, QDate DATDEXP, QString NOM, float PRIX);

    // Setters et Getters
    void setPrix(float PRIX);
    float getPrix() const;

    // Méthodes pour les opérations sur la base de données
    bool ajout();
    QSqlQueryModel* afficher();
    bool modifier();
    bool supprimer();
    bool existe();
    QSqlQueryModel* trierParID();

        // Trier les médicaments par NOM
    QSqlQueryModel* trierParNom();
    QSqlQueryModel* statistiquesParCategorie();
    QSqlQueryModel* rechercheParID(int idRecherche);
    bool consommer(int id, int quantiteConsommee);
    bool ajouterQuantite(int id, int quantiteAjoutee);
};

#endif // MEDICAMENTS_H
