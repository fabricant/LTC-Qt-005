#include <QCoreApplication>
#include <QString>
#include <QList>
#include <QStack>
#include <QDebug>

QString findLongestName(QList<QString> names);
QString findShortestName(QList<QString> names);
QStringList printLynn(QList<QString> names);
void printInBackOrder(QList<QString> names);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> names;
    names << "123" << "123456lynn" << "12345lynn" << "12";
    QString str("longest name %1");
    qDebug() << str.arg(findLongestName(names));

    str = findShortestName(names);
    str.prepend("shortest name ");
    qDebug() << str;
    str = printLynn(names).join(", ");
    qDebug() << str;
    printInBackOrder(names);
    return a.exec();
}


QString findLongestName(QList<QString> names) {
    QString returnString;
    QListIterator<QString> current(names);
    while (current.hasNext()) {
        QString next = current.next();
        if (next.length() > returnString.length()) {
            returnString = next;
        }
    }
    return returnString;
}


QString findShortestName(QList<QString> names) {
    QString returnString = "";

    for (auto current = names.begin(); current < names.end(); ++current) {
        if (current->length() < returnString.length() || !returnString.length()) {
            returnString = *current;
        }
    }
    return returnString;
}

QStringList printLynn(QList<QString> names) {
    QStringList list;
    foreach(QString str,  names) {
        if (str.endsWith("lynn")) {
            list.push_back(str);
        }
    }
    return list;
}


void printInBackOrder(QList<QString> names) {
    auto current = names.rbegin();

    qDebug() << "QList:";
    while (current !=  names.rend()) {
        qDebug() << *current;
        ++current;

    }

    qDebug() << "QStack:";
    QStack<QString> namesStack;
    namesStack += QStack<QString>::fromList(names);
    while (namesStack.size()) {
        qDebug () << namesStack.pop();
    }
}
