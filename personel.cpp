#include "personel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QDate>


Personel::Personel(){
    id_personnel=0;
    nom="";
    prenom="";
    email="";
    poste="";
    mdp="";
    sexe="";
    dateembauche = QDate();
    salaire=0.0;
}

Personel::Personel(int id_personnel, float salaire, QString nom, QString prenom, QString email, QString poste, QString mdp, QString sexe, QDate dateembauche){

    this->id_personnel=id_personnel;
    this->salaire=salaire;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->poste=poste;
    this->mdp=mdp;
    this->sexe=sexe;
    this->dateembauche=dateembauche;
}
int Personel::generateIdentifiant() {
    int identifiant = 0;

    // Generate 4 random numbers and build the integer
    for (int i = 0; i < 4; i++) {
        int num = QRandomGenerator::global()->bounded(10); // Random number between 0 and 9
        identifiant = identifiant * 10 + num; // Shift left by one digit and add the random number
    }

    return identifiant; // Return the generated integer
}

QString Personel::generateNumericPassword() {
    QString password;
    for (int i = 0; i < 8; ++i) {
        int digit = rand() % 10; //
        password.append(QString::number(digit));
    }
    return password;
}

bool Personel::ajouter() {
    int id_p = generateIdentifiant(); // Generate the identifier
    QString mdp = generateNumericPassword(); // Generate a numeric password

    QSqlQuery query;
    query.prepare("INSERT INTO personnels (id_personnel, nom, prenom, email, poste, mdp, sexe, date_embauche, salaire) "
                  "VALUES (:id_p, :nom, :prenom, :email, :poste, :mdp, :sexe, :date_embauche, :salaire)");

    // Bind values to placeholders
    query.bindValue(":id_p", id_p);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":poste", poste);
    query.bindValue(":mdp", mdp);
    query.bindValue(":sexe", sexe);
    query.bindValue(":date_embauche", dateembauche.toString("yyyy-MM-dd"));
    query.bindValue(":salaire", QVariant::fromValue(salaire));

    // Display all attributes in qDebug for verification
    qDebug() << "Adding Employee with the following details:";
    qDebug() << "ID:" << id_p;
    qDebug() << "Name:" << nom;
    qDebug() << "Surname:" << prenom;
    qDebug() << "Email:" << email;
    qDebug() << "Position:" << poste;
    qDebug() << "Password:" << mdp;
    qDebug() << "Gender:" << sexe;
    qDebug() << "Hire Date:" << dateembauche.toString("yyyy-MM-dd");
    qDebug() << "Salary:" << salaire;

    // Execute the query and check for success
    if (!query.exec()) {
        qDebug() << "Error adding employee:" << query.lastError().text();
        return false;
    }

    return true;
}



bool Personel::idExists(QString id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM personnels WHERE id_personnel = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            // Check the result of the query and return true if count > 0, else false
            return query.value(0).toInt() > 0;
        }
    } else {
        qDebug() << "ID existence check query error:" << query.lastError().text();
    }

    return false; // Return false if the query fails or the count is 0
}


bool Personel::supprimer(QString id_p){
    QSqlQuery query;
    query.prepare("DELETE FROM personnels WHERE id_personnel = :id_p");
    query.bindValue(":id_p", id_p); // Bind the value correctly
    return query.exec();
}
QSqlQueryModel *Personel::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from personnels");


    // Set header data for each column correctly
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Personnel"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date d'embauche"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));



    return model;
}
bool Personel::modifier(QString nom, QString prenom, QString sexe, QString email, float salaire, QString poste, QDate date_embauche, QString id)
{
    QStringList updateFields;

    // Dynamically construct the fields to be updated
    if (!nom.isEmpty()) {
        updateFields << "nom = :nom";
    }
    if (!prenom.isEmpty()) {
        updateFields << "prenom = :prenom";
    }
    if (!sexe.isEmpty()) {
        updateFields << "sexe = :sexe";
    }
    if (!email.isEmpty()) {
        updateFields << "email = :email";
    }
    if (salaire > 0) {
        updateFields << "salaire = :salaire";
    }
    if (!poste.isEmpty()) {
        updateFields << "poste = :poste";
    }
    if (date_embauche.isValid()) {
        updateFields << "date_embauche = :date_embauche";
    }

    // Check if there are fields to update
    if (updateFields.isEmpty()) {
        qDebug() << "No fields to update.";
        return false; // Nothing to update
    }

    // Join all fields with a comma to form the final query
    QString queryString = "UPDATE personnels SET " + updateFields.join(", ") + " WHERE id_personnel = :id";

    // Prepare the query
    QSqlQuery query;
    query.prepare(queryString);

    // Bind only the non-empty values
    if (!nom.isEmpty()) query.bindValue(":nom", nom);
    if (!prenom.isEmpty()) query.bindValue(":prenom", prenom);
    if (!sexe.isEmpty()) query.bindValue(":sexe", sexe);
    if (!email.isEmpty()) query.bindValue(":email", email);
    if (salaire > 0) query.bindValue(":salaire", salaire);
    if (!poste.isEmpty()) query.bindValue(":poste", poste);
    if (date_embauche.isValid()) query.bindValue(":date_embauche", date_embauche.toString("yyyy-MM-dd"));
    query.bindValue(":id", id); // Bind 'id' as the employee identifier

    // Execute and check for success
    if (!query.exec()) {
        qDebug() << "Update failed:" << query.lastError();
        return false;
    }

    return true;
}
