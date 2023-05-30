#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QWidget>
#include <QDir>
#include <QFileSystemModel>
#include <QListView>

class FileSystem : public QListView
{
    Q_OBJECT

public:
    FileSystem(QWidget* parent = nullptr);

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

signals:
    void insert_text(QString text);

private:
    QFileSystemModel* m_model;
    QDir* m_dir;
};

#endif // FILESYSTEM_H
