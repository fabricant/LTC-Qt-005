#include "textstreamreader.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

TextStreamReader::TextStreamReader(QObject *parent) : QObject(parent)
{

}

void TextStreamReader::readFromFile(QString fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
        return;

    QTextStream stream(&file);
    // TODO: open file in readonly mode

    // TODO: create QTextStream
    forever {
        // TODO: read from stream and emit required signal on each row
        QString line = stream.readLine();

        if (line.isNull() || line.isEmpty()) {
            break;
        }

        double data = line.toDouble();
        qDebug() << "Read" << data;
        emit dataReaded(data);
    }
    emit allDataReaded();
    qDebug() << "End of input file";
}
