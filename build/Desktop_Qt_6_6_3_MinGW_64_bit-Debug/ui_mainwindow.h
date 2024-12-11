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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *afficher;
    QTableView *tableView_r;
    QTableView *tableView_s;
    QLabel *label_26;
    QGraphicsView *graphicsViewRendezvous;
    QGraphicsView *graphicsViewServices;
    QComboBox *comboBoxT;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tab_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QLabel *label_11;
    QLabel *label_22;
    QLineEdit *lineEditNum;
    QDateEdit *dateEdit;
    QLineEdit *lineEditClientId;
    QLabel *label_23;
    QLineEdit *lineEditNomService;
    QTableView *tableView;
    QPushButton *btnSupprimer;
    QPushButton *btnAfficher;
    QComboBox *combobox;
    QLabel *label_24;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_25;
    QPushButton *btnMettreAJourStatut;
    QComboBox *comboBoxStatut;
    QDateTimeEdit *timeEdit;
    QPushButton *btn;
    QTableView *salleTableView;
    QPushButton *accueil_5;
    QWidget *tab_7;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *nomServiceEdit;
    QLabel *label_16;
    QDoubleSpinBox *prixEdit;
    QTextEdit *descriptionEdit;
    QLabel *label_17;
    QPushButton *ajouterButton;
    QPushButton *supprimerButton;
    QLabel *label_18;
    QPushButton *afficherButton;
    QTableView *tableView_rv;
    QPushButton *modifierButton;
    QPushButton *pushButton_generatePDF;
    QLabel *label_19;
    QLabel *label_20;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboboxSort;
    QLabel *label_21;
    QLineEdit *lineEdit_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1781, 1315);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1521, 1231));
        tabWidget->setStyleSheet(QString::fromUtf8("/* Set the base background color and padding */\n"
"QWidget {\n"
"    background-color: #dfeff9; \n"
"    color: #333;\n"
"    font-family: \"Arial\";\n"
"}\n"
"\n"
"/* Style for main window title and labels */\n"
"QMainWindow::title, QLabel {\n"
"    color: #4a4a4a;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Style de base pour QPushButton avec couleur rouge bordeaux */\n"
"QPushButton {\n"
"    background-color: #550000; /* Rouge bordeaux */\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: #7a0000; /* Rouge bordeaux l\303\251g\303\250rement plus clair lors du survol */\n"
"}\n"
"\n"
"/* Couleur lorsqu'on appuie sur le bouton */\n"
"QPushButton:pressed {\n"
"    background-color: #2196f3; /* Bleu lors du clic */\n"
"}\n"
"\n"
"\n"
"/* Style for QLineEdit and QComboBox */\n"
"QLineEdit, QComboBox,QTextEdit,QDoubleSpinBox {\n"
"    border: 1px solid #"
                        "550000;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus,QTextEdit:focus,QDoubleSpinBox:focus {\n"
"    border: 1px solid #43a047;\n"
"}\n"
"\n"
"/* Customize QTableView header and alternate row colors */\n"
"QTableView::header {\n"
"    background-color: #43a047;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    background-color: #f9f9f9;\n"
"    alternate-background-color: #e0e0e0;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"/* Add shadows and rounded corners */\n"
"QGroupBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #dcdcdc;\n"
"    border-radius: 10px;\n"
"    margin-top: 15px;\n"
"    padding: 10px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background-color: #eaeaea;\n"
"    width: 10px;\n"
"    margin: 20px 0 20px 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #a5d6a7;"
                        "\n"
"    border-radius: 5px;\n"
"}\n"
""));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label = new QLabel(tab_3);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 20, 631, 121));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 130, 371, 71));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(980, 130, 371, 71));
        afficher = new QPushButton(tab_3);
        afficher->setObjectName("afficher");
        afficher->setGeometry(QRect(700, 700, 121, 29));
        tableView_r = new QTableView(tab_3);
        tableView_r->setObjectName("tableView_r");
        tableView_r->setGeometry(QRect(20, 210, 731, 291));
        tableView_r->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table */\n"
"    border: 1px solid #550000;  /* Bordure de la table */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"    font-family: Arial;         /* Police de la table */\n"
"    color: black;               /* Texte en noir */\n"
"    gridline-color: #d3d3d3;    /* Couleur des lignes de grille */\n"
"    border-radius: 8px;         \n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 10px;              /* Espacement interne des cellules */\n"
"    border: 1px solid #d3d3d3;  /* Bordure autour de chaque cellule */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #76c7c0;  /* Couleur de fond des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"    color: white;               /* Couleur du texte des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #d3d3d3;  /* Fond des "
                        "en-t\303\252tes de colonnes */\n"
