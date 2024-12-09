#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "personel.h"
#include "qitemselectionmodel.h"
#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString &email, QWidget *parent = nullptr);  // Explicit keyword added
    ~MainWindow();

    void employetelechargerPDF();
    void populateEmployeeInfo();
    void on_idEmpChanged();
    void on_soumettreButton_clicked();
    void on_acceptation_clicked();
    void on_refuser_clicked();
    void refreshTableView();
    void on_addEmployeeButton_clicked();



private slots:
    void onSortSelectionChanged(int index);
    void displayGenderStatistics();
    void onSelectionChanged(const QItemSelection &selected);

private:
    Ui::MainWindow *ui;
    Personel emp;


    void on_supprimerEmploye_clicked();
    void on_modifyEmployeeButton_clicked();
    void on_id_find_clicked();
    void onclearbutton();};




#endif // MAINWINDOW_H
