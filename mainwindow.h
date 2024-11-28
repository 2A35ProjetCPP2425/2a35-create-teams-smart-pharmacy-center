#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "personel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // Explicit keyword added
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    Personel emp;

    void on_addEmployeeButton_clicked();
    void on_supprimerEmploye_clicked();
    void on_modifyEmployeeButton_clicked();
};

#endif // MAINWINDOW_H
