#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "distribution.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QLayout>
#include <QVBoxLayout>
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
    mettreAJourListeAboratoires();   // Appel à la méthode de la classe parente

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
        QSqlQueryModel *model = d.afficher();  // Si vous utilisez QSqlQueryModel

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
    //QString aboratoire = ui->comboBox_aboratoire2->currentText();
    QDate dated = ui->dateEdit_4->date();
    int medist = ui->lineEdit_medist_2->text().toInt();
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
    bool test = dist.modifier(id, qte, dated, medist);

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

void MainWindow::on_pushButtonPdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer en tant que PDF", "", "Fichiers PDF (*.pdf);;Tous les fichiers ()");
    if (fileName.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageOrientation(QPageLayout::Portrait);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);

    // Remplacez ui->tableView par la vue ou le modèle spécifique à votre application
    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter.");
        return;
    }

    int x = 20;
    int y = 200;
    int rowHeight = 50;
    int columnWidth = 340; //

    // Dessiner l'en-tête
    QColor headerColor(100, 149, 237);
    QColor altRowColor(240, 248, 255);
    QColor textColor(25, 25, 112);
    QFont font = painter.font();
    font.setPointSize(10);
    painter.setFont(font);

    painter.setBrush(QBrush(headerColor));
    painter.setPen(QPen(Qt::white));

    for (int column = 0; column < model->columnCount(); ++column) {
        QRect rect(x + column * columnWidth, y, columnWidth, rowHeight);
        painter.drawRect(rect);
        painter.drawText(rect, Qt::AlignCenter, model->headerData(column, Qt::Horizontal).toString());
    }

    y += rowHeight;

    // Dessiner les lignes de données
    painter.setPen(QPen(textColor));
    for (int row = 0; row < model->rowCount(); ++row) {
        QColor rowColor = (row % 2 == 0) ? Qt::white : altRowColor;
        painter.setBrush(QBrush(rowColor));

        for (int column = 0; column < model->columnCount(); ++column) {
            QRect rect(x + column * columnWidth, y + row * rowHeight, columnWidth, rowHeight);
            painter.drawRect(rect);
            painter.drawText(rect.adjusted(5, 0, -5, 0), Qt::AlignVCenter | Qt::AlignLeft, model->data(model->index(row, column)).toString());
        }
    }

    // Titre
    painter.setPen(QPen(QColor(0, 51, 102)));
    QFont titleFont("Arial", 25, QFont::Bold);
    painter.setFont(titleFont);
    QString title = "les Distribution";
    int pageWidth = pdfWriter.width();
    int textWidth = painter.fontMetrics().horizontalAdvance(title);
    int centeredX = (pageWidth - textWidth) / 2;
    painter.drawText(centeredX, 85, title);

    // Ajouter un logo
    QPixmap logo("C:/Users/eya_d/OneDrive/Bureau/pharma2025/logo.png");
    if (logo.isNull()) {
        qDebug() << "Le logo n'a pas pu être chargé. Vérifiez le chemin du fichier.";
    } else {
        int logoWidth = 250;  // Ajustez la taille du logo si nécessaire
        int logoHeight = 300;
        int logoX = pageWidth - logoWidth - 20;
        int logoY = 20;

        painter.drawPixmap(logoX, logoY, logoWidth, logoHeight, logo);
    }

    painter.end();

    QMessageBox::information(this, "Exportation réussie", "Les données ont été exportées avec succès.");
}

void MainWindow::on_pushButtonStat_clicked() {
    Distribution distribution;
    QStandardItemModel* model = distribution.statistiquesParMedist();
    ui->tableView_statistiques->setModel(model);

    // Optionnel : Ajuster les colonnes pour qu'elles soient bien visibles
    ui->tableView_statistiques->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    if (!model || model->rowCount() == 0) {
        qDebug() << "Aucune donnée trouvée pour les statistiques.";
        return;
    }

    // Créer une série pour le graphique à secteurs
    QPieSeries *series = new QPieSeries();

    // Parcourir le modèle pour ajouter les données au graphique
    for (int row = 0; row < model->rowCount(); ++row) {
        QString medist = model->data(model->index(row, 0)).toString(); // Récupère l'ID du médicament
        int totalQte = model->data(model->index(row, 1)).toInt();     // Récupère la quantité totale

        // Ajouter un segment pour chaque médicament
        QPieSlice *slice = series->append(medist, totalQte);

        // Rendre les étiquettes visibles et ajouter des détails (quantité et pourcentage)
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1: %2 (%3%)")
                            .arg(medist)
                            .arg(totalQte)
                            .arg(slice->percentage() * 100, 0, 'f', 1));
    }

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des quantités par médicament");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Configurer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Définir une taille fixe pour le graphique
    chartView->setFixedSize(600, 400); // Ajustez cette taille si nécessaire

    // Ajouter le graphique dans la QGraphicsView
    ui->graphicsView->setScene(new QGraphicsScene());
    ui->graphicsView->scene()->addWidget(chartView);

    // Ajuster la vue pour afficher correctement le graphique
    ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);

    // Rafraîchir la scène
    ui->graphicsView->scene()->update();
    ui->graphicsView->show();
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
        return;
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
            distributionCount[nom] = 0;
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
