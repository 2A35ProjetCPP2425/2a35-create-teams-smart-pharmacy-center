#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QMessageBox>
#include "personel.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDebug>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "dialog.h"

MainWindow::MainWindow(const QString &email, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->afficher_conge->setModel(emp.afficherconge());



    ui->tableView_2->setModel(emp.afficher());
    displayGenderStatistics();

    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_addEmployeeButton_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::on_supprimerEmploye_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifyEmployeeButton_clicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::on_id_find_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &MainWindow::onclearbutton);
    connect(ui->comboBox_Tri, SIGNAL(currentIndexChanged(int)), this, SLOT(onSortSelectionChanged(int)));
    connect(ui->PDF, &QPushButton::clicked, this, &MainWindow::employetelechargerPDF);
    connect(ui->id_p, &QLineEdit::editingFinished, this, &MainWindow::on_idEmpChanged);
    connect(ui->soumettre, &QPushButton::clicked, this, &MainWindow::on_soumettreButton_clicked);
    populateEmployeeInfo();
    connect(ui->refuser_conge, &QPushButton::clicked, this, &MainWindow::on_refuser_clicked);

    connect(ui->accepter_conge, &QPushButton::clicked, this, &MainWindow::on_acceptation_clicked);
    connect(ui->afficher_conge->selectionModel(), &QItemSelectionModel::selectionChanged,//afficher congé
            this, &MainWindow::onSelectionChanged);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addEmployeeButton_clicked()
{
    // Validation des champs (Nom, Prénom, Email, Salaire, etc.)
    if (ui->nom->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Nom vide !!");
        return;
    }

    // Validation pour les autres champs

    // Création de l'objet 'Personel' et définition des attributs
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString sexe = ui->homme->isChecked() ? "M" : "F"; // Radio buttons pour homme/femme
    QString poste = ui->poste->currentText();
    emp.dateembauche = ui->date_embauche->date(); // Date de l'embauche

    // Définir les attributs pour 'emp'
    emp.setnom(nom);
    emp.setprenom(prenom);
    emp.setsexe(sexe);
    emp.setemail(ui->email->text());
    emp.setsalaire(ui->salaire->text().toDouble());
    emp.setposte(poste);

    // Ajouter l'employé
    bool test = emp.ajouter();

    if (test) {
        // Si l'ajout est réussi, activer 4 bips pour la réussite
        // Dans mainwindow.cpp

        Dialog dialog;  // Création de l'instance de Dialog
        dialog.activateMultipleBuzzerBeep();  // Appel de la méthode
          // Envoie 4 bips avec délai

        // Afficher un message de succès
        QMessageBox::information(this, "Success", "Employee added successfully: " + nom + " " + prenom);

        // Réinitialiser les champs de l'interface après l'ajout
        ui->nom->clear();
        ui->prenom->clear();
        ui->email->clear();
        ui->salaire->clear();
        ui->poste->setCurrentIndex(0);  // Réinitialiser à "choisir poste"
        ui->homme->setChecked(false);   // Décocher le genre
        ui->homme->setAutoExclusive(true);
        ui->femme_2->setAutoExclusive(true);
        ui->confirmation->setChecked(false);  // Décocher la confirmation
        ui->date_embauche->setDate(QDate::currentDate());  // Réinitialiser la date d'embauche à aujourd'hui
    } else {
        // Si l'ajout échoue, afficher un message d'erreur
        QMessageBox::warning(this, "Error", "Failed to add employee.");
    }

    // Mettre à jour la vue des employés
    ui->tableView_2->setModel(emp.afficher());
}