"    color: black;               /* Couleur du texte des en-t\303\252tes */\n"
"    padding: 4px;               /* Espacement dans les en-t\303\252tes */\n"
"    border: 1px solid #cccccc;  /* Bordure des sections */\n"
"    text-align: center;         /* Alignement du texte */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: #d3d3d3;  /* Fond pour le coin sup\303\251rieur gauche */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
""));
        tableView_s = new QTableView(tab_3);
        tableView_s->setObjectName("tableView_s");
        tableView_s->setGeometry(QRect(770, 210, 731, 291));
        tableView_s->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table */\n"
"    border: 1px solid #550000;  /* Bordure de la table */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"    font-family: Arial;         /* Police de la table */\n"
"    color: black;               /* Texte en noir */\n"
"    gridline-color: #d3d3d3;    /* Couleur des lignes de grille */\n"
"    border-radius: 8px;         \n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 10px;              /* Espacement interne des cellules */\n"
"    border: 1px solid #d3d3d3;  /* Bordure autour de chaque cellule */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #76c7c0;  /* Couleur de fond des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"    color: white;               /* Couleur du texte des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #d3d3d3;  /* Fond des "
                        "en-t\303\252tes de colonnes */\n"
"    color: black;               /* Couleur du texte des en-t\303\252tes */\n"
"    padding: 4px;               /* Espacement dans les en-t\303\252tes */\n"
"    border: 1px solid #cccccc;  /* Bordure des sections */\n"
"    text-align: center;         /* Alignement du texte */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: #d3d3d3;  /* Fond pour le coin sup\303\251rieur gauche */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
""));
        label_26 = new QLabel(tab_3);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 10, 161, 161));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_26->setScaledContents(true);
        graphicsViewRendezvous = new QGraphicsView(tab_3);
        graphicsViewRendezvous->setObjectName("graphicsViewRendezvous");
        graphicsViewRendezvous->setGeometry(QRect(240, 540, 256, 151));
        graphicsViewRendezvous->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table en gris clair */\n"
"    border: 1px solid #550000;  /* Bordure de la table en gris clair */\n"
"    border-radius: 8px;   /* Couleur des lignes de grille en gris clair */\n"
"}"));
        graphicsViewServices = new QGraphicsView(tab_3);
        graphicsViewServices->setObjectName("graphicsViewServices");
        graphicsViewServices->setGeometry(QRect(1040, 540, 256, 151));
        graphicsViewServices->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table en gris clair */\n"
"    border: 1px solid #550000;  /* Bordure de la table en gris clair */\n"
"    border-radius: 8px;   /* Couleur des lignes de grille en gris clair */\n"
"}\n"
""));
        comboBoxT = new QComboBox(tab_3);
        comboBoxT->setObjectName("comboBoxT");
        comboBoxT->setGeometry(QRect(650, 210, 101, 31));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1070, 510, 261, 20));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(290, 510, 231, 20));
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        label_7 = new QLabel(tab_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(130, 50, 531, 51));
        label_8 = new QLabel(tab_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(160, 230, 181, 41));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(160, 280, 251, 41));
        label_10 = new QLabel(tab_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(160, 320, 251, 51));
        btnAjouter = new QPushButton(tab_5);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(210, 470, 93, 29));
        btnModifier = new QPushButton(tab_5);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(280, 520, 93, 29));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(630, 50, 291, 41));
        label_22 = new QLabel(tab_5);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(160, 180, 241, 31));
        lineEditNum = new QLineEdit(tab_5);
        lineEditNum->setObjectName("lineEditNum");
        lineEditNum->setGeometry(QRect(370, 180, 161, 31));
        dateEdit = new QDateEdit(tab_5);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(420, 330, 110, 26));
        lineEditClientId = new QLineEdit(tab_5);
        lineEditClientId->setObjectName("lineEditClientId");
        lineEditClientId->setGeometry(QRect(260, 230, 161, 31));
        label_23 = new QLabel(tab_5);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(0, 0, 121, 151));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_23->setScaledContents(true);
        lineEditNomService = new QLineEdit(tab_5);
        lineEditNomService->setObjectName("lineEditNomService");
        lineEditNomService->setGeometry(QRect(270, 280, 161, 31));
        tableView = new QTableView(tab_5);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(630, 100, 841, 421));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table en gris clair */\n"
