#include <QCoreApplication>
#include <qDebug>
#include <QAbstractOAuth2>

#include "main.h"

//Generated protobuf includes
#include "header.pb.h"

using namespace pubsub;

int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    qDebug("Starting...");
    QCoreApplication app(argc,argv);


    app.exec();

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
}
