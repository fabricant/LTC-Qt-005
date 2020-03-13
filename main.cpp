#include <QCoreApplication>
#include <QString>
#include <QLinkedList>
#include <QDebug>

QString findLongestName(QLinkedList<QString> names);
QString findShortestName(QLinkedList<QString> names);
QStringList printLynn(QLinkedList<QString> names);
void printInBackOrder(QLinkedList<QString> names);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QLinkedList<QString> names;
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


QString findLongestName(QLinkedList<QString> names) {
    QString returnString;
    QLinkedListIterator<QString> iterator(names);
    while (iterator.hasNext()) {
        QString next = iterator.next();
        if (next.length() > returnString.length()) {
            returnString = next;
        }
    }
    return returnString;
}


QString findShortestName(QLinkedList<QString> names) {
    auto iterator = names.begin();
    QString returnString = *iterator;
    ++iterator;

    while (iterator != names.end()) {
        if (iterator->length() < returnString.length()) {
            returnString = *iterator;
        }
        ++iterator;
    }
    return returnString;
}

QStringList printLynn(QLinkedList<QString> names) {
    QStringList list;
    foreach(QString str,  names) {
        if (str.right(4) == "lynn") {
            list.push_back(str);
        }
    }
    return list;
}


void printInBackOrder(QLinkedList<QString> names) {
    auto iterator = names.rbegin();
    while (iterator !=  names.rend()) {
        qDebug() << *iterator;
        ++iterator;

    }
}
