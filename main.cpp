#include <QCoreApplication>
#include "bankaccount.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // don't change type of account, use it as QObject*
    QObject *account = new BankAccount;
    account->setProperty(     "holderName", QString("John Doe") );
    qDebug() <<     account->property("holderName").toString();

    account->setProperty(     "balance", QVariant::fromValue(200L) );
    qDebug() << account->property("balance").toLongLong();
    // TODO: set holder name
    // TODO: print it to qDebug()

    // TODO: get balance from property to qDebug()

    return a.exec();
}
