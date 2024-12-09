#include "personel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidgetItem>
#include <QSqlError>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QVariant>
#include <QPdfWriter>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QtCore>
#include <QCoreApplication>
#include <QUrl>
#include <QByteArray>
#include <QDebug>
#include <QPair>
#include <cmath>
#include <QStandardItemModel>


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
QSqlQueryModel* Personel::rechercher(QString id) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM personnels WHERE id_personnel = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        model->setQuery(std::move(query));
    } else {
        qDebug() << "Search query error:" << query.lastError();
    }

    return model;
}

QSqlQueryModel* Personel::tri(Qt::SortOrder order, int columnIndex1, int columnIndex2) {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Déterminer l'ordre de tri (ASC ou DESC)
    QString sortOrder = (order == Qt::AscendingOrder) ? "ASC" : "DESC";
    QString query;

    // Tri par différentes colonnes en fonction de columnIndex
    if (columnIndex1 == 1 && columnIndex2 == 9) {
        // Tri par ID_PERSONNEL et SALAIRE
        query = "SELECT ID_PERSONNEL, NOM, PRENOM, EMAIL, POSTE, MDP, SEXE, DATE_EMBAUCHE, SALAIRE "
                "FROM Personnels "
                "ORDER BY SALAIRE " + sortOrder + ", DATE_EMBAUCHE " + sortOrder; // Tri sur SALAIRE puis DATE_EMBAUCHE
    }
    else if (columnIndex1 == 9 && columnIndex2 == 1) {
        // Tri par SALAIRE et DATE_EMBAUCHE dans l'ordre inverse
        query = "SELECT ID_PERSONNEL, NOM, PRENOM, EMAIL, POSTE, MDP, SEXE, DATE_EMBAUCHE, SALAIRE "
                "FROM Personnels "
                "ORDER BY SALAIRE " + sortOrder + ", DATE_EMBAUCHE " + sortOrder;
    }
    else if (columnIndex1 == 9) {
        // Tri par SALAIRE
        query = "SELECT ID_PERSONNEL, NOM, PRENOM, EMAIL, POSTE, MDP, SEXE, DATE_EMBAUCHE, SALAIRE "
                "FROM Personnels "
                "ORDER BY SALAIRE " + sortOrder;
    }
    else if (columnIndex1 == 8) {
        // Tri par DATE_EMBAUCHE
        query = "SELECT ID_PERSONNEL, NOM, PRENOM, EMAIL, POSTE, MDP, SEXE, DATE_EMBAUCHE, SALAIRE "
                "FROM Personnels "
                "ORDER BY DATE_EMBAUCHE " + sortOrder;
    }

    // Définir la requête pour le modèle
    model->setQuery(query);

    // Vérifier si la requête a échoué
    if (model->lastError().isValid()) {
        qDebug() << "Query failed: " << model->lastError().text();
    }

    return model;
}



