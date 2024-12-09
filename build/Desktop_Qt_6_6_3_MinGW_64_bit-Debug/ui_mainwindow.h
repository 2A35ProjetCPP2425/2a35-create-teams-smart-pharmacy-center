/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_13;
    QFrame *frame_14;
    QLineEdit *lineEdit_idd;
    QLineEdit *lineEdit_nom;
    QLabel *label_13;
    QLabel *label_18;
    QPushButton *pushButton_ajouterr;
    QPushButton *pushButton_10;
    QLabel *label_23;
    QLineEdit *lineEdit_distance;
    QLabel *label_43;
    QLabel *label_48;
    QFrame *frame_38;
    QTableView *tableView_6;
    QLabel *label_76;
    QFrame *frame_30;
    QFrame *frame_31;
    QLineEdit *lineEdit_idd1;
    QLineEdit *lineEdit_nom1;
    QLabel *label_14;
    QLabel *label_77;
    QPushButton *pushButton_modifier1;
    QPushButton *pushButton_28;
    QLineEdit *lineEdit_distance2;
    QLabel *label_24;
    QWidget *tab_4;
    QFrame *frame_5;
    QFrame *frame_6;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_qte;
    QDateEdit *dateEdit_date;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_6;
    QLabel *label_19;
    QLineEdit *lineEdit_medist;
    QPushButton *pushButton_auto;
    QComboBox *comboBox_aboratoire;
    QFrame *frame_7;
    QFrame *frame_8;
    QLineEdit *lineEdit_id2;
    QLineEdit *lineEdit_qte2;
    QDateEdit *dateEdit_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_modifier;
    QLineEdit *lineEdit_medist_2;
    QLabel *label_20;
    QLabel *label_16;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_27;
    QComboBox *comboBox_aboratoire2;
    QFrame *frame_16;
    QTableView *tableView;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_32;
    QFrame *frame_24;
    QPushButton *pushButtonPdf;
    QLabel *label_37;
    QWidget *tab_5;
    QFrame *frame_32;
    QFrame *frame_34;
    QLabel *label_44;
    QTableView *tableView_4;
    QLabel *label_79;
    QFrame *frame_33;
    QFrame *frame_35;
    QLabel *label_45;
    QLabel *label_74;
    QLineEdit *lineEdit_qtee;
    QLineEdit *lineEdit_idr;
    QPushButton *pushButton_rech;
    QLabel *label_78;
    QLabel *label_91;
    QLineEdit *lineEdit_aboratoiree;
    QFrame *frame_36;
    QFrame *frame_40;
    QLabel *label_49;
    QPushButton *pushButton_trier;
    QComboBox *comboBox;
    QLabel *label_80;
    QLabel *label_87;
    QFrame *frame_21;
    QFrame *frame_22;
    QLabel *label_35;
    QLineEdit *lineEdit_id_2;
    QLineEdit *lineEdit_ids;
    QLabel *label_36;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_supprimer1;
    QLabel *label_88;
    QWidget *tab_6;
    QPushButton *pushButtonStat;
    QFrame *frame_19;
    QFrame *stat_3;
    QGraphicsView *graphicsView;
    QLabel *vboxLayout_stats;
    QFrame *frame_20;
    QFrame *stat_4;
    QTableView *tableView_statistiques;
    QLabel *label_89;
    QLabel *label_90;
    QWidget *tab_2;
    QFrame *frame_17;
    QFrame *frame_18;
    QLabel *label_33;
    QTableView *tableView_11;
    QLabel *label_34;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1134, 613);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("    background-color: #f5f7fa;\n"
"    color: #333;\n"
"    font-family: \"Arial\";\n"
""));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 1171, 551));
        tab = new QWidget();
        tab->setObjectName("tab");
        frame_13 = new QFrame(tab);
        frame_13->setObjectName("frame_13");
        frame_13->setGeometry(QRect(10, 40, 531, 341));
        frame_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_13->setFrameShape(QFrame::Shape::StyledPanel);
        frame_13->setFrameShadow(QFrame::Shadow::Raised);
        frame_14 = new QFrame(frame_13);
        frame_14->setObjectName("frame_14");
        frame_14->setGeometry(QRect(10, 10, 511, 321));
        frame_14->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_14->setFrameShape(QFrame::Shape::StyledPanel);
        frame_14->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_idd = new QLineEdit(frame_14);
        lineEdit_idd->setObjectName("lineEdit_idd");
        lineEdit_idd->setGeometry(QRect(280, 70, 141, 31));
        lineEdit_idd->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        lineEdit_nom = new QLineEdit(frame_14);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(280, 130, 141, 31));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        label_13 = new QLabel(frame_14);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(50, 70, 61, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_18 = new QLabel(frame_14);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 140, 101, 31));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        pushButton_ajouterr = new QPushButton(frame_14);
        pushButton_ajouterr->setObjectName("pushButton_ajouterr");
        pushButton_ajouterr->setGeometry(QRect(120, 280, 80, 24));
        pushButton_ajouterr->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_10 = new QPushButton(frame_14);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(310, 280, 80, 24));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(0, 0, 0);"));
        label_23 = new QLabel(frame_14);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(50, 190, 101, 31));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        lineEdit_distance = new QLineEdit(frame_14);
        lineEdit_distance->setObjectName("lineEdit_distance");
        lineEdit_distance->setGeometry(QRect(280, 190, 141, 31));
        lineEdit_distance->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        label_43 = new QLabel(tab);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(200, 10, 61, 21));
        label_43->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_48 = new QLabel(tab);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(10, 380, 71, 31));
        label_48->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        frame_38 = new QFrame(tab);
        frame_38->setObjectName("frame_38");
        frame_38->setGeometry(QRect(0, 410, 1051, 121));
        frame_38->setStyleSheet(QString::fromUtf8("background-color: rgb(113, 149, 195);"));
        frame_38->setFrameShape(QFrame::Shape::StyledPanel);
        frame_38->setFrameShadow(QFrame::Shadow::Raised);
        tableView_6 = new QTableView(frame_38);
        tableView_6->setObjectName("tableView_6");
        tableView_6->setGeometry(QRect(0, 0, 1051, 111));
        label_76 = new QLabel(tab);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(740, 10, 61, 21));
        label_76->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        frame_30 = new QFrame(tab);
        frame_30->setObjectName("frame_30");
        frame_30->setGeometry(QRect(550, 40, 531, 341));
        frame_30->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_30->setFrameShape(QFrame::Shape::StyledPanel);
        frame_30->setFrameShadow(QFrame::Shadow::Raised);
        frame_31 = new QFrame(frame_30);
        frame_31->setObjectName("frame_31");
        frame_31->setGeometry(QRect(10, 10, 511, 321));
        frame_31->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_31->setFrameShape(QFrame::Shape::StyledPanel);
        frame_31->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_idd1 = new QLineEdit(frame_31);
        lineEdit_idd1->setObjectName("lineEdit_idd1");
        lineEdit_idd1->setGeometry(QRect(280, 70, 141, 31));
        lineEdit_idd1->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        lineEdit_nom1 = new QLineEdit(frame_31);
        lineEdit_nom1->setObjectName("lineEdit_nom1");
        lineEdit_nom1->setGeometry(QRect(280, 130, 141, 31));
        lineEdit_nom1->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        label_14 = new QLabel(frame_31);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(50, 70, 61, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_77 = new QLabel(frame_31);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(50, 140, 101, 31));
        label_77->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        pushButton_modifier1 = new QPushButton(frame_31);
        pushButton_modifier1->setObjectName("pushButton_modifier1");
        pushButton_modifier1->setGeometry(QRect(120, 280, 80, 24));
        pushButton_modifier1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_28 = new QPushButton(frame_31);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(310, 280, 80, 24));
        pushButton_28->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_distance2 = new QLineEdit(frame_31);
        lineEdit_distance2->setObjectName("lineEdit_distance2");
        lineEdit_distance2->setGeometry(QRect(280, 190, 141, 31));
        lineEdit_distance2->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        label_24 = new QLabel(frame_31);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(50, 190, 101, 31));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        frame_5 = new QFrame(tab_4);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(20, 30, 531, 341));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(10, 10, 511, 321));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_id = new QLineEdit(frame_6);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(280, 30, 141, 31));
        lineEdit_id->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        lineEdit_qte = new QLineEdit(frame_6);
        lineEdit_qte->setObjectName("lineEdit_qte");
        lineEdit_qte->setGeometry(QRect(330, 230, 41, 31));
        lineEdit_qte->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        dateEdit_date = new QDateEdit(frame_6);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setGeometry(QRect(280, 180, 141, 31));
        dateEdit_date->setStyleSheet(QString::fromUtf8("background-color: rgb(182, 182, 182);\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(frame_6);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 30, 61, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_6 = new QLabel(frame_6);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 130, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_7 = new QLabel(frame_6);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 180, 71, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_8 = new QLabel(frame_6);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 230, 71, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        pushButton_ajouter = new QPushButton(frame_6);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(120, 280, 80, 24));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_6 = new QPushButton(frame_6);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(310, 280, 80, 24));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(0, 0, 0);"));
        label_19 = new QLabel(frame_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(50, 90, 201, 21));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        lineEdit_medist = new QLineEdit(frame_6);
        lineEdit_medist->setObjectName("lineEdit_medist");
        lineEdit_medist->setGeometry(QRect(280, 80, 141, 31));
        lineEdit_medist->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        pushButton_auto = new QPushButton(frame_6);
        pushButton_auto->setObjectName("pushButton_auto");
        pushButton_auto->setGeometry(QRect(440, 140, 51, 24));
        pushButton_auto->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        comboBox_aboratoire = new QComboBox(frame_6);
        comboBox_aboratoire->setObjectName("comboBox_aboratoire");
        comboBox_aboratoire->setGeometry(QRect(280, 130, 141, 31));
        frame_7 = new QFrame(tab_4);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(560, 30, 511, 341));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(10, 10, 491, 321));
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_id2 = new QLineEdit(frame_8);
        lineEdit_id2->setObjectName("lineEdit_id2");
        lineEdit_id2->setGeometry(QRect(250, 30, 141, 31));
        lineEdit_id2->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        lineEdit_qte2 = new QLineEdit(frame_8);
        lineEdit_qte2->setObjectName("lineEdit_qte2");
        lineEdit_qte2->setGeometry(QRect(290, 230, 41, 31));
        lineEdit_qte2->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        dateEdit_4 = new QDateEdit(frame_8);
        dateEdit_4->setObjectName("dateEdit_4");
        dateEdit_4->setGeometry(QRect(250, 180, 141, 31));
        dateEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(182, 182, 182);\n"
