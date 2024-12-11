#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QString>
#include <QDate>
#include <QDateTime>
#include <QSqlQueryModel>

class rendezvous {
private:
    int num_rendezvous;
    QString nom_client;
    QString nom_service;
    QDate date_rendezvous;
    QDateTime heure_rendezvous; // Utilisation de QDateTime pour l'heure et la date
    QString statut;

public:
    // Constructeurs
    rendezvous(int num, QString nc, QString n, QDate d, QDateTime h);
    rendezvous();

    // Méthodes
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier();
    bool supprimer(int num_rendezvous);
    bool mettreAJourStatut(int num_rendezvous, const QString &nouveauStatut);

    // Getters et Setters
    int getNumRendezvous() const { return num_rendezvous; }
    QString getNomClient() const { return nom_client; }
    QString getNomService() const { return nom_service; }
    QDate getDateRendezvous() const { return date_rendezvous; }
    QDateTime getHeureRendezvous() const { return heure_rendezvous; }
    QString getStatut() const { return statut; }

    void setNumRendezvous(int num) { num_rendezvous = num; }
    void setNomClient(const QString &nc) { nom_client = nc; }
    void setNomService(const QString &n) { nom_service = n; }
    void setDateRendezvous(const QDate &d) { date_rendezvous = d; }
    void setHeureRendezvous(const QDateTime &h) { heure_rendezvous = h; }
    void setStatut(const QString &s) { statut = s; }
};

#endif // RENDEZVOUS_H