void Personel::telechargerPDF() {
    QPdfWriter pdf("C:/Users/User/OneDrive/Desktop/projet_personel/pdf_personnel.pdf");
    pdf.setPageSize(QPageSize(QPageSize::A3));
    pdf.setPageOrientation(QPageLayout::Portrait);
    QPainter painter(&pdf);

    // Background color
    painter.fillRect(QRect(0, 0, pdf.width(), pdf.height()), QColor("#B6E5E9"));

    // Title
    QFont titleFont("Arial", 30, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(3800, 1400, "PROFILS DES EMPLOYÉS");

    // Set up fonts for header and content
    QFont headerFont("Arial", 12, QFont::Bold);
    QFont contentFont("Times New Roman", 11);
    painter.setFont(contentFont);

    // Execute query to get all employees
    QSqlQuery query;
    query.prepare("select * from personnels");
    query.exec();

    // Set up table positioning
    int initialYPosition = 2000;
    int currentYPosition = initialYPosition;
    int cellHeight = 500;
    int tableMargin = 300;

    // Define custom column widths based on expected content length
    int columnWidths[] = {1200, 1200, 1200, 800, 2000, 2000, 1500, 2000, 2600};  // Adjust widths as needed

    // Column headers
    QStringList headers = {"ID", "Nom", "Prénom", "SEXE", "POSTE", "Email", "Salaire", "Date D'embauche"};

    // Draw header row
    painter.setFont(headerFont);
    painter.setPen(Qt::black);
    int xPosition = tableMargin;
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawRect(xPosition, currentYPosition, columnWidths[i], cellHeight);
        painter.drawText(xPosition + 10, currentYPosition + cellHeight / 2 + 5, headers[i]);
        xPosition += columnWidths[i];
    }
    currentYPosition += cellHeight;  // Move to the next row

    // Set alternating row colors
    QColor rowColor1("#E0F7FA");
    QColor rowColor2("#FFFFFF");

    // Draw each employee's data in a table row
    painter.setFont(contentFont);
    bool alternate = false;
    while (query.next()) {
        xPosition = tableMargin;

        // Set row background color
        QColor rowColor = alternate ? rowColor1 : rowColor2;
        painter.fillRect(xPosition, currentYPosition, pdf.width() - 2 * tableMargin, cellHeight, rowColor);
        alternate = !alternate;

        // Draw each cell in the current row
        QStringList rowData = {
            query.value("ID_PERSONNEL").toString(), query.value("nom").toString(), query.value("prenom").toString(),
            query.value("sexe").toString(), query.value("poste").toString(),
            query.value("email").toString(), query.value("salaire").toString(),
            query.value("DATE_EMBAUCHE").toDate().toString("dd/MM/yyyy")
        };

        for (int i = 0; i < rowData.size(); ++i) {
            painter.drawRect(xPosition, currentYPosition, columnWidths[i], cellHeight);

            // Draw text within the cell
            painter.drawText(xPosition + 10, currentYPosition + cellHeight / 2 + 5, rowData[i]);
            xPosition += columnWidths[i];
        }

        currentYPosition += cellHeight;  // Move down for the next row

        // Check if we need a new page
        if (currentYPosition > pdf.height() - 2000) {
            pdf.newPage();
            currentYPosition = initialYPosition;  // Reset to top of the new page

            // Re-draw header row on the new page
            xPosition = tableMargin;
            painter.setFont(headerFont);
            for (int i = 0; i < headers.size(); ++i) {
                painter.drawRect(xPosition, currentYPosition, columnWidths[i], cellHeight);
                painter.drawText(xPosition + 10, currentYPosition + cellHeight / 2 + 5, headers[i]);
                xPosition += columnWidths[i];
            }
            currentYPosition += cellHeight;  // Move to the next row after header
        }
    }

    painter.end();
}

bool Personel::getemployeemailpassword(const QString &id_p, const QString &mdp)
{
    QSqlQuery query;

    // Préparer la requête SQL pour vérifier les identifiants
    query.prepare("SELECT COUNT(*) FROM personnels WHERE ID_PERSONNEL = :id AND MDP = :mdp;");
    query.bindValue(":id", id_p);   // Liaison de l'identifiant
    query.bindValue(":mdp", mdp);  // Liaison du mot de passe

    // Exécuter la requête
    if (query.exec()) {
        // Vérifier si une ligne est retournée et si COUNT(*) > 0
        if (query.next() && query.value(0).toInt() > 0) {
            return true;  // Identifiants valides
        } else {
            return false;  // Aucun enregistrement correspondant
        }
    } else {
        // En cas d'erreur d'exécution de la requête
        qDebug() << "Échec de la requête :" << query.lastError().text();
        return false;
    }
}
bool Personel::getEmployeeDetailsById(const QString &id_emp, QString &nom, QString &prenom, QString &email, QString &poste)
{
    // Vérifiez que la connexion à la base de données est valide
    QSqlQuery query;

    // Préparer la requête SQL pour récupérer les détails de l'employé
    query.prepare("SELECT NOM, PRENOM, EMAIL, POSTE FROM personnels WHERE ID_PERSONNEL = :id_emp");

    // Lier le paramètre :id_emp
    query.bindValue(":id_emp", id_emp);

    // Exécuter la requête
    if (query.exec()) {
        if (query.next()) {
            // Si un résultat est trouvé, affectez les valeurs aux références passées
            nom = query.value("NOM").toString();       // Correspond à la colonne NOM
            prenom = query.value("PRENOM").toString(); // Correspond à la colonne PRENOM
            email = query.value("EMAIL").toString();   // Correspond à la colonne EMAIL
            poste = query.value("POSTE").toString();   // Correspond à la colonne POSTE

            return true; // Succès
        } else {
            // Aucun employé trouvé pour l'ID donné
            qDebug() << "Aucun employé trouvé avec l'ID :" << id_emp;
            return false;
        }
    } else {
        // La requête a échoué
        qDebug() << "Échec de la requête :" << query.lastError().text();
        return false;
    }
}
int Personel::generateId() {
    // Générer un nombre aléatoire à 6 chiffres entre 100000 et 999999
    int randomId = QRandomGenerator::global()->bounded(100000, 1000000);
    return randomId; // Retourner l'identifiant généré
}
QString Personel::generateLeaveDecision() {
    // Variables pour stocker le nombre d'employés totaux et d'employés non en congé
    int totalEmployees = 0;
    int employeesNotOnLeave = 0;

    // Requête pour obtenir le nombre total d'employés
    QSqlQuery query;

    // Compter le nombre total d'employés dans PERSONNELS
    query.prepare("SELECT COUNT(*) FROM PERSONNELS");
    if (query.exec() && query.next()) {
        totalEmployees = query.value(0).toInt();
    } else {
        qDebug() << "Erreur lors de la récupération du nombre d'employés:" << query.lastError().text();
        return "Erreur de calcul des employés.";
    }
    qDebug() << "totaleemploye:" <<totalEmployees;

    // Compter les employés qui ne sont pas en congé dans CONGE
    // Supposons que `ETAT` est le champ dans la table `CONGE` qui indique l'état du congé (ex. 'Non' pour non en congé)
    query.prepare("SELECT COUNT(*) FROM CONGE WHERE ETAT != 'En congé'"); // Modifiez cette condition selon vos données
    if (query.exec() && query.next()) {
        employeesNotOnLeave = query.value(0).toInt();
    } else {
        qDebug() << "Erreur lors de la récupération des employés non en congé:" << query.lastError().text();
        return "Erreur de calcul des employés non en congé.";
    }
    qDebug() << "employe on leave:" << employeesNotOnLeave;

    // Calcul du pourcentage d'employés non en congé
    if (totalEmployees == 0) {
        return "Aucun employé disponible pour calculer.";
    }

    float percentageNotOnLeave = (float)employeesNotOnLeave / totalEmployees * 100;
    float percentagework= 100-(percentageNotOnLeave);
    qDebug() << "percentage:" << percentageNotOnLeave;
    qDebug() << "percetagework:" << percentagework;

    // Décision selon le seuil de 70%
    if (percentagework >= 70) {
        return "Tu peux accepter le congé.";
    } else {
        return "N'accepte pas le congé.";
    }
}


