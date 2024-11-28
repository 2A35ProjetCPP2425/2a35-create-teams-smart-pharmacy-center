#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QMessageBox>
#include "personel.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView_2->setModel(emp.afficher());

    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_addEmployeeButton_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::on_supprimerEmploye_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifyEmployeeButton_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addEmployeeButton_clicked()
{
    // Validate 'nom'

    if (ui->nom->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Nom vide !!");
        return;
    }

    // Validate 'prenom'
    if (ui->prenom->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Prenom vide !!");
        return;
    }

    // Validate 'email' format using regex
    QString email = ui->email->text();
    QRegularExpression emailRegex(R"((\w+)(\.?[\w-]+)*@([\w-]+\.)+[\w-]{2,})");
    QRegularExpressionValidator emailValidator(emailRegex);
    int emailPos = 0;
    if (ui->email->text().isEmpty() || emailValidator.validate(email, emailPos) != QValidator::Acceptable) {
        QMessageBox::warning(this, "Input Error", "Email vide ou invalide !!");
        return;
    }

    // Validate 'salaire' input is numeric
    bool salaireOk;
    double salaire = ui->salaire->text().toDouble(&salaireOk);
    if (!salaireOk || salaire <= 0) {
        QMessageBox::warning(this, "Input Error", "Salaire vide ou invalide !!");
        return;
    }
    if (ui->poste->currentText() == "choisir poste") {
        QMessageBox::warning(this, "Input Error", "Choisir un poste valide.");
        return;
    }

    // Validate 'genre' selection
    if (!ui->homme->isChecked() && !ui->femme_2->isChecked()) {
        QMessageBox::warning(this, "Input Error", "Choisir votre genre.");
        return;
    }

    // Get values from UI elements and set to the 'Employe' object
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString sexe = ui->homme->isChecked() ? "M" : "F"; // Radio buttons for male/female
    QString poste = ui->poste->currentText();
    emp.dateembauche = ui->date_embauche->date(); // Date from QDateEdit widget
    // Set employee attributes
    emp.setnom(nom);
    emp.setprenom(prenom);
    emp.setsexe(sexe);
    emp.setemail(email);
    emp.setsalaire(salaire);
    emp.setposte(poste);




    bool test = emp.ajouter();
    if (test) {
        QMessageBox::information(this, "Info", "Test is: " + QString::number(test));
    }

    // Check for confirmation
    if (ui->confirmation->isChecked()) {
        if (test) {
            QMessageBox::information(this, "Success", "Employee added successfully: " + nom + " " + prenom);
            // Reset UI fields after successful addition
            ui->nom->clear();
            ui->prenom->clear();
            ui->email->clear();
            ui->salaire->clear();
            ui->poste->setCurrentIndex(0);        // Reset to default "choose poste"
            ui->homme->setChecked(false);         // Uncheck gender selection
            ui->homme->setAutoExclusive(true);    // Re-enable exclusivity
            ui->femme_2->setAutoExclusive(true);
            ui->confirmation->setChecked(false);  // Uncheck confirmation checkbox
            ui->date_embauche->setDate(QDate::currentDate()); // Reset date to today
        } else {
            QMessageBox::warning(this, "Error", "Failed to add employee.");
        }
    } else {
        QMessageBox::warning(this, "Error", "You must confirm the addition of the employee.");
    }
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