void MainWindow::on_supprimerEmploye_clicked() {
    // Get the ID from the input field
    QString id = ui->id_sup->text();

    // Check if the input field is empty
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "L'ID pour supprimer est vide.");
        return;
    }


    bool exists = emp.idExists(id);
    bool test = emp.supprimer(id);

    if (exists) {
        if (test) {
            QMessageBox::information(this, "Success", "Employé supprimé avec succès.");
            ui->id_sup->clear();
            ui->tableView_2->setModel(emp.afficher());
        } else {
            QMessageBox::warning(this, "Error", "Échec de la suppression de l'employé.");
        }
    } else {
        QMessageBox::warning(this, "Error", "L'ID n'existe pas dans la base de données.");
        return;
    }

}
void MainWindow::on_modifyEmployeeButton_clicked()
{
    // Retrieve the employee ID from a selected row or an input field
    QString id = ui->id_sup->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "L'ID pour modifier est vide.");
        return;
    }

    // Get values from UI elements for each field
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString sexe = ui->homme->isChecked() ? "M" : (ui->femme_2->isChecked() ? "F" : "");
    QString email = ui->email->text();
    float salaire = ui->salaire->text().toFloat();
    QString poste = ui->poste->currentData().toString();
    QDate date_emboche = ui->date_embauche->date();







    // Create an Employe instanc
    // Call the modifier function with the collected values
    bool success = emp.modifier(nom, prenom, sexe, email, salaire,poste, date_emboche, id);
    bool exists = emp.idExists(id);
    if (exists) {
        if(ui->confirmation->isChecked()){
            if (success) {
                QMessageBox::information(this, "Success", "Employee information modified successfully.");
                ui->id_sup->clear();
                ui->tableView_2->setModel(emp.afficher());
                ui->tableView_2->resizeColumnsToContents();

            } else {
                QMessageBox::warning(this, "Failure", "Failed to modify employee information.");
            }
        }else{
            QMessageBox::warning(this, "Failure", "confirmer svp!!.");
        }
    }else{
        QMessageBox::information(this, "Failure", "id pour modifier n'existe pas.");
}

}
void MainWindow::on_id_find_clicked() {
    QString id = ui->id_find->text();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid ID.");
        return;
    }

    // Get the model currently set in the table view
    QSqlQueryModel* model = qobject_cast<QSqlQueryModel*>(ui->tableView_2->model());

    if (!model) {
        QMessageBox::warning(this, "Model Error", "No model found for the table view.");
        return;
    }

    // Select the matching row in the table view
    QModelIndex matchingIndex;
    for (int row = 0; row < model->rowCount(); ++row) {
        // Check if the ID in the first column matches the entered ID
        if (model->index(row, 0).data().toString() == id) {
            matchingIndex = model->index(row, 0); // Select the first column in the matching row
            break;
        }
    }

    if (matchingIndex.isValid()) {
        // Select the matching row
        ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

        QItemSelectionModel* selectionModel = ui->tableView_2->selectionModel();
        selectionModel->select(matchingIndex, QItemSelectionModel::Select | QItemSelectionModel::Rows);

        // Scroll to the selected row to ensure it is visible
        ui->tableView_2->scrollTo(matchingIndex);

        // Row is now highlighted in grey (due to the delegate)
    } else {
        QMessageBox::information(this, "Search Result", "No matching employee found.");
    }
}
void MainWindow::onclearbutton(){
    ui->id_find->clear();

    ui->tableView_2->selectionModel()->clearSelection();

    ui->tableView_2->scrollToTop(); // This will scroll back to the top


}
void MainWindow::onSortSelectionChanged(int index) {
    Qt::SortOrder order;

    // Determine the order based on the index
    if (index == 0) {
        ui->tableView_2->setModel(emp.afficher()); // Show all data without sorting
    }
    else if (index == 1) {
        order = Qt::AscendingOrder;  // Ascending order for SALAIRE
        QSqlQueryModel* sortedModel = emp.tri(order, 9, 1); // Sorting by SALAIRE and then DATE_EMBAUCHE
        ui->tableView_2->setModel(sortedModel);
    }
    else if (index == 2) {
        order = Qt::DescendingOrder; // Descending order for SALAIRE
        QSqlQueryModel* sortedModel = emp.tri(order, 9, 1); // Sorting by SALAIRE and then DATE_EMBAUCHE
        ui->tableView_2->setModel(sortedModel);
    }
    else if (index == 3) {
        order = Qt::AscendingOrder;  // Ascending order for DATE_EMBAUCHE
        QSqlQueryModel* sortedModel = emp.tri(order, 8, 1); // Sorting by DATE_EMBAUCHE and then SALAIRE
        ui->tableView_2->setModel(sortedModel);
    }
    else if (index == 4) {
        order = Qt::DescendingOrder; // Descending order for DATE_EMBAUCHE
        QSqlQueryModel* sortedModel = emp.tri(order, 8, 1); // Sorting by DATE_EMBAUCHE and then SALAIRE
        ui->tableView_2->setModel(sortedModel);
    }

    // Resize columns to fit the content after sorting
    ui->tableView_2->resizeColumnsToContents();
}

void MainWindow::employetelechargerPDF() {
    qDebug() << "Téléchargement du PDF en cours...";  // Vérifier si la fonction est appelée
    emp.telechargerPDF();
}

