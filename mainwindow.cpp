#include "mainwindow.h"
#include "FileSystem.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->listView, SIGNAL(insert_text(QString)), this, SLOT(insert_plainText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insert_plainText(QString text)
{
    ui->viewport->clear();
    ui->viewport->insertPlainText(text);
}