bool Personel::ajouterconge(const QString &id_emp, const QString &nom, const QString &prenom,
                             const QString &email, const QString &raison, const QString &poste,
                             const QDate &date_dep, const QDate &date_fin) {
    int id_conge = generateId(); // Générer un ID unique pour le congé
    QString conseilMessage = generateLeaveDecision(); // Générer une consigne pour le congé

    // Ensure QSqlQuery is properly declared and included
    QSqlQuery query;
    query.prepare("INSERT INTO conge (ID_CONGE, ID_EMP, NOM, PRENOM, EMAIL, RAISON, POSTE, DATE_DEP, DATE_FIN, CONSIGNE, TYPE_CONGÉ, ETAT) "
                  "VALUES (:id_conge, :id_emp, :nom, :prenom, :email, :raison, :poste, :date_dep, :date_fin, :consigne, 'Congé annuel', 'En attente')");

    // Lier les valeurs
    query.bindValue(":id_conge", id_conge);
    query.bindValue(":id_emp", id_emp);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":raison", raison);
    query.bindValue(":poste", poste);
    query.bindValue(":date_dep", date_dep);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":consigne", conseilMessage);
    query.bindValue(":type_congé", type_conge);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du congé :" << query.lastError().text();
        return false; // Échec de l'insertion
    }

    return true; // Insertion réussie
}
QSqlQueryModel *Personel::afficherconge() {
    QSqlQueryModel *model = new QSqlQueryModel();

    // SQL Query to fetch data from conge table
    model->setQuery("SELECT \"ID_CONGE\", \"NOM\", \"PRENOM\", \"EMAIL\", \"POSTE\", \"RAISON\", \"DATE_DEP\", \"DATE_FIN\", \"TYPE_CONGÉ\", \"CONSIGNE\" ,\"ETAT\" FROM conge;");

    // Check if the query executed successfully
    if (model->lastError().isValid()) {
        qDebug() << "Query execution error:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    // Set header data for each column
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Conge"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Raison"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Type Congé"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Consigne"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Etat"));

    return model;
}

bool Personel::updateCongeStatus(const QString &id_conge, const QString &etat)
{
    // Prepare the SQL query to update only the 'etat' column
    QSqlQuery query;
    query.prepare("UPDATE conge SET etat = :etat WHERE ID_CONGE = :id_conge");

    // Bind the values to the query
    query.bindValue(":etat", etat);
    query.bindValue(":id_conge", id_conge);

    // Log the query for debugging
    qDebug() << "Executing query: UPDATE conge SET etat = " << etat
             << " WHERE ID_CONGE = " << id_conge;

    // Execute the query and check for success
    if (query.exec()) {
        qDebug() << "Record updated successfully.";
        return true;
    } else {
        qDebug() << "Error updating record: " << query.lastError().text();
        return false;
    }
}