void MainWindow::displayGenderStatistics()
{
    int maleCount = 0;
    int femaleCount = 0;

    // Requête pour obtenir le nombre d'hommes et de femmes dans la table PERSONNELS
    QSqlQuery query;
    query.prepare("SELECT sexe, COUNT(*) as count FROM PERSONNELS GROUP BY sexe");
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête: " << query.lastError().text();
        return;
    }

    // Traiter les résultats pour attribuer les valeurs à maleCount et femaleCount
    while (query.next()) {
        QString gender = query.value("sexe").toString().toLower(); // Récupère la valeur du sexe
        int count = query.value("count").toInt();                 // Récupère le nombre associé au sexe

        if (gender == "m") {
            maleCount = count;
        } else if (gender == "f") {
            femaleCount = count;
        }
    }

    // --- Creating the Pie Chart ---
    QPieSeries *pieSeries = new QPieSeries();
    QPieSlice *maleSlice = pieSeries->append("Hommes", maleCount);
    QPieSlice *femaleSlice = pieSeries->append("Femmes", femaleCount);

    // Personnalisation des couleurs
    maleSlice->setBrush(QColor("#00008B")); // Bleu foncé
    femaleSlice->setBrush(QColor("#800000")); // Rouge bordeaux

    // Personnalisation des tranches pour ajouter des étiquettes
    for (QPieSlice *slice : pieSeries->slices()) {
        slice->setLabelVisible(true); // Rendre les étiquettes visibles
        slice->setLabel(QString("%1: %2%").arg(slice->label()).arg(slice->percentage() * 100, 0, 'f', 1));
    }

    // --- Creating the Bar Chart ---
    QBarSeries *barSeries = new QBarSeries();
    QBarSet *maleSet = new QBarSet("Hommes");
    QBarSet *femaleSet = new QBarSet("Femmes");

    *maleSet << maleCount;
    *femaleSet << femaleCount;

    barSeries->append(maleSet);
    barSeries->append(femaleSet);

    // --- Pie Chart for 'pie' (QGraphicsView) ---
    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);  // Add the Pie Chart
    pieChart->setTitle("Répartition des genres (Pie)");

    pieChart->setAnimationOptions(QChart::SeriesAnimations);

    // Create the Pie Chart view and set it in the 'pie' graphics view
    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing); // Enable anti-aliasing for better visual quality

    // Size the QChartView to fit the 'pie' view
    pieChartView->setFixedSize(ui->pie->size());

    // Clear the previous scene and add the new view
    QGraphicsScene *pieScene = new QGraphicsScene();
    pieScene->addWidget(pieChartView);
    ui->pie->setScene(pieScene);  // Set the scene for 'pie'

    // Show the pie chart
    ui->pie->show();

    // --- Bar Chart for 'pie2' (QGraphicsView) ---
    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);  // Add the Bar Chart
    barChart->setTitle("Répartition des genres (Bar)");

    barChart->setAnimationOptions(QChart::SeriesAnimations);

    // Create the Bar Chart view and set it in the 'pie2' graphics view
    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing); // Enable anti-aliasing for better visual quality

    // Size the QChartView to fit the 'pie2' view
    barChartView->setFixedSize(ui->pie2->size());

    // Clear the previous scene and add the new view
    QGraphicsScene *barScene = new QGraphicsScene();
    barScene->addWidget(barChartView);
    ui->pie2->setScene(barScene);  // Set the scene for 'pie2'

    // Show the bar chart
    ui->pie2->show();
}



void MainWindow::populateEmployeeInfo()
{
    // Créer une instance de la classe Personel
    Personel emp;
    QString id_emp = ui->id_p->text().trimmed(); // Récupérer et nettoyer l'entrée utilisateur

    // Vérifier si l'identifiant est vide
    if (id_emp.isEmpty()) {

        return;
    }

    // Variables pour stocker les détails de l'employé
    QString nom, prenom, email, poste;

    // Tenter de récupérer les détails de l'employé via l'ID
    bool employeeFound = emp.getEmployeeDetailsById(id_emp, nom, prenom, email, poste);

    // Afficher les détails pour vérification
    qDebug() << "ID:" << id_emp << ", Nom:" << nom << ", Prénom:" << prenom
             << ", Email:" << email << ", Poste:" << poste;

    if (employeeFound) {
        // Si l'employé est trouvé, mettre à jour les champs de l'interface utilisateur
        ui->nom_conge->setText(nom);
        ui->prenom_conge->setText(prenom);
        ui->email_conge->setText(email);
        ui->date_debut->setDate(QDate::currentDate());
        ui->date_fin->setDate(QDate::currentDate());
        ui->poste_conge->setText(poste);

    } else {
        // Si l'employé n'est pas trouvé, afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "Aucun employé trouvé avec l'ID " + id_emp + ".");
        ui->id_p->clear(); // Effacer l'entrée de l'utilisateur
    }
}



