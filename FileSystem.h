#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QDir>
#include <QFileSystemModel>
#include <QListView>

class FileSystem : public QListView
{
    Q_OBJECT

public:
    FileSystem(QWidget* parent = nullptr);

private slots:
    void on_listView_clicked(const QModelIndex &index);
    void on_newFile_clicked();
    void on_saveFile_clicked();
    void on_runFile_clicked();

signals:
    void insert_text(QString text);
    QString get_text();

private:
    QFileSystemModel* m_model;
    QDir* m_dir;
    QFileInfo m_fileInfo;
};

#endif // FILESYSTEM_H
