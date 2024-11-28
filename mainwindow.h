#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"MEDICAMENTS.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

/*private slots:
    void on_pushButton_clicked();*/

private slots:
    void on_pushButton_clicked();


    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_trierID_clicked();

    void on_pushButton_trierNom_clicked();

    void on_pushButton_statistiques_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_consommer_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_Pdf_clicked();

    void displayMedicamentCategoryStatistics();
    void displayMedicationPriceStatistics();

private:
    Ui::MainWindow *ui;
    MEDICAMENTS M;
};
#endif // MAINWINDOW_H
