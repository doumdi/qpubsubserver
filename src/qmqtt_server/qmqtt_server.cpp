#include "qmqtt_server.h"
#include "QDebug"

namespace QMQTT
{
Server::Server(quint16 port)
    : _port(port)
{

}

void Server::start()
{
    this->listen(QHostAddress::Any, _port);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Server::incomingConnection = " << socketDescriptor;
}

} //namespace QMQTT