void MainWindow::on_idEmpChanged() {
    populateEmployeeInfo();  // Call the function when the ID is changed
}
void MainWindow::refreshTableView()
{
    // Refresh the table model
    QSqlQueryModel *model = emp.afficherconge();
    ui->afficher_conge->setModel(model);

    // Resize the columns to fit content
    ui->afficher_conge->resizeColumnsToContents();

    // Reconnect the selection model to the onSelectionChanged slot
    connect(ui->afficher_conge->selectionModel(),
            &QItemSelectionModel::selectionChanged,
            this,
            &MainWindow::onSelectionChanged);
}
void MainWindow::on_soumettreButton_clicked()
{
    // Créer une instance de la classe Personel
    Personel emp;

    // Récupérer les valeurs des champs du formulaire
    QString id_emp = ui->id_p->text().trimmed();
    QString nom = ui->nom_conge->text().trimmed();
    QString prenom = ui->prenom_conge->text().trimmed();
    QString email = ui->email_conge->text().trimmed();
    QString raison = ui->raison_conge->text().trimmed();
    QString poste = ui->poste_conge->text().trimmed();
    QDate date_d = ui->date_debut->date();
    QDate date_f = ui->date_fin->date();

    // Validation des entrées
    if (id_emp.isEmpty() || nom.isEmpty() || prenom.isEmpty() || email.isEmpty() ||
        raison.isEmpty() || poste.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs avant de soumettre.");
        return;
    }

    // Appeler la méthode ajouterconge pour insérer le congé
    if (emp.ajouterconge(id_emp, nom, prenom, email, raison, poste, date_d, date_f)) {
        QMessageBox::information(this, "Succès", "Le congé a été ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du congé. Veuillez réessayer.");
    }
 ui->afficher_conge->setModel(emp.afficherconge());
}
void MainWindow::onSelectionChanged(const QItemSelection &selected)
{
    // Check if something is selected
    if (!selected.isEmpty()) {
        // Get the first selected index (row, column)
        QModelIndex index = selected.indexes().first();

        // Check if the selected column is the one containing the 'id_conge' (assuming column 0)
        if (index.column() == 0) {
            // Retrieve the 'id_conge' from the model (assuming it's the first column)
            QString id_conge = ui->afficher_conge->model()->data(index).toString();

            // Set the 'id_conge' value in the QLineEdit (id_emp_3)
            ui->id_emp3->setText(id_conge);

            // Enable the buttons (assuming buttons are named acceptation and refuser)
            ui->accepter_conge->setEnabled(true);
            ui->refuser_conge->setEnabled(true);
        }
    }
}
void MainWindow::on_acceptation_clicked()
{
    // Get the selected index from the table view
    QModelIndexList selectedIndexes = ui->afficher_conge->selectionModel()->selectedRows();

    // Check if there is a selection
    if (!selectedIndexes.isEmpty()) {
        // Get the first selected row (we assume it's a single row selection)
        QModelIndex index = selectedIndexes.first();

        // Get the 'id_conge' from the selected row (assuming it's in column 0)
        QString id_conge = ui->afficher_conge->model()->data(index.sibling(index.row(), 0)).toString();

        // Call the method in Personel.cpp to update the 'etat' column
        Personel employe;
        if (employe.updateCongeStatus(id_conge, "accepté")) {
            qDebug() << "Record updated successfully!";
        } else {
            qDebug() << "Error updating record!";
        }
    }

    // Refresh the table view
    QSqlQueryModel *model = emp.afficherconge();
    ui->afficher_conge->setModel(model);

    // Optionally, resize the columns to fit the content
    ui->afficher_conge->resizeColumnsToContents();

    // Clear any input fields (if applicable)
    ui->id_emp3->clear();
    refreshTableView();
    ui->afficher_conge->setModel(emp.afficherconge());
}
void MainWindow::on_refuser_clicked()
{
    // Get the selected index from the table view
    QModelIndexList selectedIndexes = ui->afficher_conge->selectionModel()->selectedRows();

    // Check if there is a selection
    if (!selectedIndexes.isEmpty()) {
        // Get the first selected row (we assume it's a single row selection)
        QModelIndex index = selectedIndexes.first();

        // Get the 'id_conge' from the selected row (assuming it's in column 0)
        QString id_conge = ui->afficher_conge->model()->data(index.sibling(index.row(), 0)).toString();

        // Call the method in Personel.cpp to update the database
        Personel employe;
        if (employe.updateCongeStatus(id_conge, "refusé")) {
            qDebug() << "Record updated successfully!";
        } else {
            qDebug() << "Error updating record!";
        }
    }

    // Refresh the table view to reflect database changes
    QSqlQueryModel *model = emp.afficherconge();
    ui->afficher_conge->setModel(model);

    // Optionally, resize the column to fit the content
    ui->afficher_conge->resizeColumnsToContents();

    // Clear the selection after update
    ui->afficher_conge->selectionModel()->clearSelection();

    // Disable the buttons when no row is selected
    ui->accepter_conge->setEnabled(false);
    ui->refuser_conge->setEnabled(false);
    refreshTableView();
    ui->afficher_conge->setModel(emp.afficherconge());
}


