#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QFileDialog>      // For QFileDialog
#include <QPdfWriter>       // For QPdfWriter
#include <QPageSize>        // For QPageSize
#include <QPageLayout>
#include <QSqlTableModel>
#include <QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



#include "arduino.h"
#include <QThread>
#include <QInputDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <service.h>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlError>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPixmap>
#include "rendezvous.h"
#include "medicament.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QDateTime>
#include <QRegularExpression>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      arduino(new Arduino(this))  // Initialisation du port série
{
    ui->setupUi(this);




    // Connecter Arduino au démarrage
    if (!arduino->connectArduino()) {
        QMessageBox::warning(this, "Erreur", "Impossible de se connecter à Arduino !");
    }





    searchBar1 = new QLineEdit(this);  // Crée le widget QLineEdit
    searchBar1->setPlaceholderText("Rechercher un rendezvous...");  // Texte d'exemple

    // Assure-toi qu'il y a un QVBoxLayout dans ton UI, sinon tu devras l'ajouter
    ui->verticalLayout_2->insertWidget(0, searchBar1);  // Ajoute le QLineEdit au layout (index 0 pour le mettre en haut)

    // Connecte le signal de changement de texte au slot de filtrage
    connect(searchBar1, &QLineEdit::textChanged, this, &MainWindow::filterRendezvous);



    searchBar = new QLineEdit(this);  // Crée le widget QLineEdit
    searchBar->setPlaceholderText("Rechercher un service...");  // Texte d'exemple
    // Assure-toi qu'il y a un QVBoxLayout dans ton UI, sinon tu devras l'ajouter
    ui->verticalLayout->insertWidget(0, searchBar);  // Ajoute le QLineEdit au layout (index 0 pour le mettre en haut)
    // Connecte le signal de changement de texte au slot de filtrage
    connect(searchBar, &QLineEdit::textChanged, this, &MainWindow::filterServices);
    ui->comboboxSort->addItem("Trier par");
    ui->comboboxSort->addItem("Nom");
    ui->comboboxSort->addItem("Prix");

    ui->combobox->addItem("Trier par");
    ui->combobox->addItem("Num rendez-vous");
    ui->combobox->addItem("nom client");
    ui->combobox->addItem("nom service");
    ui->combobox->addItem("date");

    ui->comboBoxStatut->addItem("Statut");
    ui->comboBoxStatut->addItem("en attente");
    ui->comboBoxStatut->addItem("passé");
    ui->comboBoxStatut->addItem("annulé");

    ui->comboBoxT->addItem("Trier par");
    ui->comboBoxT->addItem("Statut");
    ui->salleTableView->resizeColumnsToContents();
    ui->salleTableView->horizontalHeader()->setStretchLastSection(true);  // Étend la dernière colonne
    ui->salleTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



}





MainWindow::~MainWindow() {
    arduino->disconnectArduino();
    delete ui;
    delete arduino;

}









void MainWindow::refreshSalleView() {
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("salle");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    ui->salleTableView->setModel(model);

    // Redimensionner les colonnes automatiquement pour s'adapter au contenu
    ui->salleTableView->resizeColumnsToContents();

    // Étendre la dernière colonne pour occuper tout l'espace restant
    ui->salleTableView->horizontalHeader()->setStretchLastSection(true);

    // Optionnellement, vous pouvez étirer toutes les colonnes pour remplir l'espace
    ui->salleTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void MainWindow::on_btn_clicked() {
    // Lire les données de l'Arduino
    QString data = arduino->readData();
    qDebug() << "Données Arduino reçues : " << data;

    if (data.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée reçue de l'Arduino !");
        return;
    }

    // Vérifier si un mouvement a été détecté et mettre à jour le statut de la salle
    if (data.contains("Mouvement détecté")) {
        mettreAJourStatutSalle(1, "occupée");  // Remplacez 1 par le Num_salle approprié
        QMessageBox::information(this, "Salle de soins", "La salle est occupée. Veuillez patienter quelques minutes !");
    } else if (data.contains("Aucun mouvement")) {
        mettreAJourStatutSalle(1, "vide");  // Remplacez 1 par le Num_salle approprié
        QMessageBox::information(this, "Salle de soins", "La salle est vide, vous pouvez l'utiliser !");
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de lire correctement les données de la salle !");
    }

    // Rafraîchir la vue de la table salle
    refreshSalleView();
}



void MainWindow::mettreAJourStatutSalle(int numSalle, const QString &nouveauStatut) {
    QSqlQuery query;
    query.prepare("UPDATE salle SET statut = :statut WHERE Num_salle = :numSalle");
    query.bindValue(":statut", nouveauStatut);
    query.bindValue(":numSalle", numSalle);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour du statut de la salle : " << query.lastError();
    }
}











