#include "FileSystem.h"

#include <QCoreApplication>
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
    connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_listView_doubleClicked(QModelIndex)));
}

void FileSystem::on_listView_doubleClicked(const QModelIndex &index)
{
    QFileInfo fileInfo = m_model->fileInfo(index);
    QFile file(fileInfo.absoluteFilePath());
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "File can not be openned";
    }

    QString file_text = file.readAll();
    emit insert_text(file_text);
    file.close();
}
