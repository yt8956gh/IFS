#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QList>
#include <algorithm>
#include "clientinfo.h"


QT_BEGIN_NAMESPACE
class QTcpServer;
class QTcpSocket;
class QAction;
QT_END_NAMESPACE


namespace myserver {

    class server:public QObject
    {

        Q_OBJECT

    public:

        explicit server(QObject *parent);

    public slots:
        void start();
        void listen(unsigned short);
        void acceptConnection();
        void updateServerProgress();
        void displayError(QAbstractSocket::SocketError socketError);

    signals:
        void getData(QString);
        void clientChange(QList<clientInfo>);

    private:
        QTcpServer tcpServer;
        QTcpSocket tcpClient;
        QTcpSocket *tcpServerConnection;
        int bytesToWrite;
        int bytesWritten;
        int bytesReceived;
        QList<clientInfo> clientList;
    };
}


#endif // SERVER_H
