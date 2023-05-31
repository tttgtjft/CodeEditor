#ifndef COMPILER_H
#define COMPILER_H

#include <QFileInfo>

class Compiler
{
public:
    static void compile(const QFileInfo& fileInfo);
};

#endif // COMPILER_H