void MainWindow::on_ajouterButton_clicked() {
    QString nom_service = ui->nomServiceEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    double prix_service = ui->prixEdit->value();

    service newService(nom_service, description, prix_service);

    if (newService.ajouter()) {
        QMessageBox::information(this, "Succès", "Le service a été ajouté avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout du service.");
    }
}

void MainWindow::on_afficherButton_clicked() {
    service s;
    QSqlQueryModel *model = s.afficher();
    ui->tableView_rv->setModel(model);

}

void MainWindow::on_supprimerButton_clicked() {
    QString nom_service = ui->nomServiceEdit->text();

    service s;
    if (s.supprimer(nom_service)) {
        QMessageBox::information(this, "Succès", "Le service a été supprimé avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression du service.");
    }
}

void MainWindow::on_modifierButton_clicked() {  // Implémentation du slot pour le bouton "Modifier"
    QString nom_service = ui->nomServiceEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    int prix_service = ui->prixEdit->value();

    if (nom_service.isEmpty() || description.isEmpty() || prix_service <= 0) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs correctement.");
        return;
    }

    service existingService(nom_service, description, prix_service);

    if (existingService.modifier()) {
        QMessageBox::information(this, "Succès", "Le service a été modifié avec succès !");
        on_afficherButton_clicked();  // Rafraîchit l'affichage pour montrer le service modifié
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification du service.");
    }
}

void MainWindow::on_pushButton_generatePDF_clicked() {
    // Accéder à la tableView directement depuis l'UI
    QTableView *tableView_rv = ui->tableView_rv;

    QString fileName = QFileDialog::getSaveFileName(this, "Save as PDF", "", "PDF Files (.pdf);;All Files ()");
    if (fileName.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageOrientation(QPageLayout::Portrait);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);

    QAbstractItemModel *model = tableView_rv->model();

    int x = 10;   // Position x de départ
    int y = 30;   // Position y de départ
    int rowHeight = 100;
    int columnWidth = 500;

    // Définir la police pour le PDF avec une taille plus grande
    QFont font = painter.font();
    font.setPointSize(12);  // Augmenter la taille de la police à 12
    painter.setFont(font);

    // Dessiner les en-têtes de colonnes
    for (int column = 0; column < model->columnCount(); ++column) {
        QRect rect(x + column * columnWidth, y, columnWidth, rowHeight);
        painter.drawText(rect, Qt::AlignCenter, model->headerData(column, Qt::Horizontal).toString());
        painter.drawRect(rect);
    }

    // Dessiner les lignes
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QRect rect(x + column * columnWidth, y + (row + 1) * rowHeight, columnWidth, rowHeight);
            painter.drawText(rect, Qt::AlignCenter, model->data(model->index(row, column)).toString());
            painter.drawRect(rect);
        }
    }

    painter.end();
    QMessageBox::information(this, "Export Complete", "Data has been exported to PDF successfully.");
}

void MainWindow::filterServices() {
    QString searchText = searchBar->text(); // Assurez-vous que searchBar est bien un QLineEdit défini dans votre interface

    QString queryStr;
    if (searchText.isEmpty()) {
        queryStr = "SELECT * FROM service";  // Si le champ est vide, montre tous les services
    } else {
        // Requête pour filtrer par nom_service, description ou prix_service
        queryStr = QString("SELECT * FROM service WHERE nom_service LIKE '%%1%' OR description LIKE '%%1%' OR prix_service LIKE '%%1%'").arg(searchText);
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(queryStr);  // Définit la requête à exécuter

    // Vérifie si la requête a échoué
    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Erreur", model->lastError().text());
    } else {
        ui->tableView_rv->setModel(model); // Applique le modèle à la table
    }
}

void MainWindow::on_comboboxSort_currentIndexChanged(int index) {
    QSqlQueryModel *model = new QSqlQueryModel;
    QString query;

    if (index == 1) {  // Trier par nom du service
        query = "SELECT * FROM service ORDER BY nom_service ASC";
    } else if (index == 2) {  // Trier par prix du service
        query = "SELECT * FROM service ORDER BY prix_service ASC";
    }

    model->setQuery(query);
    ui->tableView_rv->setModel(model);
}

