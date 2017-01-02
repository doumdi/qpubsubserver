#include <QCoreApplication>
#include <qDebug>
#include <QAbstractOAuth2>

#include "main.h"

//Generated protobuf includes
#include "header.pb.h"


int main(int argc, char* argv[])
{
    qDebug("Starting...");
    QCoreApplication app(argc,argv);

    Person person;

    person.set_name("Test");
    person.set_id(0);
    person.set_email("test@gmail.com");

    QString test = QString::fromStdString(person.SerializeAsString());

    Person person2;
    person2.ParseFromString(test.toStdString());

    qDebug() << test << QString::fromStdString(person2.SerializeAsString());

    app.exec();
}
