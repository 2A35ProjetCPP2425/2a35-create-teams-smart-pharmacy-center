#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QByteArray>
#include <QAuthenticator>
#include "client.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QAuthenticator>
#include "mainwindow.h"
#include "qsqlquery.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlError>
#include <QSerialPort>
#include <QSerialPortInfo>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    arduino(new QSerialPort(this))  // Initialize arduino as a new QSerialPort object
{
    ui->setupUi(this);

    if (!arduino) {
        qDebug() << "Failed to create QSerialPort object.";
        QMessageBox::critical(this, "Error", "Unable to initialize Arduino connection.");
        return;  // Exit if Arduino setup fails
    }

    setupArduino();

    // Connect the send button to the send action
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::on_sendButton_clicked);

    // Load clients and comboBox items
    ui->tableView->setModel(Client::getAllClients());
    ui->comboBox->addItem("Message 1 : Rappel de rendez-vous");
    ui->comboBox->addItem("Message 2 : Commande prête");
    ui->comboBox->addItem("Message 3 : Remerciement");
}

MainWindow::~MainWindow() {
    delete ui;  // Cleanup UI
}


void MainWindow::on_insertButton_clicked() {
    // Vérifier que les champs ne sont pas vides
    if (ui->lineEdit->text().isEmpty() ||
        ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() ||
        ui->lineEdit_4->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Tous les champs sont obligatoires.");
        return;
    }

    // Valider que le premier champ est un entier
    bool ok;
    int clientId = ui->lineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID client doit être un nombre entier.");
        return;
    }

    // Validation des autres champs
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString adresse = ui->lineEdit_4->text();
    QDate dateCreation = ui->dateEditDateCreation->date();

    if (!dateCreation.isValid()) {
        QMessageBox::warning(this, "Erreur de saisie", "La date de création n'est pas valide.");
        return;
    }

    // Créer le client et insérer dans la base de données
    Client client(clientId, nom, prenom, adresse, dateCreation);
    if (Client::insertClient(client)) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout du client.");
    }

    // Mettre à jour la vue
    ui->tableView->setModel(Client::getAllClients());
}

void MainWindow::on_updateButton_clicked() {
    // Vérifier si l'ID client est valide
    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer l'ID du client.");
        return;
    }

    bool ok;
    int clientId = ui->lineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID du client doit être un nombre entier.");
        return;
    }

    // Vérifier si le client existe
    Client client;
    if (!client.clientExists(clientId)) {
        QMessageBox::warning(this, "Erreur", "Aucun client trouvé avec cet ID.");
        return;
    }

    // Valider les autres champs
    if (ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() ||
        ui->lineEdit_4->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Tous les champs doivent être remplis.");
        return;
    }

    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString adresse = ui->lineEdit_4->text();
    QDate dateCreation = ui->dateEditDateCreation->date();

    if (!dateCreation.isValid()) {
        QMessageBox::warning(this, "Erreur de saisie", "La date de création est invalide.");
        return;
    }

    // Créer l'objet Client avec les nouvelles données
    Client updatedClient(clientId, nom, prenom, adresse, dateCreation);

    // Mettre à jour les informations du client
    if (Client::updateClient(updatedClient)) {
        QMessageBox::information(this, "Succès", "Client mis à jour avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du client.");
    }

    // Actualiser la vue pour afficher les données mises à jour
    ui->tableView->setModel(Client::getAllClients());
}



void MainWindow::on_deleteButton_clicked() {
    int clientId = ui->lineEdit->text().toInt();  // Get client ID from the lineEdit

    // Create an instance of the Client class and check if the client exists
    Client client;  // Create a default Client object
    if (!client.clientExists(clientId)) {  // Call the non-static method on the object
        // If client does not exist, show a message box indicating that
        QMessageBox::warning(this, "Error", "Client ID does not exist.");
        return;
    }

    // Proceed to delete the client if the ID exists
    if (Client::deleteClient(clientId)) {  // Keep deleteClient as static (or non-static if needed)
        QMessageBox::information(this, "Success", "Client deleted successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete client.");
    }

    // Refresh the table view to show updated data
    ui->tableView->setModel(Client::getAllClients());
}



