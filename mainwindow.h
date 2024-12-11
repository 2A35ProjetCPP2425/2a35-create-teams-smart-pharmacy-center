#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


#include "service.h"
#include "rendezvous.h"
#include "QLabel"
#include <QTableView>
#include <QFileDialog>
#include <QLineEdit>  // Ajouté pour le champ de recherche
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QSerialPort>
#include "arduino.h"
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:







void on_btn_clicked(); // Vérifier la salle
void mettreAJourStatutSalle(int numSalle, const QString &nouveauStatut);
void refreshSalleView();
void on_ajouterButton_clicked();
void on_afficherButton_clicked();
void on_supprimerButton_clicked();
void on_modifierButton_clicked();
void on_pushButton_generatePDF_clicked();
void filterServices();  // Ajout de la fonction de filtre
void on_comboboxSort_currentIndexChanged(int index);
void on_btnAjouter_clicked();
void on_btnAfficher_clicked();
void on_btnModifier_clicked();
void on_combobox_currentIndexChanged(int index);
void on_comboBoxT_currentIndexChanged(int index);
void filterRendezvous();
void on_btnMettreAJourStatut_clicked();
void on_afficher_clicked();




private:
    Ui::MainWindow *ui;



    Arduino *arduino; // Objet Arduino
    QString salleStatus; // Status de la salle



    service currentService;
    QLineEdit *searchBar;
    QLineEdit *searchBar1;
    QMap<QString, int> recupererStatistiquesRendezvous();
    QMap<QString, int> recupererStatistiquesServices();
    void afficherStatistiquesServices(QMap<QString, int> stats);
    void afficherStatistiquesRendezvous(QMap<QString, int> stats);



};
#endif // MAINWINDOW_H