void MainWindow::on_btnAjouter_clicked() {

    int num_rendezvous = ui->lineEditNum->text().toInt();
    QString nom_client = ui->lineEditClientId->text();
    QString nom_service = ui->lineEditNomService->text();
    QDate date_rendezvous = ui->dateEdit->date();
    QDateTime heure_rendezvous = ui->timeEdit->dateTime();

    // Créer un objet rendezvous avec les données récupérées
    rendezvous newRendezvous(num_rendezvous, nom_client, nom_service, date_rendezvous, heure_rendezvous);

    // Tenter d'ajouter le rendez-vous à la base de données
    if (newRendezvous.ajouter()) {
        QMessageBox::information(this, "Succès", "Le rendez-vous a été ajouté avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout du rendez-vous.");
    }
}

void MainWindow::on_btnAfficher_clicked() {
    rendezvous rdv;
    QSqlQueryModel *model = rdv.afficher();  // Récupérer le modèle contenant les données des rendez-vous
    ui->tableView->setModel(model);  // Affecter ce modèle au tableView pour l'affichage
}



void MainWindow::on_btnModifier_clicked() {
    int num_rendezvous = ui->lineEditNum->text().toInt();
    QString nom_client = ui->lineEditClientId->text();
    QString nom_service = ui->lineEditNomService->text();
    QDate date_rendezvous = ui->dateEdit->date();
    QDateTime heure_rendezvous = ui->timeEdit->dateTime();

    if (num_rendezvous <= 0 || nom_client.isEmpty() || nom_service.isEmpty() || !date_rendezvous.isValid() || !heure_rendezvous.isValid()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs correctement.");
        return;
    }

    rendezvous existingRendezvous(num_rendezvous, nom_client, nom_service, date_rendezvous, heure_rendezvous);

    if (existingRendezvous.modifier()) {
        QMessageBox::information(this, "Succès", "Le rendez-vous a été modifié avec succès !");
        on_btnAfficher_clicked();  // Rafraîchit l'affichage
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification du rendez-vous.");
    }
}
void MainWindow::on_combobox_currentIndexChanged(int index) {
    QSqlQueryModel *model = new QSqlQueryModel;
    QString query;

    if (index == 1) {  // Trier par nom du service
        query = "SELECT * FROM rendezvous ORDER BY num_rendezvous ASC";
    } else if (index == 2) {
        query = "SELECT * FROM rendezvous ORDER BY nom_client ASC";
    }else if (index == 3) {
        query = "SELECT * FROM rendezvous ORDER BY nom_service ASC";
    }else if (index == 4) {
        query = "SELECT * FROM rendezvous ORDER BY date_rendezvous ASC";
    }

    model->setQuery(query);
    ui->tableView->setModel(model);
}
void MainWindow::on_comboBoxT_currentIndexChanged(int index) {
    QSqlQueryModel *model = new QSqlQueryModel;
    QString query;

    if (index == 1) {  // Trier par nom du service
        query = "SELECT * FROM rendezvous ORDER BY statut ASC";
    }

    model->setQuery(query);
    ui->tableView_r->setModel(model);
}
void MainWindow::filterRendezvous() {
    QString searchText = searchBar1->text(); // Assurez-vous que searchBar1 est bien un QLineEdit défini dans votre interface

    QString queryStr;
    if (searchText.isEmpty()) {
        queryStr = "SELECT * FROM rendezvous";  // Si le champ est vide, montre tous les rendez-vous
    } else {
        // Correction de la concaténation de la requête
        queryStr = QString("SELECT * FROM rendezvous WHERE num_rendezvous LIKE '%%1%' OR nom_client LIKE '%%1%' OR nom_service LIKE '%%1%' OR date_rendezvous LIKE '%%1%'").arg(searchText);
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(queryStr);  // Définit la requête à exécuter

    // Vérifie si la requête a échoué
    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Erreur", model->lastError().text());
    } else {
        ui->tableView->setModel(model); // Applique le modèle à la table
    }
}