"color: rgb(0, 0, 0);"));
        pushButton_7 = new QPushButton(frame_8);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(270, 280, 80, 24));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(0, 0, 0);"));
        pushButton_modifier = new QPushButton(frame_8);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(100, 280, 80, 24));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_medist_2 = new QLineEdit(frame_8);
        lineEdit_medist_2->setObjectName("lineEdit_medist_2");
        lineEdit_medist_2->setGeometry(QRect(250, 80, 141, 31));
        lineEdit_medist_2->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        label_20 = new QLabel(frame_8);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(40, 80, 201, 21));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_16 = new QLabel(frame_8);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(40, 220, 71, 31));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_21 = new QLabel(frame_8);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(50, 30, 61, 31));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_22 = new QLabel(frame_8);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(40, 170, 71, 31));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        label_27 = new QLabel(frame_8);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(40, 130, 101, 31));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: italic 14pt \"Segoe UI\";"));
        comboBox_aboratoire2 = new QComboBox(frame_8);
        comboBox_aboratoire2->setObjectName("comboBox_aboratoire2");
        comboBox_aboratoire2->setGeometry(QRect(250, 130, 141, 31));
        frame_16 = new QFrame(tab_4);
        frame_16->setObjectName("frame_16");
        frame_16->setGeometry(QRect(20, 400, 811, 121));
        frame_16->setStyleSheet(QString::fromUtf8("background-color: rgb(113, 149, 195);"));
        frame_16->setFrameShape(QFrame::Shape::StyledPanel);
        frame_16->setFrameShadow(QFrame::Shadow::Raised);
        tableView = new QTableView(frame_16);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 0, 811, 121));
        label_29 = new QLabel(tab_4);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(170, 0, 61, 21));
        label_29->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_30 = new QLabel(tab_4);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(790, 0, 71, 21));
        label_30->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_32 = new QLabel(tab_4);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(30, 370, 71, 31));
        label_32->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        frame_24 = new QFrame(tab_4);
        frame_24->setObjectName("frame_24");
        frame_24->setGeometry(QRect(850, 400, 211, 121));
        frame_24->setStyleSheet(QString::fromUtf8("background-color: rgb(113, 149, 195);"));
        frame_24->setFrameShape(QFrame::Shape::StyledPanel);
        frame_24->setFrameShadow(QFrame::Shadow::Raised);
        pushButtonPdf = new QPushButton(frame_24);
        pushButtonPdf->setObjectName("pushButtonPdf");
        pushButtonPdf->setGeometry(QRect(60, 50, 93, 31));
        pushButtonPdf->setStyleSheet(QString::fromUtf8("background-color: rgb(137, 214, 255);"));
        label_37 = new QLabel(tab_4);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(910, 370, 101, 21));
        label_37->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        frame_32 = new QFrame(tab_5);
        frame_32->setObjectName("frame_32");
        frame_32->setGeometry(QRect(20, 190, 871, 331));
        frame_32->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_32->setFrameShape(QFrame::Shape::StyledPanel);
        frame_32->setFrameShadow(QFrame::Shadow::Raised);
        frame_34 = new QFrame(frame_32);
        frame_34->setObjectName("frame_34");
        frame_34->setGeometry(QRect(10, 10, 851, 311));
        frame_34->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_34->setFrameShape(QFrame::Shape::StyledPanel);
        frame_34->setFrameShadow(QFrame::Shadow::Raised);
        label_44 = new QLabel(frame_34);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(40, 200, 71, 31));
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tableView_4 = new QTableView(frame_34);
        tableView_4->setObjectName("tableView_4");
        tableView_4->setGeometry(QRect(0, 0, 851, 311));
        label_79 = new QLabel(tab_5);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(270, 10, 111, 31));
        label_79->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        frame_33 = new QFrame(tab_5);
        frame_33->setObjectName("frame_33");
        frame_33->setGeometry(QRect(20, 40, 611, 141));
        frame_33->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_33->setFrameShape(QFrame::Shape::StyledPanel);
        frame_33->setFrameShadow(QFrame::Shadow::Raised);
        frame_35 = new QFrame(frame_33);
        frame_35->setObjectName("frame_35");
        frame_35->setGeometry(QRect(10, 10, 591, 121));
        frame_35->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_35->setFrameShape(QFrame::Shape::StyledPanel);
        frame_35->setFrameShadow(QFrame::Shadow::Raised);
        label_45 = new QLabel(frame_35);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(40, 200, 71, 31));
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_74 = new QLabel(frame_35);
        label_74->setObjectName("label_74");
        label_74->setGeometry(QRect(20, 30, 21, 31));
        label_74->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_qtee = new QLineEdit(frame_35);
        lineEdit_qtee->setObjectName("lineEdit_qtee");
        lineEdit_qtee->setGeometry(QRect(290, 30, 51, 31));
        lineEdit_qtee->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        lineEdit_idr = new QLineEdit(frame_35);
        lineEdit_idr->setObjectName("lineEdit_idr");
        lineEdit_idr->setGeometry(QRect(60, 30, 121, 31));
        lineEdit_idr->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        pushButton_rech = new QPushButton(frame_35);
        pushButton_rech->setObjectName("pushButton_rech");
        pushButton_rech->setGeometry(QRect(280, 90, 80, 24));
        pushButton_rech->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_78 = new QLabel(frame_35);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(210, 30, 61, 31));
        label_78->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_91 = new QLabel(frame_35);
        label_91->setObjectName("label_91");
        label_91->setGeometry(QRect(360, 30, 71, 31));
        label_91->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_aboratoiree = new QLineEdit(frame_35);
        lineEdit_aboratoiree->setObjectName("lineEdit_aboratoiree");
        lineEdit_aboratoiree->setGeometry(QRect(450, 30, 121, 31));
        lineEdit_aboratoiree->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        frame_36 = new QFrame(tab_5);
        frame_36->setObjectName("frame_36");
        frame_36->setGeometry(QRect(630, 40, 261, 141));
        frame_36->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_36->setFrameShape(QFrame::Shape::StyledPanel);
        frame_36->setFrameShadow(QFrame::Shadow::Raised);
        frame_40 = new QFrame(frame_36);
        frame_40->setObjectName("frame_40");
        frame_40->setGeometry(QRect(10, 10, 241, 121));
        frame_40->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_40->setFrameShape(QFrame::Shape::StyledPanel);
        frame_40->setFrameShadow(QFrame::Shadow::Raised);
        label_49 = new QLabel(frame_40);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(40, 200, 71, 31));
        label_49->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_trier = new QPushButton(frame_40);
        pushButton_trier->setObjectName("pushButton_trier");
        pushButton_trier->setGeometry(QRect(80, 80, 80, 24));
        pushButton_trier->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        comboBox = new QComboBox(frame_40);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(150, 30, 72, 24));
        label_80 = new QLabel(frame_40);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(30, 30, 81, 31));
        label_80->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_87 = new QLabel(tab_5);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(730, 10, 81, 21));
        label_87->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        frame_21 = new QFrame(tab_5);
        frame_21->setObjectName("frame_21");
        frame_21->setGeometry(QRect(900, 40, 211, 481));
        frame_21->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_21->setFrameShape(QFrame::Shape::StyledPanel);
        frame_21->setFrameShadow(QFrame::Shadow::Raised);
        frame_22 = new QFrame(frame_21);
        frame_22->setObjectName("frame_22");
        frame_22->setGeometry(QRect(10, 10, 191, 461));
        frame_22->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_22->setFrameShape(QFrame::Shape::StyledPanel);
        frame_22->setFrameShadow(QFrame::Shadow::Raised);
        label_35 = new QLabel(frame_22);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(90, 60, 61, 31));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_id_2 = new QLineEdit(frame_22);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(30, 100, 141, 31));
        lineEdit_id_2->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        lineEdit_ids = new QLineEdit(frame_22);
        lineEdit_ids->setObjectName("lineEdit_ids");
        lineEdit_ids->setGeometry(QRect(30, 350, 141, 31));
        lineEdit_ids->setStyleSheet(QString::fromUtf8("background-color: rgb(156, 156, 156);"));
        label_36 = new QLabel(frame_22);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(50, 300, 101, 31));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_supprimer = new QPushButton(frame_22);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(60, 160, 80, 24));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(0, 0, 0);"));
        pushButton_supprimer1 = new QPushButton(frame_22);
        pushButton_supprimer1->setObjectName("pushButton_supprimer1");
        pushButton_supprimer1->setGeometry(QRect(60, 410, 80, 24));
        pushButton_supprimer1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(0, 0, 0);"));
        label_88 = new QLabel(tab_5);
        label_88->setObjectName("label_88");
        label_88->setGeometry(QRect(980, 10, 101, 21));
        label_88->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        pushButtonStat = new QPushButton(tab_6);
        pushButtonStat->setObjectName("pushButtonStat");
        pushButtonStat->setGeometry(QRect(1000, 70, 80, 24));
        pushButtonStat->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        frame_19 = new QFrame(tab_6);
        frame_19->setObjectName("frame_19");
        frame_19->setGeometry(QRect(380, 120, 731, 361));
        frame_19->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_19->setFrameShape(QFrame::Shape::StyledPanel);
        frame_19->setFrameShadow(QFrame::Shadow::Raised);
        stat_3 = new QFrame(frame_19);
        stat_3->setObjectName("stat_3");
        stat_3->setGeometry(QRect(10, 10, 711, 341));
        stat_3->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        stat_3->setFrameShape(QFrame::Shape::StyledPanel);
        stat_3->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView = new QGraphicsView(stat_3);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 1, 711, 341));
        vboxLayout_stats = new QLabel(tab_6);
        vboxLayout_stats->setObjectName("vboxLayout_stats");
        vboxLayout_stats->setGeometry(QRect(500, 10, 121, 31));
        vboxLayout_stats->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        frame_20 = new QFrame(tab_6);
        frame_20->setObjectName("frame_20");
        frame_20->setGeometry(QRect(10, 120, 361, 361));
        frame_20->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_20->setFrameShape(QFrame::Shape::StyledPanel);
        frame_20->setFrameShadow(QFrame::Shadow::Raised);
        stat_4 = new QFrame(frame_20);
        stat_4->setObjectName("stat_4");
        stat_4->setGeometry(QRect(10, 10, 341, 341));
        stat_4->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        stat_4->setFrameShape(QFrame::Shape::StyledPanel);
        stat_4->setFrameShadow(QFrame::Shadow::Raised);
        tableView_statistiques = new QTableView(stat_4);
        tableView_statistiques->setObjectName("tableView_statistiques");
        tableView_statistiques->setGeometry(QRect(0, 0, 341, 341));
        label_89 = new QLabel(tab_6);
        label_89->setObjectName("label_89");
        label_89->setGeometry(QRect(90, 70, 171, 31));
        label_89->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_90 = new QLabel(tab_6);
        label_90->setObjectName("label_90");
        label_90->setGeometry(QRect(640, 70, 171, 31));
        label_90->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        frame_17 = new QFrame(tab_2);
        frame_17->setObjectName("frame_17");
        frame_17->setGeometry(QRect(40, 150, 1041, 361));
        frame_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_17->setFrameShape(QFrame::Shape::StyledPanel);
        frame_17->setFrameShadow(QFrame::Shadow::Raised);
        frame_18 = new QFrame(frame_17);
        frame_18->setObjectName("frame_18");
        frame_18->setGeometry(QRect(10, 10, 1021, 341));
        frame_18->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 247, 255);"));
        frame_18->setFrameShape(QFrame::Shape::StyledPanel);
        frame_18->setFrameShadow(QFrame::Shadow::Raised);
        label_33 = new QLabel(frame_18);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(40, 200, 71, 31));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tableView_11 = new QTableView(frame_18);
        tableView_11->setObjectName("tableView_11");
        tableView_11->setGeometry(QRect(0, 0, 1011, 341));
        label_34 = new QLabel(tab_2);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(80, 50, 251, 31));
        label_34->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1134, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        pushButton_ajouterr->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "ANNULER", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_76->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        pushButton_modifier1->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "ANNULER", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "AJOUTER DISTRIBUTEUR", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "LAboratoire", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "ANNULER", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Mdicamment Distribuer", nullptr));
        pushButton_auto->setText(QCoreApplication::translate("MainWindow", "AUTO", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Mdicamment Distribuer", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "LAboratoire", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        pushButtonPdf->setText(QCoreApplication::translate("MainWindow", "export", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Exporter pdf", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Ajouter une Commande", nullptr));
        label_44->setText(QString());
        label_79->setText(QCoreApplication::translate("MainWindow", "RECHERCHE", nullptr));
        label_45->setText(QString());
        label_74->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        pushButton_rech->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "Quantiter", nullptr));
        label_91->setText(QCoreApplication::translate("MainWindow", "Laboratoire", nullptr));
        label_49->setText(QString());
        pushButton_trier->setText(QCoreApplication::translate("MainWindow", "TRIE", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "date", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "qte", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "aboratoire", nullptr));

        label_80->setText(QCoreApplication::translate("MainWindow", "TRIER PAR :", nullptr));
        label_87->setText(QCoreApplication::translate("MainWindow", "TRIER", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "ID Distributeur", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_supprimer1->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_88->setText(QCoreApplication::translate("MainWindow", "SUPPRESSION", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Les recherche -trie*supp", nullptr));
        pushButtonStat->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        vboxLayout_stats->setText(QCoreApplication::translate("MainWindow", "Les statistique", nullptr));
        label_89->setText(QCoreApplication::translate("MainWindow", " Tableaux Statistique", nullptr));
        label_90->setText(QCoreApplication::translate("MainWindow", " Statistique Graphique", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_33->setText(QString());
        label_34->setText(QCoreApplication::translate("MainWindow", "les demande des medicament", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Les demande des Medicament", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