"    border: 1px solid #550000;  /* Bordure de la table en gris clair */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"    font-family: Arial;         /* Police de la table */\n"
"    color: black;               /* Texte en noir */\n"
"    gridline-color: #d3d3d3; \n"
"    border-radius: 8px;   /* Couleur des lignes de grille en gris clair */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 10px;              /* Espacement interne des cellules */\n"
"    border: 1px solid #d3d3d3;  /* Bordure autour de chaque cellule avec gris clair */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #550000;  /* Couleur de fond des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"    color: white;               /* Couleur du texte des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"}\n"
"\n"
"QHeaderView::section {"
                        "\n"
"    background-color: #d3d3d3;  /* Gris clair pour les en-t\303\252tes de colonnes/sections */\n"
"    color: black;               /* Couleur du texte des en-t\303\252tes en noir */\n"
"    padding: 4px;               /* Espacement dans les en-t\303\252tes */\n"
"    border: 1px solid #cccccc;  /* Bordure des sections */\n"
"    text-align: center;         /* Alignement du texte */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: #d3d3d3;  /* Gris clair pour le coin sup\303\251rieur gauche */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
""));
        btnSupprimer = new QPushButton(tab_5);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(340, 470, 111, 29));
        btnAfficher = new QPushButton(tab_5);
        btnAfficher->setObjectName("btnAfficher");
        btnAfficher->setGeometry(QRect(280, 570, 93, 29));
        combobox = new QComboBox(tab_5);
        combobox->setObjectName("combobox");
        combobox->setGeometry(QRect(1360, 100, 111, 31));
        label_24 = new QLabel(tab_5);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(1120, 60, 171, 20));
        verticalLayoutWidget_2 = new QWidget(tab_5);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(1290, 60, 181, 31));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(tab_5);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(160, 360, 261, 51));
        btnMettreAJourStatut = new QPushButton(tab_5);
        btnMettreAJourStatut->setObjectName("btnMettreAJourStatut");
        btnMettreAJourStatut->setGeometry(QRect(240, 620, 181, 29));
        comboBoxStatut = new QComboBox(tab_5);
        comboBoxStatut->setObjectName("comboBoxStatut");
        comboBoxStatut->setGeometry(QRect(1260, 100, 101, 31));
        timeEdit = new QDateTimeEdit(tab_5);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(430, 370, 194, 26));
        btn = new QPushButton(tab_5);
        btn->setObjectName("btn");
        btn->setGeometry(QRect(630, 540, 251, 31));
        salleTableView = new QTableView(tab_5);
        salleTableView->setObjectName("salleTableView");
        salleTableView->setGeometry(QRect(630, 590, 541, 81));
        salleTableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table en gris clair */\n"
"    border: 1px solid #550000;  /* Bordure de la table en gris clair */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"    font-family: Arial;         /* Police de la table */\n"
"    color: black;               /* Texte en noir */\n"
"    gridline-color: #d3d3d3; \n"
"    border-radius: 8px;   /* Couleur des lignes de grille en gris clair */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 10px;              /* Espacement interne des cellules */\n"
"    border: 1px solid #d3d3d3;  /* Bordure autour de chaque cellule avec gris clair */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #550000;  /* Couleur de fond des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"    color: white;               /* Couleur du texte des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"}\n"
"\n"
"QHeaderView::section {"
                        "\n"
"    background-color: #d3d3d3;  /* Gris clair pour les en-t\303\252tes de colonnes/sections */\n"
"    color: black;               /* Couleur du texte des en-t\303\252tes en noir */\n"
"    padding: 4px;               /* Espacement dans les en-t\303\252tes */\n"
"    border: 1px solid #cccccc;  /* Bordure des sections */\n"
"    text-align: center;         /* Alignement du texte */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: #d3d3d3;  /* Gris clair pour le coin sup\303\251rieur gauche */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
""));
        accueil_5 = new QPushButton(tab_5);
        accueil_5->setObjectName("accueil_5");
        accueil_5->setGeometry(QRect(10, 10, 93, 29));
        tabWidget->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        label_14 = new QLabel(tab_7);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(170, 40, 521, 51));
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_15 = new QLabel(tab_7);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(110, 130, 181, 41));
        label_15->setStyleSheet(QString::fromUtf8(""));
        nomServiceEdit = new QLineEdit(tab_7);
        nomServiceEdit->setObjectName("nomServiceEdit");
        nomServiceEdit->setGeometry(QRect(280, 140, 231, 31));
        label_16 = new QLabel(tab_7);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(110, 230, 181, 41));
        prixEdit = new QDoubleSpinBox(tab_7);
        prixEdit->setObjectName("prixEdit");
        prixEdit->setGeometry(QRect(270, 240, 171, 31));
        descriptionEdit = new QTextEdit(tab_7);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setGeometry(QRect(350, 190, 181, 31));
        label_17 = new QLabel(tab_7);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(110, 190, 231, 21));
        ajouterButton = new QPushButton(tab_7);
        ajouterButton->setObjectName("ajouterButton");
        ajouterButton->setGeometry(QRect(210, 370, 93, 29));
        supprimerButton = new QPushButton(tab_7);
        supprimerButton->setObjectName("supprimerButton");
        supprimerButton->setGeometry(QRect(330, 370, 111, 29));
        label_18 = new QLabel(tab_7);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(670, 30, 321, 61));
        afficherButton = new QPushButton(tab_7);
        afficherButton->setObjectName("afficherButton");
        afficherButton->setGeometry(QRect(860, 500, 93, 29));
        tableView_rv = new QTableView(tab_7);
        tableView_rv->setObjectName("tableView_rv");
        tableView_rv->setGeometry(QRect(670, 100, 591, 381));
        tableView_rv->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table en gris clair */\n"
