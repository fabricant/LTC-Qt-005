#include "mainwidget.h"
#include "ui_mainwidget.h"

#include "textstreamreader.h"
#include "datastreamwriter.h"

#include <QFileDialog>
#include <QThread>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowTitle("Converter");
    // TODO: create and start threads

    readerThread = new QThread;
    writerThread = new QThread;
    readerThread->start();
    writerThread->start();
}

MainWidget::~MainWidget()
{
    // TODO: destroy threads
    delete readerThread;
    delete writerThread;
    delete ui;
}

void MainWidget::on_inputFilePushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    findChild<QLineEdit *>("inputFileLineEdit")->setText(fileName);
}

void MainWidget::on_outputFilePushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    findChild<QLineEdit *>("outputFileLineEdit")->setText(fileName);
}

void MainWidget::on_convertPushButton_clicked()
{
    QString inputFile = findChild<QLineEdit *>("inputFileLineEdit")->text();
    QString outputFile = findChild<QLineEdit *>("outputFileLineEdit")->text();
    TextStreamReader *reader = new TextStreamReader;
    DataStreamWriter *writer = new DataStreamWriter(outputFile);
    reader->moveToThread(readerThread);
    writer->moveToThread(writerThread);
    // TODO: move reader and writer to required threads

    // TODO: connect reader and writer
    connect(reader, &TextStreamReader::dataReaded,
    writer, &DataStreamWriter::writeData);
    connect(reader, &TextStreamReader::allDataReaded,
    writer, &QObject::deleteLater);
    connect(reader, &TextStreamReader::allDataReaded,
    reader, &QObject::deleteLater);

    reader->readFromFile(inputFile);
}
