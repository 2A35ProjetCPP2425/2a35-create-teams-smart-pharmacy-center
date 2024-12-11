#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"
#include "qnetworkreply.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString processChatCommand(const QString& command);
    QString handleGetClientCount();
    QString handleSearchClientById();
    QString formatClientDetails(const Client &client);
    QString handleGetMostLoyalClient();
    void onSmsResponse(QNetworkReply *reply);
    void sendSms(const QString &phoneNumber, const QString &message);
    void setupArduino();
    double calculateAverageTemperature();
    void sendCommandToArduino(double averageTemperature);

    void on_sendButton_clicked();


private slots:
    void on_insertButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_searchButton_clicked();

    void on_sortButton_clicked();

    void on_sortByIdButton_clicked();

    void on_sortByNameButton_clicked();

    void on_showClientCountButton_clicked();

    void on_chatBotSendButton_clicked();

    void on_sendSmsButton_clicked();

    void on_pushButton_clicked();

    void on_lineEditChatBot_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;

};

#endif // MAINWINDOW_H
