#include "receiver.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QtWidgets>
#include"../gpp_qt/wfunction/wfunction.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);

    ui->label->setText("Listen to port 45454");

    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	ui->textBrowser->append("2222222222");
}

void MainWindow::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString text_to_print(datagram.data());
        text_to_print=QString::fromStdString(wfunction::joinquote(text_to_print.toStdString()));
        ui->textBrowser->append(text_to_print);
        //        ui->textBrowser->append(tr("Received datagram: \"%1\"").arg(datagram.data()));
    }
}

