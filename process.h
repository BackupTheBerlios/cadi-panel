#ifndef PROCESS_H
#define PROCESS_H

#include <QString>

class Process
{
private:
    bool com;
    void setCom(bool status);
    bool isCommandSet();

public:
    Process();
    bool isRunning(QString process);
    bool kill(QString processName);
	QString execShellProcess(QString id_struct, QString idParam);
	QStringList execShellProcessList(QString idCommand, QString idParam);
	QString execPippedShellProcess(QString idCommand1, QString idParam1, QString idCommand2, QString idParam2);
	QStringList execPippedShellProcessList(QString idCommand1, QString idParam1, QString idCommand2, QString idParam2);
	QString getShellCommand(QString id_struct, QString idParam);
	QString getPippedShellCommand(QString idCommand1, QString idParam1, QString idCommand2, QString idParam2);
};

#endif // PROCESS_H
