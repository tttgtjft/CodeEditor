#include "mainwindow.h"
#include "FileSystem.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->fileSystem, SIGNAL(insert_text(QString)), this, SLOT(insert_codeEditor(QString)));
    connect(ui->themeChanger, SIGNAL(is_checked()), this, SLOT(isChecked_themeChanger()));
    connect(ui->themeChanger, SIGNAL(is_checked()), ui->codeEditor, SLOT(change_lineColor()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insert_codeEditor(QString text)
{
    ui->codeEditor->clear();
    ui->codeEditor->insertPlainText(text);
}

bool MainWindow::isChecked_themeChanger()
{
    return ui->themeChanger->isChecked();
}