void MainWindow::on_searchButton_clicked() {
    QString searchQuery = ui->lineEdit_5->text();  // Get search query from the QLineEdit

    // Search for clients with the given query (search by name or ID)
    QSqlQueryModel* model = Client::searchClients(searchQuery);

    // Check if the model has any rows
    if (model->rowCount() == 0) {
        // Show a message box if no results are found
        QMessageBox::information(this, "No Results", "No client found with the given search criteria.");
    } else {
        // If results are found, set the model to the table view
        ui->tableView->setModel(model);
    }
}


void MainWindow::on_sortButton_clicked() {
    QString column = "NOM"; // Example: sort by name
    ui->tableView->setModel(Client::sortClients(column));
}
void MainWindow::on_sortByIdButton_clicked() {
    ui->tableView->setModel(Client::getSortedClientsById());  // Set the sorted model by CLIENT_ID
}

void MainWindow::on_sortByNameButton_clicked() {
    ui->tableView->setModel(Client::getSortedClientsByName());  // Set the sorted model by NOM
}
void MainWindow::on_showClientCountButton_clicked() {
    int clientCount = Client::getNumberOfClients();  // Call the static function to get the count
    QMessageBox::information(this, "Client Count", "Total number of clients: " + QString::number(clientCount));
}
void MainWindow::on_chatBotSendButton_clicked() {
    QString userInput = ui->lineEditChatBot->text();
    ui->textEditChatHistory->append("Vous: " + userInput);

    QString botResponse = processChatCommand(userInput);
    ui->textEditChatHistory->append("Chatbot: " + botResponse);

    ui->lineEditChatBot->clear();
}

QString MainWindow::processChatCommand(const QString &command)
{
    QString commandLower = command.toLower();

    // Commande pour obtenir le nombre de clients
    if (commandLower.contains("afficher le nombre des clients")) {
        return handleGetClientCount();
    }
    // Commande pour rechercher un client par ID
    else if (commandLower.contains("chercher un client")) {
        return handleSearchClientById();
    }
    // Commande pour obtenir le client le plus fidèle
    else if (commandLower.contains("afficher le client le plus fidèle")) {
        return handleGetMostLoyalClient();
    }
    else if (commandLower.contains("expliquer ce logiciel")) {
        return "Ce logiciel est un système de gestion des clients. Il permet de gérer les informations des clients, "
                   "de rechercher des clients par ID, de voir le nombre total de clients, d'ajouter, supprimer et mettre à jour "
                   "les informations des clients. Il est conçu pour aider à organiser et à traiter les données des clients de manière efficace.";

    }
    // Autres commandes peuvent être ajoutées ici de manière similaire
    else {
        return "Désolé, je n'ai pas compris votre demande. Essayez encore.";
    }
}


QString MainWindow::handleGetClientCount()
{
    int clientCount = Client::getNumberOfClients();
    return "Le nombre total de clients est : " + QString::number(clientCount);
}

QString MainWindow::handleSearchClientById()
{
    bool ok;
    int clientId = QInputDialog::getInt(this, "Rechercher un Client", "Entrez l'ID du client:", 0, 0, 100000, 1, &ok);

    // Vérifier si l'utilisateur a validé l'ID
    if (!ok) {
        return "Opération annulée ou ID du client invalide.";
    }

    // Recherche du client par ID
    Client client = Client::getClientById(clientId);

    // Si un client est trouvé, afficher ses informations
    if (client.getClientId() != 0) {
        return formatClientDetails(client);
    } else {
        return "Aucun client trouvé avec cet ID.";
    }
}

QString MainWindow::formatClientDetails(const Client &client)
{
    // Formater les détails du client pour une sortie lisible
    QString clientDetails = "Client trouvé:\n";
    clientDetails += "Nom: " + client.getNom() + "\n";
    clientDetails += "Email: " + client.getEmail() + "\n";
    clientDetails += "Téléphone: " + client.getTelephone() + "\n";
    clientDetails += "Date de création: " + client.getDateCreation().toString("dd/MM/yyyy") + "\n";
    return clientDetails;
}

