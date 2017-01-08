#ifndef _MAIN_H_
#define _MAIN_H_

#include <QCoreApplication>
#include <QSharedPointer>
#include "qmqtt_server.h"
#include "qmqtt_client.h"


class ServerApp : public QCoreApplication
{
    Q_OBJECT

public:

    const quint16 DEFAULT_PORT = 1234;


    ServerApp(int &argc, char* argv[])
     : QCoreApplication(argc,argv)
    {
        _server = QSharedPointer<QMQTT::Server>(new QMQTT::Server(DEFAULT_PORT));
        //Will start listening
        _server->start();

        _client = QSharedPointer<QMQTT::Client>(new QMQTT::Client
                                                (QHostAddress::LocalHost,DEFAULT_PORT,this));

        _client->setAutoReconnect(true);
        _client->setClientId("_INTERNAL_TEST_");
        _client->setUsername("joe");
        _client->setPassword("password");
        _client->connectToHost();

    }

public slots:

private:

    ///Server pointer
    QSharedPointer<QMQTT::Server> _server;

    ///Client - for testing
    QSharedPointer<QMQTT::Client> _client;

    Q_DISABLE_COPY(ServerApp)
};

#endif //_MAIN_H_
