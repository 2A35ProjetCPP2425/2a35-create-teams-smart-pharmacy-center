#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD
=======
#include "arduino.h"
>>>>>>> 8fb8c24 (Deuxieme commit)
#include "distribution.h"
#include "distributeur.h"
#include <QMainWindow>
#include <QTableView>
#include <QSqlError>
#include <QFileDialog>
#include <QPainter>
<<<<<<< HEAD

=======
#include <QSqlDatabase>
#include <QSerialPort>

#include <QSerialPortInfo>
>>>>>>> 8fb8c24 (Deuxieme commit)
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void showEvent(QShowEvent *event) override;  // Ajoutez cette ligne

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();


    void on_pushButton_modifier_clicked();

    void on_pushButton_rech_clicked();
    void on_pushButton_trier_clicked();
    void on_pushButtonPdf_clicked();
    void on_pushButtonStat_clicked();
    void on_pushButton_ajouterr_clicked();
    void on_pushButton_supprimer1_clicked();
    void on_pushButton_modifier1_clicked();
    void on_pushButton_auto_clicked();
<<<<<<< HEAD
=======
    void updateTemperatureDisplay(float temperature);


>>>>>>> 8fb8c24 (Deuxieme commit)


private:
    Ui::MainWindow *ui;
    Distribution tmpDistribution;
    Distributeur tmpDistributeur;
<<<<<<< HEAD
    void afficherGraphique();
    void mettreAJourListeAboratoires();
   // QString choisirLaboratoireProche(const QString& aboratoire);
        // Modèle pour afficher les données des clients dans un QTableView
=======

    void mettreAJourListeAboratoires();

    QTableView *tableView;  // Le QTableView pour afficher la température
    QStandardItemModel *model;  // Le modèle de données pour le QTableView
    Arduino *arduino;
>>>>>>> 8fb8c24 (Deuxieme commit)


};


#endif // MAINWINDOW_H