QString MainWindow::handleGetMostLoyalClient()
{
    // Appel à la méthode statique de la classe Client pour obtenir le client le plus fidèle
    Client loyalClient = Client::getMostLoyalClient();

    if (loyalClient.getClientId() == 0) {
        return "Désolé, aucun client fidèle n'a été trouvé.";
    } else {
        return "Le client le plus fidèle est :\n"
               "Nom: " + loyalClient.getNom() + "\n"
               "Email: " + loyalClient.getEmail() + "\n"
               "Téléphone: " + loyalClient.getTelephone() + "\n"
               "Date de création: " + loyalClient.getDateCreation().toString("dd/MM/yyyy");
    }
}
void MainWindow::sendSms(const QString &phoneNumber, const QString &message)
{
    // Twilio API URL
    QString url = "https://api.twilio.com/2010-04-01/Accounts/ACbfe58a8efddb87283ca88c014483427a/Messages.json";

    // Créer un gestionnaire de requêtes
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Configuration de la requête
    QNetworkRequest request((QUrl(url)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Authentification Basic (Base64)
    QString accountSid = "ACbfe58a8efddb87283ca88c014483427a";  // Votre Account SID
    QString authToken = "dbe733567a8cb3db43597113de9d529c";  // Remplacez par votre Auth Token Twilio
    QString credentials = accountSid + ":" + authToken; // Forme correcte : SID:Token
    QByteArray authData = credentials.toUtf8().toBase64(); // Convertir en Base64
    request.setRawHeader("Authorization", "Basic " + authData);

    // Paramètres de la requête (message et destinataire)
    QByteArray data;
    data.append("To=+21656466773");
    data.append("&From=+17753737217");  // Remplacez par votre numéro Twilio
    data.append("&Body=" + message.toUtf8());

    // Envoyer la requête
    manager->post(request, data);

    // Connecter le signal pour traiter la réponse
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onSmsResponse);
}

// Slot pour traiter la réponse de l'API Twilio
void MainWindow::onSmsResponse(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        // Si l'envoi est réussi
        ui->textEditChatHistory->append("SMS envoyé avec succès !");
    } else {
        // Si une erreur est survenue
        ui->textEditChatHistory->append("Erreur d'envoi de SMS : " + reply->errorString());
    }

    // Nettoyer la réponse
    reply->deleteLater();
}

// Slot pour gérer le bouton d'envoi de SMS
void MainWindow::on_sendSmsButton_clicked()
{
    QString clientId = ui->lineEdit_13->text();  // ID client
    QString message;

    // Récupérer le message sélectionné dans la ComboBox
    int selectedIndex = ui->comboBox->currentIndex();
    if (selectedIndex == 0) {
        message = "Bonjour, c'est un rappel pour votre rendez-vous.";
    } else if (selectedIndex == 1) {
        message = "Votre commande est prête à être récupérée.";
    } else if (selectedIndex == 2) {
        message = "Merci pour votre achat. Nous espérons vous revoir bientôt.";
    }
    QSqlQuery query;
    query.prepare("SELECT TELEPHONE FROM CLIENTS WHERE CLIENT_ID = :clientId");
    query.bindValue(":clientId", clientId); // Lier le paramètre idp à la requête
    if (!query.exec()) {
        qDebug() << "Erreur de requête SELECT : " << query.lastError();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération de la telphone.");
        return;
    }
    QString phoneNumber;
    if (query.next()) {
        phoneNumber = query.value(0).toString();
    }
    // Ajouter l'ID client dans l'historique ou une confirmation (optionnel)
    ui->textEditChatHistory->append("Envoi d'un SMS à ID Client: " + clientId);

    // Appeler la fonction pour envoyer le SMS
    sendSms(phoneNumber, message);
}


