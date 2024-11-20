#include "mainwindow.h"
#include "gestion_achat.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QStandardItemModel>


void MainWindow::on_pushButton_ajouter_clicked()
{
    int id_achat=ui->lineEdit_ida->text().toInt();
    QString nom =ui->lineEdit_nom->text();
    int quantite=ui->lineEdit_q->text().toInt();
    float prix = ui->lineEdit_prix->text().toFloat();
    QDate date_achat=ui->dateEdit_datea->date();
    int id_perso=ui->lineEdit_idp->text().toInt();
 gestion_achat g(id_achat,nom,quantite,prix,date_achat,id_perso);
 bool test=g.ajouter();
         if (test)
 {
             ui->tableView->setModel(etmp.afficher());
         QMessageBox ::information(nullptr,QObject::tr("ok"),
                                  QObject::tr("ajout effectué.\n"
                                              "click cancel to exit") , QMessageBox::Cancel);
}
         else {
         QMessageBox::critical(nullptr,QObject::tr("not ok"),
                               QObject::tr("ajout non effectué.\n"
                                           "click cancel to exit"),QMessageBox::Cancel);
         }
};

MainWindow::MainWindow(QWidget * parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
}
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
qDebug() << "Row activated:" << index.row();
}
void MainWindow::on_pushButton_supprimer_clicked( )
{
    int id_achat =ui->lineEdit_supprimer->text().toInt();
    bool test = etmp.supprimer(id_achat);
    if (test)
    { QMessageBox::information(nullptr,QObject::tr("ok"),
                               QObject::tr("suppressipn effectueé\n"
                                           "click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non affectueé\n"
                              "click cancel to exit."),QMessageBox::Cancel);
}
void MainWindow::on_pushButton_modifier_clicked()
{
    int id_achat = ui->lineEdit_idn->text().toInt();
    QString nom = ui->lineEdit_nouveau_nom->text();
    int quantite = ui->lineEdit_nouvelle_quantite->text().toInt();
    float prix = ui->lineEdit_nouveau_prix->text().toDouble();
    QDate date_achat = ui->dateEdit_datea->date();
    int id_perso = ui->lineEdit_idp2->text().toInt();

    bool test = etmp.modifier(id_achat, nom, quantite, prix, date_achat, id_perso);
    if (test) {
        QMessageBox::information(this, "Succès", "Données mises à jour avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour des données.");
    }
}