void MainWindow::on_btnMettreAJourStatut_clicked() {
    QModelIndex index = ui->tableView->currentIndex();  // Récupérer l'élément sélectionné dans la tableView
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un rendez-vous.");
        return;
    }

    // Récupérer l'ID du rendez-vous à partir de la table
    int num_rendezvous = index.sibling(index.row(), 0).data().toInt(); // La première colonne (num_rendezvous)
    QString statut = ui->comboBoxStatut->currentText();  // Récupérer le statut sélectionné dans le ComboBox

    rendezvous rdv;
    if (statut == "annulé") {
        if (rdv.supprimer(num_rendezvous)) {
            QMessageBox::information(this, "Succès", "Le rendez-vous a été annulé et supprimé.");
            on_btnAfficher_clicked(); // Rafraîchir l'affichage
        }
    } else if (statut == "passé") {
        if (rdv.mettreAJourStatut(num_rendezvous, "passé")) {
            QMessageBox::information(this, "Succès", "Le rendez-vous a été marqué comme passé.");
            on_btnAfficher_clicked(); // Rafraîchir l'affichage
        }
    }
}
void MainWindow::on_afficher_clicked() {
    // Afficher les rendez-vous dans la table
    rendezvous r;
    QSqlQueryModel *modelRendezvous = r.afficher();
    ui->tableView_r->setModel(modelRendezvous);

    // Afficher les services dans la table
    medicament m;
    QSqlQueryModel *modelMedicament = m.afficher();
    ui->tableView_s->setModel(modelMedicament);

    // Récupérer les statistiques des rendez-vous (en attente et passés)
    QMap<QString, int> statsRendezvous = recupererStatistiquesRendezvous();
    afficherStatistiquesRendezvous(statsRendezvous);

    // Récupérer les statistiques des services utilisés
    QMap<QString, int> statsServices = recupererStatistiquesServices();
    afficherStatistiquesServices(statsServices);
}


QMap<QString, int> MainWindow::recupererStatistiquesRendezvous() {
    QMap<QString, int> stats;
    QSqlQuery query;

    // Récupérer le nombre de rendez-vous par statut (passés, en attente)
    query.prepare("SELECT statut, COUNT(*) FROM rendezvous GROUP BY statut");

    if (query.exec()) {
        while (query.next()) {
            QString statut = query.value(0).toString();
            int count = query.value(1).toInt();
            stats[statut] = count;
        }
    } else {
        qDebug() << "Erreur de récupération des statistiques de rendezvous";
    }
    return stats;
}

QMap<QString, int> MainWindow::recupererStatistiquesServices() {
    QMap<QString, int> stats;
    QSqlQuery query;

    // Récupérer le nombre de services utilisés dans les rendez-vous
    query.prepare("SELECT nom_service, COUNT(*) FROM rendezvous GROUP BY nom_service");

    if (query.exec()) {
        while (query.next()) {
            QString service = query.value(0).toString();
            int count = query.value(1).toInt();
            stats[service] = count;
        }
    } else {
        qDebug() << "Erreur de récupération des statistiques des services";
    }
    return stats;
}

void MainWindow::afficherStatistiquesRendezvous(QMap<QString, int> stats) {
    // Créer une nouvelle scène pour les rendez-vous
    QGraphicsScene *scene = new QGraphicsScene(this);
    int x = 0;

    // Affichage des rendez-vous passés (en bleu)
    if (stats.contains("passe")) {
        int passed = stats["passe"];
        scene->addRect(x, 0, 50, passed * 20, QPen(Qt::green), QBrush(Qt::green));
        scene->addText("Passe: " + QString::number(passed))->setPos(x, passed * 20 + 10);
        x += 60;
    }

    // Affichage des rendez-vous en attente (en rouge)
    if (stats.contains("en attente")) {
        int waiting = stats["en attente"];
        scene->addRect(x, 0, 50, waiting * 20, QPen(Qt::red), QBrush(Qt::red));
        scene->addText("En attente: " + QString::number(waiting))->setPos(x, waiting * 20 + 10);
        x += 60;
    }

    // Définir la scène dans le QGraphicsView des rendez-vous
    ui->graphicsViewRendezvous->setScene(scene);
}
void MainWindow::afficherStatistiquesServices(QMap<QString, int> stats) {
    // Créer une nouvelle scène pour les services
    QGraphicsScene *scene = new QGraphicsScene(this);
    int x = 0;

    // Liste de couleurs prédéfinies
    QVector<QColor> couleurs = {Qt::red, Qt::blue, Qt::green, Qt::yellow, Qt::magenta, Qt::cyan, Qt::gray};
    int colorIndex = 0;

    // Affichage des services utilisés, chaque service avec une couleur unique
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        int height = it.value() * 20;  // Hauteur basée sur le nombre de services utilisés

        // Utiliser la couleur suivante de la liste (cycle à travers la liste si besoin)
        QColor color = couleurs[colorIndex % couleurs.size()];  // Utilise % pour revenir au début si trop de services

        // Ajouter un rectangle pour chaque service avec une couleur unique
        scene->addRect(x, 0, 50, height, QPen(color), QBrush(color));
        scene->addText(it.key() + ": " + QString::number(it.value()))->setPos(x, height + 10);

        // Incrémenter l'indice de couleur pour le service suivant
        colorIndex++;
        x += 60;
    }

    // Définir la scène dans le QGraphicsView des services
    ui->graphicsViewServices->setScene(scene);
}