"    border: 1px solid #550000;  /* Bordure de la table en gris clair */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"    font-family: Arial;         /* Police de la table */\n"
"    color: black;               /* Texte en noir */\n"
"    gridline-color: #d3d3d3; \n"
"    border-radius: 8px;   /* Couleur des lignes de grille en gris clair */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 10px;              /* Espacement interne des cellules */\n"
"    border: 1px solid #d3d3d3;  /* Bordure autour de chaque cellule avec gris clair */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #550000;  /* Couleur de fond des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"    color: white;               /* Couleur du texte des \303\251l\303\251ments s\303\251lectionn\303\251s */\n"
"}\n"
"\n"
"QHeaderView::section {"
                        "\n"
"    background-color: #d3d3d3;  /* Gris clair pour les en-t\303\252tes de colonnes/sections */\n"
"    color: black;               /* Couleur du texte des en-t\303\252tes en noir */\n"
"    padding: 4px;               /* Espacement dans les en-t\303\252tes */\n"
"    border: 1px solid #cccccc;  /* Bordure des sections */\n"
"    text-align: center;         /* Alignement du texte */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: #d3d3d3;  /* Gris clair pour le coin sup\303\251rieur gauche */\n"
"    color: black;               /* Texte en noir */\n"
"}\n"
""));
        modifierButton = new QPushButton(tab_7);
        modifierButton->setObjectName("modifierButton");
        modifierButton->setGeometry(QRect(270, 420, 93, 29));
        pushButton_generatePDF = new QPushButton(tab_7);
        pushButton_generatePDF->setObjectName("pushButton_generatePDF");
        pushButton_generatePDF->setGeometry(QRect(980, 500, 121, 29));
        label_19 = new QLabel(tab_7);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(110, 280, 101, 41));
        label_20 = new QLabel(tab_7);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(960, 60, 141, 20));
        verticalLayoutWidget = new QWidget(tab_7);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(1100, 60, 160, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboboxSort = new QComboBox(tab_7);
        comboboxSort->setObjectName("comboboxSort");
        comboboxSort->setGeometry(QRect(1110, 100, 151, 31));
        comboboxSort->setStyleSheet(QString::fromUtf8("    border: 1px solid #550000;"));
        label_21 = new QLabel(tab_7);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(0, 0, 111, 131));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_21->setScaledContents(true);
        lineEdit_4 = new QLineEdit(tab_7);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(220, 290, 151, 26));
        tabWidget->addTab(tab_7, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1781, 26));
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
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700; color:#550000;\">Tableau de bord</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">Les rendez-vous \303\240 venir :</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">Les stocks disponible :</span></p></body></html>", nullptr));
        afficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_26->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">Les services les plus demand\303\251 :</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">Statut des rendezvous :</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tableau de bord", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:700; color:#550000;\">Planification de rendez-vous :</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Client :</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Service :</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Date du rendez-vous :</span></p></body></html>", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Planifier", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Rendez-vous planifi\303\251s</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        label_22->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Rendez-vous n&quot; :</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_22->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Rendez-vous n\302\260 :</span></p></body></html>", nullptr));
        label_23->setText(QString());
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnAfficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Chercher rendezvous :", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Heure du rendez-vous :</span></p></body></html>", nullptr));
        btnMettreAJourStatut->setText(QCoreApplication::translate("MainWindow", "Mettre a jour statut", nullptr));
        btn->setText(QCoreApplication::translate("MainWindow", "V\303\251rifier la salle de soins", nullptr));
        accueil_5->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Gestion des rendez-vous", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; color:#550000;\">Ajouter un services :</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Nom du service :</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Prix du service :</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Description du service :</span></p></body></html>", nullptr));
        ajouterButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        supprimerButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#4a4a4a;\">Les services propos\303\251s</span></p></body></html>", nullptr));
        afficherButton->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
#if QT_CONFIG(tooltip)
        tableView_rv->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#005500;\">Les services propos\303\251s</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        modifierButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_generatePDF->setText(QCoreApplication::translate("MainWindow", "G\303\251nerer pdf", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Employe :</span></p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Chercher service :", nullptr));
        label_21->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Gestion des services", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
