#ifndef PROCESS_H
#define PROCESS_H

#include <QString>
#include <QProcess>

class Process
{
public:
    Process();
    static bool isRunning(QString process);
};

#endif // PROCESS_H
