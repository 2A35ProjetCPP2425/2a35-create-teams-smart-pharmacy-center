#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "distribution.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QPainter>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QLayout>
#include <QtCharts/QPieSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QVBoxLayout>
#include <QPolygonF>
#include <QPointF>
#include <QVector>
#include <QGraphicsPolygonItem>
#include <QtCore/QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Distribution d;
    ui->setupUi(this);
    mettreAJourListeAboratoires();
    ui->tableView->setModel(d.afficher());
    Distributeur d1;
    ui->tableView_6->setModel(d1.afficher1());

}
void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    mettreAJourListeAboratoires();     // Appel à la méthode de la classe parente

    // Charge et affiche les données de la table distribution chaque fois que la fenêtre est affichée
    Distribution dist;
    ui->tableView->setModel(dist.afficher());
    Distributeur d1;
    ui->tableView_6->setModel(d1.afficher1());
}
void MainWindow::on_pushButton_ajouter_clicked()
{
    Distribution d1;
    int id_distribution = ui->lineEdit_id->text().toInt();
    int qte_distribution = ui->lineEdit_qte->text().toInt();
    QString aboratoire_distribution = ui->comboBox_aboratoire->currentText();
    QDate dated_distribution = ui->dateEdit_date->date();
    int medist_distribution = ui->lineEdit_medist->text().toInt();
    if (id_distribution <= 0) {
        QMessageBox::warning(this, "Validation", "L'ID de la distribution doit être un nombre positif !");
        return;
    }

    if (d1.idExiste(id_distribution)) {
        QMessageBox::warning(this, "Validation", "L'ID existe déjà. Veuillez en choisir un autre !");
        return;
    }

    if (qte_distribution <= 0) {
        QMessageBox::warning(this, "Validation", "La quantité doit être un nombre positif !");
        return;
    }

    if (aboratoire_distribution.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le champ 'Laboratoire' ne peut pas être vide !");
        return;
    }

    if (dated_distribution < QDate::currentDate()) {
        QMessageBox::warning(this, "Validation", "La date ne peut pas être dans le passé !");
        return;
    }

    if (medist_distribution <= 0) {
        QMessageBox::warning(this, "Validation", "Le champ 'Medist' doit être un nombre positif !");
        return;
    }
    Distribution d(id_distribution, qte_distribution, aboratoire_distribution, dated_distribution, medist_distribution);
    bool test = d.ajouter();

    if (test) {
        ui->tableView->setModel(d1.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter une distribution"),
                                 QObject::tr("Distribution ajoutée.\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une distribution"),
                              QObject::tr("Erreur !.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test = tmpDistribution.supprimer(id);

    if (test) {
        ui->tableView->setModel(tmpDistribution.afficher());  // Refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une distribution"),
                                 QObject::tr("Distribution supprimée.\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une distribution"),
                              QObject::tr("Erreur !\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier_clicked()
{
    Distribution dist;  // Utiliser la classe Distribution
    int id = ui->lineEdit_id2->text().toInt();
    int qte = ui->lineEdit_qte2->text().toInt();
    QString aboratoire = ui->comboBox_aboratoire2->currentText();
    QDate dated = ui->dateEdit_4->date();
    if (id <= 0) {
        QMessageBox::warning(this, "Validation", "L'ID doit être un nombre positif !");
        return;
    }

    if (qte <= 0) {
        QMessageBox::warning(this, "Validation", "La quantité doit être un nombre positif !");
        return;
    }

    if (!dist.idExiste(id)) {
        QMessageBox::warning(this, "Validation", "L'ID spécifié n'existe pas dans la base de données !");
        return;
    }
    /*if (aboratoire.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le champ 'Laboratoire' ne peut pas être vide !");
        return;
    }*/

    if (dated < QDate::currentDate()) {
        QMessageBox::warning(this, "Validation", "La date ne peut pas être dans le passé !");
        return;
    }

    // Vérification de l'existence de l'ID dans la base de données
   if (!dist.idExiste(id)) {
        QMessageBox::warning(this, "Validation", "L'ID spécifié n'existe pas dans la base de données !");
        return;
    }

    // Modifier l'enregistrement de la distribution
    bool test = dist.modifier(id, qte);

    if (test)
    {
        // Afficher un message de succès
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        // Forcer le rafraîchissement du modèle
        QSqlQueryModel *model = dist.afficher();  // Si vous utilisez QSqlQueryModel
        ui->tableView_6->setModel(model);  // Appliquer le modèle actualisé
    }
    else
    {
        // Afficher un message d'échec
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Modification non effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_rech_clicked()
{
    Distribution D;
    // Récupérer les valeurs des champs, s'assurer qu'ils sont du bon type
    int id = ui->lineEdit_idr->text().toInt(); // id en tant qu'int
    QString aboratoire = ui->lineEdit_aboratoiree->text(); // aboratoire en tant que QString
    int qte = ui->lineEdit_qtee->text().toInt(); // qte en tant qu'int

    // Passer les bons paramètres à la méthode rech
    QSqlQueryModel* model = D.rech(id, aboratoire, qte);

    // Mettre à jour le tableau avec le modèle retourné
    ui->tableView_4->setModel(model);
}
void MainWindow::on_pushButton_trier_clicked()
{
    Distribution D;

    // Récupérer le critère sélectionné dans le QComboBox
    QString criteria = ui->comboBox->currentText();  // Récupère le texte sélectionné dans le comboBox

    // Effectuer le tri en fonction du critère sélectionné
    QSqlQueryModel* model = nullptr;

    if (criteria == "id") {
        model = D.trierById();
    } else if (criteria == "qte") {
        model = D.trierByQte();
    } else if (criteria == "aboratoire") {
        model = D.trierByAboratoire();
    } else if (criteria == "date") {
        model = D.trierByDate();
    }

    // Appliquer le modèle de tri à la vue (tableView)
    ui->tableView_4->setModel(model);
}

void MainWindow::on_pushButtonPdf_clicked() {
    // Demander à l'utilisateur de choisir l'emplacement du fichier PDF à enregistrer
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer sous"), "", tr("Fichiers PDF (*.pdf)"));

    if (filePath.isEmpty()) {
        return;  // Si l'utilisateur annule, on ne fait rien
    }

    // Créer un QPdfWriter pour générer le fichier PDF
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Portrait);

    // Récupérer les dimensions de la page
    int pageWidth = writer.width();
    int pageHeight = writer.height();
    int margin = 200;
    int usableWidth = pageWidth - 2 * margin;

    QPainter painter(&writer);
    painter.translate(margin, margin);  // Déplacer l'origine du dessin pour tenir compte des marges

    // Définir la police pour le titre du document
    QFont titleFont;
    titleFont.setPointSize(30);
    titleFont.setBold(true);
    painter.setFont(titleFont);
    painter.setPen(QPen(Qt::black));

    // Titre du document
    QString title = "Rapport des Distributions";
    int titleHeight = 100;  // Hauteur du titre
    painter.drawText(0, 0, usableWidth, titleHeight, Qt::AlignCenter, title);

    // Définir la police pour le contenu
    QFont contentFont;
    contentFont.setPointSize(15);
    painter.setFont(contentFont);

    int yOffset = 50;  // Position Y initiale

    // Entêtes des colonnes
    QStringList headers = {"ID", "QTE", "ABORATOIRE", "DATE", "MEDIST"};
    int numColumns = headers.size();
    int columnWidth = usableWidth / numColumns;
    int rowHeight = 400;

    // Dessiner les entêtes des colonnes
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawRect(i * columnWidth, yOffset, columnWidth, rowHeight);
        painter.drawText(i * columnWidth, yOffset, columnWidth, rowHeight, Qt::AlignCenter, headers[i]);
    }

    yOffset += rowHeight;  // Décaler pour commencer à dessiner les données sous les entêtes

    // Récupérer les données de la base de données
    QSqlQuery query("SELECT id, qte, aboratoire, dated, medist FROM distribution");
    while (query.next()) {
        // Vérifier si la page est pleine, et si oui, passer à une nouvelle page
        if (yOffset > pageHeight - margin) {
            writer.newPage();
            yOffset = 200;  // Redémarrer la position verticale

            // Redessiner les entêtes de colonnes
            for (int i = 0; i < headers.size(); ++i) {
                painter.drawRect(i * columnWidth, yOffset, columnWidth, rowHeight);
                painter.drawText(i * columnWidth, yOffset, columnWidth, rowHeight, Qt::AlignCenter, headers[i]);
            }
            yOffset += rowHeight;
        }

        // Remplir les données des lignes
        for (int col = 0; col < numColumns; ++col) {
            QString data;

            switch (col) {
            case 0: data = query.value("id").toString(); break;
            case 1: data = query.value("qte").toString(); break;
            case 2: data = query.value("aboratoire").toString(); break;
            case 3: data = query.value("dated").toDate().toString("dd/MM/yyyy"); break;
            case 4: data = query.value("medist").toString(); break;
            }

            painter.drawRect(col * columnWidth, yOffset, columnWidth, rowHeight);
            painter.drawText(col * columnWidth, yOffset, columnWidth, rowHeight, Qt::AlignCenter, data);
        }

        yOffset += rowHeight;  // Décalage vers le bas pour la prochaine ligne
    }

    painter.end();  // Terminer l'écriture du PDF
    QMessageBox::information(this, tr("Succès"), tr("Le fichier PDF a été généré avec succès."));
}

void MainWindow::on_pushButtonStat_clicked() {
    Distribution dist;

    // Appeler la méthode pour obtenir les statistiques
    QStandardItemModel* model = dist.statistiquesParMedist();

    // Associer le modèle au QTableView
    ui->tableView_statistiques->setModel(model);

    // Optionnel : Ajuster les colonnes pour qu'elles soient bien visibles
    ui->tableView_statistiques->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::afficherGraphique() {
    Distribution dist;
    QStandardItemModel* model = dist.statistiquesParMedist(); // Utiliser la méthode mise à jour

    QBarSeries* series = new QBarSeries();
    QStringList categories; // Liste pour les noms des médicaments

    // Remplir les données à partir du modèle
    for (int i = 0; i < model->rowCount(); ++i) {
        QString medName = model->item(i, 0)->text(); // ID du médicament
        int totalQte = model->item(i, 1)->text().toInt(); // Quantité totale

        QBarSet* set = new QBarSet("Médicament " + medName);
        *set << totalQte;
        series->append(set);

        categories.append("Méd " + medName);
    }

    // Création du graphique
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par Médicament (trié par Quantité)");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Création et configuration des axes
    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Quantité");
    axisY->setRange(0, 100); // Ajustez selon vos données

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Affichage du graphique
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->show();
}


void MainWindow::on_pushButton_ajouterr_clicked()
{
    int idd = ui->lineEdit_idd->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    float distance = ui->lineEdit_distance->text().toFloat();
    Distributeur d1(idd, nom, distance );


    if (idd <= 0) {
        QMessageBox::warning(this, tr("Validation"), tr("L'ID doit être un nombre positif !"));
        return;
    }

    if (nom.isEmpty()) {
        QMessageBox::warning(this, tr("Validation"), tr("Le champ 'Nom' est obligatoire !"));
        return;
    }
    if (d1.nomExiste(nom)) {
        QMessageBox::warning(this, tr("Erreur"), tr("Le nom du distributeur est déjà utilisé. Veuillez en choisir un autre."));
        return; // Ne pas ajouter si le nom existe déjà
    }
    bool test = d1.ajouterr();
    // Vérification de l'unicité de l'ID
    if (test) {
        ui->tableView_6->setModel(d1.afficher1());
        QMessageBox::information(this, tr("Ajouter un distributeur"), tr("Distributeur ajouté avec succès"));



    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de l'ajout du distributeur"));
    }
}
// Supprimer un distributeur de la base de données
void MainWindow::on_pushButton_supprimer1_clicked()
{
    int idd = ui->lineEdit_ids->text().toInt();
    bool test = tmpDistributeur.supprimer1(idd);

    if (test) {
        ui->tableView_6->setModel(tmpDistributeur.afficher1());  // Refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une distributeur"),
                                 QObject::tr("Distributeur supprimée.\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une distributeur"),
                              QObject::tr("Erreur !\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier1_clicked()
{
    Distributeur d1;  // Utiliser la classe Distribution
    int idd = ui->lineEdit_idd1->text().toInt();
    QString nom = ui->lineEdit_nom1->text();
    float distance = ui->lineEdit_distance2->text().toFloat();
    // Validation des champs
    if (idd <= 0) {
        QMessageBox::warning(this, tr("Validation"), tr("L'ID doit être un nombre positif !"));
        return;
    }
    // Modifier l'enregistrement de la distribution
    bool test = d1.modifier1(idd, nom,distance);

    if (test)
    {
        // Afficher un message de succès
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        // Forcer le rafraîchissement du modèle
        QSqlQueryModel *model = d1.afficher1();  // Si vous utilisez QSqlQueryModel
        ui->tableView_6->setModel(model);  // Appliquer le modèle actualisé
    }
    else
    {
        // Afficher un message d'échec
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Modification non effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::mettreAJourListeAboratoires() {
    Distributeur distrib;
    QStringList nomsAboratoires = distrib.obtenirNomsDistributeurs(); // Récupérer les noms des distributeurs

    ui->comboBox_aboratoire->clear(); // Effacer les anciennes entrées
    ui->comboBox_aboratoire->addItems(nomsAboratoires); // Ajouter les nouveaux noms
}
void MainWindow::on_pushButton_auto_clicked() {
    // Étape 1: Récupérer tous les distributeurs et leurs distances
    QSqlQuery query("SELECT nom, distance FROM DISTRIBUTEUR");
    QMap<QString, float> distanceMap; // Pour stocker la distance des laboratoires
    QMap<QString, int> distributionCount; // Pour compter les occurrences des laboratoires

    // Remplir les maps avec les données des distributeurs
    while (query.next()) {
        QString nom = query.value("nom").toString();
        float distance = query.value("distance").toFloat();

        // Stocker la distance
        if (!distanceMap.contains(nom)) {
            distanceMap[nom] = distance;
            distributionCount[nom] = 0; // Initialiser le compteur à zéro
        }
    }

    // Étape 2: Récupérer le nombre de distributions pour chaque laboratoire
    QSqlQuery distributionQuery("SELECT ABORATOIRE, COUNT(*) as count FROM DISTRIBUTION GROUP BY ABORATOIRE");
    while (distributionQuery.next()) {
        QString laboratoire = distributionQuery.value("ABORATOIRE").toString();
        int count = distributionQuery.value("count").toInt();

        if (distributionCount.contains(laboratoire)) {
            distributionCount[laboratoire] = count; // Mettre à jour le compteur
        }
    }

    // Étape 3: Trouver le laboratoire avec le minimum d'occurrences
    QString selectedLaboratoire;
    int minCount = std::numeric_limits<int>::max(); // Initialiser à une valeur très élevée
    float minDistance = std::numeric_limits<float>::max(); // Initialiser à une valeur très élevée

    for (auto it = distributionCount.constBegin(); it != distributionCount.constEnd(); ++it) {
        QString laboratoire = it.key();
        int count = it.value();
        float distance = distanceMap[laboratoire];

        if (count < minCount) {
            minCount = count;
            selectedLaboratoire = laboratoire;
            minDistance = distance; // Mettre à jour la distance minimale
        } else if (count == minCount) {
            // En cas d'égalité, choisir celui avec la distance la plus courte
            if (distance < minDistance) {
                selectedLaboratoire = laboratoire;
                minDistance = distance; // Mettre à jour la distance minimale
            }
        }
    }

    // Étape 4: Mettre à jour l'interface utilisateur
    if (!selectedLaboratoire.isEmpty()) {
        ui->comboBox_aboratoire->setCurrentText(selectedLaboratoire);
        QMessageBox::information(this, tr("Laboratoire Choisi"), tr("Le laboratoire choisi automatiquement est : %1").arg(selectedLaboratoire));
    } else {
        QMessageBox::warning(this, tr("Aucun Laboratoire Disponible"), tr("Tous les laboratoires ont atteint leur maximum de distributions."));
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