void MainWindow::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer PDF"), "", tr("PDF Files (*.pdf)"));
    if (filePath.isEmpty()) {
        return; // L'utilisateur a annulé l'enregistrement
    }

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&writer);

    // Définir la police et la taille
    QFont font("Arial", 12);
    painter.setFont(font);

    // Titre
    painter.drawText(3000, 0, "Liste des Clients");
    painter.drawLine(100, 110, 500, 110); // Ligne sous le titre

    // Récupérer les données de la base de données
    QSqlQuery query("SELECT * FROM CLIENTS");
    int y = 130; // Position de départ pour écrire les données
    int margin = 50; // Marges

    while (query.next()) {
        // Récupérer les valeurs
        QString id = query.value("CLIENT_ID").toString();
        QString nom = query.value("NOM").toString();
        QString categorie = query.value("EMAIL").toString();
        QString dateAchat = query.value("TELEPHONE").toString();
        QString dateExpiration = query.value("DATE_CREATION").toString();


        // Écrire chaque champ sur une nouvelle ligne avec un en-tête
        painter.drawText(margin, y, QString("CLIENT_ID: %1").arg(id));
        y += 290; // Augmenter l'espacement entre Article ID et Nom
        painter.drawText(margin, y, QString("NOM: %1").arg(nom));
        y += 290;
        painter.drawText(margin, y, QString("EMAIL: %1").arg(categorie));
        y += 290;
        painter.drawText(margin, y, QString("TELEPHONE: %1").arg(dateAchat));
        y += 290;
        painter.drawText(margin, y, QString("DATE_CREATION: %1").arg(dateExpiration));
        y += 290; // Espacement supplémentaire avant le prochain article
        painter.drawLine(margin, y, 500, y); // Ligne de séparation entre les articles
        y += 290; // Espacement après la ligne de séparation

        // Vérifier si on dépasse la hauteur de la page
        if (y > writer.height() - 100) {
            painter.end();
            writer.newPage(); // Créer une nouvelle page si nécessaire
            painter.begin(&writer);
            painter.setFont(font); // Redéfinir la police
            y = 100; // Réinitialiser la position y
        }
    }

    painter.end();

    // Afficher un message de succès
    QMessageBox::information(this, tr("Succès"), tr("Les données ont été exportées vers le PDF avec succès."));
}


void MainWindow::on_lineEditChatBot_cursorPositionChanged(int arg1, int arg2)
{

}



void MainWindow::setupArduino() {
    QString portName = "COM4";

    // Setup Arduino connection
    arduino->setPortName(portName);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    // Try to open the port
    if (arduino->open(QIODevice::ReadWrite)) {
        qDebug() << "Connected to Arduino on port:" << portName;

        QMessageBox::information(this, "Connection Established", "Connected to Arduino!");
    } else {
        qDebug() << "Failed to connect to Arduino on port:" << portName;
        QMessageBox::critical(this, "Connection Error", "Could not connect to Arduino!");
    }
}


double MainWindow::calculateAverageTemperature() {
    QSqlQuery query;
    double sum = 0;
    int count = 0;

    query.prepare("SELECT TEMP FROM orders");
    if (query.exec()) {
        while (query.next()) {
            double temp = query.value(0).toDouble();
            sum += temp;
            count++;
        }

        if (count == 0) {
            qDebug() << "No temperatures found!";
            return 0;
        }

        double average = sum / count;
        qDebug() << "Average Temperature:" << average;
        return average;
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to execute query!");
        return -1;  // Indicate failure
    }
}

void MainWindow::sendCommandToArduino(double averageTemperature) {
    if (!arduino || !arduino->isOpen()) {
        qDebug() << "Arduino is not connected!";
        QMessageBox::critical(this, "Error", "Arduino is not connected!");
        return;
    }

    // Format the data as a string and send to Arduino
    QString command = QString("AVG:%1\n").arg(averageTemperature, 0, 'f', 2);  // Format with 2 decimal places


    // Send the data to Arduino
    qint64 bytesWritten = arduino->write(command.toUtf8());
    if (bytesWritten == -1) {
        qDebug() << "Failed to send data to Arduino:" << arduino->errorString();
        QMessageBox::critical(this, "Error", "Failed to send data to Arduino!");
    } else {
        qDebug() << "Sent to Arduino:" << command;
    }
}

void MainWindow::on_sendButton_clicked() {
    double avgTemp = calculateAverageTemperature();
    if (avgTemp >= 0) {
        sendCommandToArduino(avgTemp);
    } else {
        qDebug() << "Error: Unable to calculate average temperature!";
        QMessageBox::critical(this, "Error", "Failed to calculate average temperature!");
    }
}
