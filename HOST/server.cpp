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
    qDebug()<<recv;

    emit recv_data(recv);

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

