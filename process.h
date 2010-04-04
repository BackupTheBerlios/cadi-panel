#ifndef PROCESS_H
#define PROCESS_H

#include <QString>
#include <QProcess>

class Process
{
private:
    bool com;
    void setCom(bool status);
    bool isCommandSet();

public:
    Process();
	bool isRunning(QString process);
    QString execShellProcess(int id_struct, int idParam);
    QString getShellCommand(int id_struct, int idParam);
};

#endif // PROCESS_H
