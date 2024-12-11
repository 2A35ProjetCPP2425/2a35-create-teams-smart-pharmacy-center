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
#include <QtWidgets/QHBoxLayout>
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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *updateButton;
    QLabel *label_2;
    QPushButton *searchButton;
    QLineEdit *lineEdit;
    QPushButton *sortByNameButton;
    QLineEdit *lineEdit_4;
    QTableView *tableView;
    QLineEdit *lineEdit_3;
    QPushButton *deleteButton;
    QPushButton *sortButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_5;
    QDateEdit *dateEditDateCreation;
    QPushButton *sortByIdButton;
    QPushButton *showClientCountButton;
    QLabel *label;
    QLabel *label_4;
    QPushButton *insertButton;
    QPushButton *pushButton;
    QWidget *tab_2;
    QLineEdit *lineEditChatBot;
    QTextEdit *textEditChatHistory;
    QPushButton *chatBotSendButton;
    QPushButton *sendSmsButton;
    QLabel *label_12;
    QComboBox *comboBox;
    QPushButton *sendButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLineEdit *lineEdit_13;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1259, 485);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1251, 441));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(42, 190, 101, 20));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(52, 310, 111, 20));
        updateButton = new QPushButton(tab);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(440, 260, 93, 29));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 150, 63, 20));
        searchButton = new QPushButton(tab);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(560, 310, 93, 29));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 120, 113, 26));
        sortByNameButton = new QPushButton(tab);
        sortByNameButton->setObjectName("sortByNameButton");
        sortByNameButton->setGeometry(QRect(910, 20, 101, 29));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(190, 240, 113, 26));
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(445, 50, 561, 192));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(200, 200, 113, 26));
        deleteButton = new QPushButton(tab);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(560, 260, 93, 29));
        sortButton = new QPushButton(tab);
        sortButton->setObjectName("sortButton");
        sortButton->setGeometry(QRect(670, 260, 93, 29));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 160, 113, 26));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(440, 310, 113, 26));
        dateEditDateCreation = new QDateEdit(tab);
        dateEditDateCreation->setObjectName("dateEditDateCreation");
        dateEditDateCreation->setGeometry(QRect(180, 310, 110, 26));
        sortByIdButton = new QPushButton(tab);
        sortByIdButton->setObjectName("sortByIdButton");
        sortByIdButton->setGeometry(QRect(440, 20, 93, 29));
        showClientCountButton = new QPushButton(tab);
        showClientCountButton->setObjectName("showClientCountButton");
        showClientCountButton->setGeometry(QRect(780, 260, 93, 29));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 120, 111, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(42, 240, 101, 20));
        insertButton = new QPushButton(tab);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(180, 350, 93, 29));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(910, 260, 93, 29));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        lineEditChatBot = new QLineEdit(tab_2);
        lineEditChatBot->setObjectName("lineEditChatBot");
        lineEditChatBot->setGeometry(QRect(20, 20, 181, 26));
        textEditChatHistory = new QTextEdit(tab_2);
        textEditChatHistory->setObjectName("textEditChatHistory");
        textEditChatHistory->setGeometry(QRect(10, 60, 1231, 371));
        chatBotSendButton = new QPushButton(tab_2);
        chatBotSendButton->setObjectName("chatBotSendButton");
        chatBotSendButton->setGeometry(QRect(210, 20, 93, 29));
        sendSmsButton = new QPushButton(tab_2);
        sendSmsButton->setObjectName("sendSmsButton");
        sendSmsButton->setGeometry(QRect(1110, 20, 131, 29));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(670, 20, 111, 20));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(770, 20, 331, 26));
        sendButton = new QPushButton(tab_2);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(350, 20, 83, 29));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(480, 20, 187, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        horizontalLayout->addWidget(label_11);

        lineEdit_13 = new QLineEdit(layoutWidget);
        lineEdit_13->setObjectName("lineEdit_13");

        horizontalLayout->addWidget(lineEdit_13);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1259, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "DATE_CREATION", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        sortByNameButton->setText(QCoreApplication::translate("MainWindow", "Trier par Nom", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "Actualiser", nullptr));
        sortByIdButton->setText(QCoreApplication::translate("MainWindow", "Trier par ID", nullptr));
        showClientCountButton->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CLIENT_ID", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TELEPHONE", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Gestion client", nullptr));
        chatBotSendButton->setText(QCoreApplication::translate("MainWindow", "ChatBot", nullptr));
        sendSmsButton->setText(QCoreApplication::translate("MainWindow", "Envoyer message", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "MSG \303\240 envoyer", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "AVG TEMP", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "id client", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Taches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
