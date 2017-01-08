#ifndef QMQTT_SERVER_H
#define QMQTT_SERVER_H

#include <qmqtt_global.h>

#include <QObject>
#include <QAbstractSocket>
#include <QScopedPointer>
#include <QHostAddress>
#include <QTcpServer>

#include "qmqtt_client.h"

namespace QMQTT {

class Q_MQTT_EXPORT Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(quint16 port);

    void start();

protected:


    virtual void incomingConnection(qintptr socketDescriptor) override;

private:

    quint16 _port;

};

}// namespace QMQTT


#endif //QMQTT_SERVER_H
