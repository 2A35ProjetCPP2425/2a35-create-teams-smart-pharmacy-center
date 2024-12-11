#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "distribution.h"
#include "distributeur.h"
#include <QMainWindow>
#include <QTableView>
#include <QSqlError>
#include <QFileDialog>
#include <QPainter>

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


private:
    Ui::MainWindow *ui;
    Distribution tmpDistribution;
    Distributeur tmpDistributeur;

    void mettreAJourListeAboratoires();

};


#endif // MAINWINDOW_H

