#include "FileSystem.h"
#include "Compiler.h"

#include <QCoreApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>

FileSystem::FileSystem(QWidget* parent) : QListView(parent)
    , m_model(new QFileSystemModel(this))
    , m_dir(new QDir(QCoreApplication::applicationDirPath() + "/Project"))
{
    if (m_dir->exists() == false)
    {
        m_dir->mkdir(QCoreApplication::applicationDirPath() + "/Project");
    }

    m_model->setFilter(QDir::Files);
    m_model->setRootPath(QDir::currentPath());

    this->setModel(m_model);
    this->setRootIndex(m_model->index(QDir::currentPath() + "/Project"));

    connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(on_listView_clicked(QModelIndex)));
}

void FileSystem::on_listView_clicked(const QModelIndex &index)
{
    m_fileInfo = m_model->fileInfo(index);
    QFile file(m_fileInfo.absoluteFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File can not be openned";
    }

    QString file_text = file.readAll();
    emit insert_text(file_text);

    file.close();
}

void FileSystem::on_newFile_clicked()
{
    QInputDialog* input_dialog = new QInputDialog();
    input_dialog->setInputMode(QInputDialog::TextInput);
    input_dialog->setWindowTitle("New File");
    input_dialog->setLabelText("Name of the new file:");
    input_dialog->setOkButtonText("Add");
    input_dialog->exec();

    QString text = input_dialog->textValue();
    QFile file(QDir::currentPath() + "/Project/" + text);
    if (file.exists() && !text.isEmpty())
    {
        QMessageBox::warning(this, "Error", "The file with this name already exists");
    }
    else if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "File can not be created";
    }

    file.close();
}

void FileSystem::on_saveFile_clicked()
{
    QFile file(m_fileInfo.absoluteFilePath());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File can not be openned";
    }

    QTextStream out(&file);
    out << emit get_text();

    file.close();
}

void FileSystem::on_runFile_clicked()
{
    Compiler::compile(m_fileInfo);
}
