#include "Compiler.h"

#include <QProcess>
#include <QDebug>
#include <QCoreApplication>
#include <QMessageBox>

void Compiler::compile(const QFileInfo& fileInfo)
{
    QStringList program_create;
    program_create << fileInfo.absoluteFilePath()
                   << "-o"
                   << QCoreApplication::applicationDirPath() + "/build-files/" + fileInfo.baseName() + ".out";
    QProcess process;
    process.start("g++", program_create);
    process.waitForReadyRead();
    QString compiled_errors = process.readAllStandardError();
    process.waitForFinished(-1);

    if (!compiled_errors.isEmpty())
    {
        QMessageBox msg_critical;
        msg_critical.setIcon(QMessageBox::Critical);
        msg_critical.setWindowTitle("Compiled Error");
        msg_critical.setText(compiled_errors);
        msg_critical.exec();
        return;
    }

    QStringList program_run;
    program_run << "-fa"
                << "'Monospace'"
                << "-fs"
                << "12"
                << "-hold"
                << "-e"
                << QCoreApplication::applicationDirPath() + "/build-files/" + fileInfo.baseName() + ".out";
    process.startDetached("xterm", program_run);
    process.waitForFinished(-1);

    qDebug() << process.errorString();
}
