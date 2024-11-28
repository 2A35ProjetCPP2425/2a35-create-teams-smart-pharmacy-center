#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"MEDICAMENTS.h"
#include"QMessageBox"
#include <QSqlQuery>
#include <QSqlError>  // Pour capturer les erreurs SQL si nécessaire
#include <QSqlDatabase>  // Si ce n'est pas déjà inclus
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    connect(ui->buttonDisplayStats, &QPushButton::clicked, this, &MainWindow::displayMedicamentCategoryStatistics);
    connect(ui->pushButton_showPriceStats, &QPushButton::clicked, this, &MainWindow::displayMedicationPriceStatistics);




}


/*void MainWindow::on_pushButton_clicked()
{

}*/


void MainWindow::on_pushButton_clicked()
{
    // Récupérer les données saisies
    int ID = ui->lineEdit_5->text().toInt();
    int QTESTOCK = ui->lineEdit_4->text().toInt();
    QString CATEGORIE = ui->comboBox->currentText();
    QDate DATDEXP = ui->dateEdit->date();
    QString NOM = ui->lineEdit_2->text();
    float PRIX = ui->lineEdit_9->text().toFloat();

    // 1. Vérification des champs vides
    if (NOM.isEmpty() || ID <= 0 || QTESTOCK <= 0 || PRIX <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // 2. Vérification que l'ID n'existe pas déjà
    M.fset(ID, QTESTOCK, CATEGORIE, DATDEXP, NOM, PRIX);
    if (M.existe()) {
        QMessageBox::warning(this, "Erreur", "Un médicament avec cet ID existe déjà.");
        return;
    }

    // 3. Vérification que la date de péremption est dans le futur
    if (DATDEXP < QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date de péremption doit être dans le futur.");
        return;
    }

    // 4. Ajouter le médicament
    if (M.ajout()) {
        QMessageBox::information(this, "Ajout", "Ajout avec succès");
        ui->tableView->setModel(M.afficher());
    } else {
        QMessageBox::warning(this, "Erreur", "Ajout échoué.");
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int ID = ui->lineEdit_5->text().toInt();
    int QTESTOCK = ui->lineEdit_4->text().toInt();
    QString CATEGORIE = ui->comboBox->currentText(); // Utilisez currentText() pour obtenir l'élément sélectionné
    QDate DATDEXP = ui->dateEdit->date();
    QString NOM = ui->lineEdit_2->text();
    float PRIX = ui->lineEdit_9->text().toFloat();

    M.fset(ID, QTESTOCK, CATEGORIE, DATDEXP, NOM, PRIX);

    // Vérifier si l'ID existe dans la base de données avant de modifier
    if (M.existe()) {
        if (M.modifier()) {
            QMessageBox::information(nullptr, "Modification", "Modification réussie");
            ui->tableView->setModel(M.afficher());
        } else {
            QMessageBox::warning(nullptr, "Erreur", "Modification échouée");
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Cet ID n'existe pas dans la base de données");
    }
}

void MainWindow::on_pushButton_supprimer_clicked() {
    int ID = ui->lineEdit_5->text().toInt();
    M.fset(ID, 0, "", QDate(), "", 0);  // On n'a besoin que de l'ID pour supprimer
    if (M.existe()) {
    if (M.supprimer()) {  // Appel de la méthode supprimer() sur l'objet M
        QMessageBox::information(nullptr, "Suppression", "Suppression réussie");
        ui->tableView->setModel(M.afficher());
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Suppression échouée");
    }
    }
    else{
        QMessageBox::warning(nullptr, "Erreur", "Cet ID n'existe pas dans la base de données");
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_trierID_clicked()
{
    ui->tableView->setModel(M.trierParID());  // Appliquer le tri par ID
}



void MainWindow::on_pushButton_trierNom_clicked()
{
    ui->tableView->setModel(M.trierParNom());  // Appliquer le tri par NOM

}
void MainWindow::on_pushButton_statistiques_clicked()
{
    // Récupérer le modèle des statistiques par catégorie
    QSqlQueryModel* model = M.statistiquesParCategorie();

    // Mettre à jour la QTableView pour afficher les statistiques
    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_rechercher_clicked()
{
    // Récupérer l'ID saisi dans le QLineEdit
    int idRecherche = ui->lineEdit_id->text().toInt(); // Remplacez "lineEdit_id" par l'ID de votre QLineEdit

    // Effectuer la recherche par ID
    QSqlQueryModel* model = M.rechercheParID(idRecherche);

    // Vérifier si le modèle n'est pas null et afficher dans la QTableView
    if (model) {
        ui->tableView->setModel(model);
    } else {
        // Si la recherche échoue, vous pouvez afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "Aucun médicament trouvé avec cet ID.");
    }
}

void MainWindow::on_pushButton_consommer_clicked()
{
    // Récupérer l'ID et la quantité consommée des QLineEdit
    int id = ui->lineEdit->text().toInt();  // ID du médicament
    int quantiteConsommee = ui->lineEdit_6->text().toInt();  // Quantité consommée

    // Appeler la méthode consommer
    bool success = M.consommer(id, quantiteConsommee);

    // Si la consommation a réussi
    if (success) {
        // Vérifier le stock après la mise à jour
        QSqlQuery query;
        query.prepare("SELECT QTESTOCK FROM MEDICAMENTS WHERE ID = :id");
        query.bindValue(":id", id);

        if (query.exec()) {
            if (query.next()) {
                int stockRestant = query.value(0).toInt();

                // Vérifier si le stock est épuisé
                if (stockRestant <= 0) {
                    QMessageBox::warning(this, "Erreur", "Le stock de ce médicament est terminé.");
                } else {
                    QMessageBox::information(this, "Succès", "La consommation a été mise à jour.");
                }
            } else {
                QMessageBox::critical(this, "Erreur", "Impossible de récupérer les informations du stock.");
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la requête SQL.");
        }
    } else {
        // Si la consommation a échoué, afficher un message d'erreur
        QMessageBox::critical(this, "Erreur", "STOCK INSUFFISANT!");
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView_2->setModel(M.afficher());
}


void MainWindow::on_pushButton_8_clicked()
{
    // Récupérer l'ID et la quantité à ajouter des QLineEdit
    int id = ui->lineEdit_7->text().toInt();  // ID du médicament
    int quantiteAjoutee = ui->lineEdit_8->text().toInt();  // Quantité à ajouter

    // Appeler la méthode ajouterQuantite
    bool success = M.ajouterQuantite(id, quantiteAjoutee);

    // Si l'ajout a réussi, afficher un message de succès
    if (success) {
        QMessageBox::information(this, "Succès", "La quantité a été ajoutée avec succès.");
    } else {
        // Si l'ajout a échoué, afficher un message d'erreur
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de la quantité.");
    }
}



void MainWindow::on_pushButton_7_clicked()
{
    ui->tableView_3->setModel(M.afficher());
}
void MainWindow::on_Pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer PDF"), "", tr("PDF Files (*.pdf)"));
    if (filePath.isEmpty()) {
        return; // L'utilisateur a annulé l'enregistrement
    }

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&writer);

    // Définir la police et la taille
    QFont font("Arial", 12);
    painter.setFont(font);

    // Titre
    painter.drawText(3000, 0, "Liste des MEDICAMENTS");
    painter.drawLine(100, 110, 500, 110); // Ligne sous le titre

    // Récupérer les données de la base de données
    QSqlQuery query("SELECT * FROM MEDICAMENTS");
    int y = 130; // Position de départ pour écrire les données
    int margin = 50; // Marges

    while (query.next()) {
        // Récupérer les valeurs
        QString id = query.value("ID").toString();
        QString nom = query.value("NOM").toString();
        QString DATDEXP = query.value("DATDEXP").toString();
        QString QTESTOCK = query.value("QTESTOCK").toString();
        QString PRIX = query.value("PRIX").toString();
        QString CATEGORIE = query.value("CATEGORIE").toString();

        // Écrire chaque champ sur une nouvelle ligne avec un en-tête
        painter.drawText(margin, y, QString("MEDICAMENTS ID: %1").arg(id));
        y += 290; // Augmenter l'espacement entre Article ID et Nom
        painter.drawText(margin, y, QString("NOM: %1").arg(nom));
        y += 290;
        painter.drawText(margin, y, QString("DATDEXP: %1").arg(DATDEXP));
        y += 290;
        painter.drawText(margin, y, QString("QTESTOCK: %1").arg(QTESTOCK));
        y += 290;
        painter.drawText(margin, y, QString("PRIX: %1").arg(PRIX));
        y += 290;
        painter.drawText(margin, y, QString("CATEGORIE: %1").arg(CATEGORIE));
        y += 290; // Espacement supplémentaire avant le prochain article
        painter.drawLine(margin, y, 500, y); // Ligne de séparation entre les articles
        y += 290; // Espacement après la ligne de séparation

        // Vérifier si on dépasse la hauteur de la page
        if (y > writer.height() - 100) {
            painter.end();
            writer.newPage(); // Créer une nouvelle page si nécessaire
            painter.begin(&writer);
            painter.setFont(font); // Redéfinir la police
            y = 100; // Réinitialiser la position y
        }
    }

    painter.end();

    // Afficher un message de succès
    QMessageBox::information(this, tr("Succès"), tr("Les données ont été exportées vers le PDF avec succès."));
}

void MainWindow::displayMedicamentCategoryStatistics()
{
    // Initialize categories for X-axis (medication categories)
    QStringList categories;
    QMap<QString, int> categoryCounts; // Map to store category names and corresponding quantities

    // Query to fetch total stock grouped by category
    QSqlQuery query;
    query.prepare(
        "SELECT categorie, SUM(qtestock) as total_stock "
        "FROM medicaments "
        "GROUP BY categorie "
        "ORDER BY categorie"
    );

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Prepare data for the chart
    QBarSet *set = new QBarSet("Stock Quantity"); // Data set for the bar chart

    while (query.next()) {
        QString category = query.value("categorie").toString(); // Get the category
        int totalStock = query.value("total_stock").toInt();    // Get the total stock

        categoryCounts[category] = totalStock; // Store the category and stock in the map
    }

    // Populate the QBarSet and X-axis categories
    for (const QString &key : categoryCounts.keys()) {
        *set << categoryCounts[key]; // Add stock to the bar set
        categories << key;           // Add category to the X-axis labels
    }

    // Create the bar series and add the dataset
    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Create the chart and set its properties
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Medication Stock by Category");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Set up the X-axis (categories)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories); // Add category labels
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Set up the Y-axis (values)
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Stock Quantity");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view and set antialiasing
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set a fixed size for the chart view to make it smaller
    chartView->setFixedSize(600, 400); // Adjust the size as needed

    // Set up the QGraphicsView
    ui->graphicsView->setScene(new QGraphicsScene());

    // Add the chart view to the scene
    ui->graphicsView->scene()->addWidget(chartView);

    // Adjust the view to fit the scene
    ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);

    // Refresh the scene and display the chart
    ui->graphicsView->scene()->update();
    ui->graphicsView->show();
}



void MainWindow::displayMedicationPriceStatistics()
{
    // Query to group medications by price ranges
    QSqlQuery query;
    query.prepare(
        "SELECT price_range, COUNT(*) AS count "
        "FROM ( "
        "  SELECT "
        "    CASE "
        "      WHEN prix BETWEEN 0 AND 10 THEN '0-10' "
        "      WHEN prix BETWEEN 11 AND 20 THEN '11-20' "
        "      WHEN prix BETWEEN 21 AND 50 THEN '21-50' "
        "      WHEN prix > 50 THEN '>50' "
        "    END AS price_range "
        "  FROM medicaments "
        ") subquery "
        "GROUP BY price_range "
        "ORDER BY price_range"
    );

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Create a Pie Chart Series
    QPieSeries *series = new QPieSeries();

    // Process the query results and populate the pie chart series
    while (query.next()) {
        QString priceRange = query.value("price_range").toString();
        int count = query.value("count").toInt();
        series->append(priceRange, count); // Add price range and count to the series
    }

    // Calculate the total value of the series
    qreal totalValue = 0;
    for (const QPieSlice *slice : series->slices()) {
        totalValue += slice->value();
    }

    // Update each slice with proper labels
    for (QPieSlice *slice : series->slices()) {
        qreal percentage = (slice->value() / totalValue) * 100.0; // Calculate percentage
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1: %2 (%3%)")
                            .arg(slice->label())        // Price range
                            .arg(slice->value())        // Total count
                            .arg(percentage, 0, 'f', 1)); // Correct percentage
    }

    // Create the chart and add the pie series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Medication Price Distribution");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Create a chart view and set antialiasing for better visuals
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set a fixed size for the chart view
    chartView->setFixedSize(600, 400); // Adjust the size as needed

    // Set up the QGraphicsView
    ui->graphicsView->setScene(new QGraphicsScene());

    // Add the chart view to the scene
    ui->graphicsView->scene()->addWidget(chartView);

    // Use fitInView to make sure the chart fits within the view's scene, but keep the aspect ratio
    ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);

    // Refresh the scene and display the chart
    ui->graphicsView->scene()->update();
    ui->graphicsView->show();
}
