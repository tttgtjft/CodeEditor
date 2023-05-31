#include "mainwindow.h"
#include "FileSystem.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->fileSystem, SIGNAL(insert_text(QString)), this, SLOT(insert_codeEditor(QString)));
    connect(ui->fileSystem, SIGNAL(get_text()), this, SLOT(get_text_codeEditor()));
    connect(ui->themeChanger, SIGNAL(is_checked()), this, SLOT(isChecked_themeChanger()));
    connect(ui->themeChanger, SIGNAL(is_checked()), ui->codeEditor, SLOT(change_lineColor()));
    connect(ui->action_newFile, SIGNAL(triggered()), ui->fileSystem, SLOT(on_newFile_clicked()));
    connect(ui->action_saveFile, SIGNAL(triggered()), ui->fileSystem, SLOT(on_saveFile_clicked()));
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

QString MainWindow::get_text_codeEditor()
{
    return ui->codeEditor->toPlainText();
}
