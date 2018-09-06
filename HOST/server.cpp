#include "server.h"

static const int TotalBytes = 50 * 1024 * 1024;
static const int PayloadSize = 64 * 1024; // 64

using namespace myserver;

server::server(QObject *parent):QObject(parent)
{
    connect(&tcpServer, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    connect(&tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    this->listen(8700);
}

void server::start()
{
    if(!tcpServer.isListening() && !tcpServer.listen()) {
            return;
    }
}

void server::listen(unsigned short port)
{
    this->tcpServer.listen(QHostAddress::Any, port);
}

void server::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection, SIGNAL(readyRead()),
            this, SLOT(updateServerProgress()));
    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void server::updateServerProgress()
{
    QString recv = tcpServerConnection->readAll();

    if(!recv.isEmpty())//判斷收到的訊息否為空
    {
       clientInfo* clientInfoTmp = new clientInfo(
                   tcpServerConnection->peerAddress().toString().split(":").last(),
                   "ESP","溫溼度/功耗",true);

       //如果這次的客戶端是新的，就把它新增到Clientlist裡面，
       //並發出clientChange信號要求mainWindow中的QtableWidget重繪。
        if(std::find(clientList.begin(),clientList.end(), *clientInfoTmp)!=clientList.end())
        {
               clientList.append(*clientInfoTmp);
               emit clientChange(clientList);
        }
    }

    qDebug()<<"-------------------------------";
    qDebug()<<recv;
    qDebug()<<tcpServerConnection->peerAddress().toString();
    qDebug()<<tcpServerConnection->peerName();

    emit getData(recv);

    tcpServerConnection->close();
    return;
}

void server::displayError(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
    {
        qDebug()<<"ERRO: "<<tcpServer.errorString();
        tcpServerConnection->close();
        return;
    }
}

