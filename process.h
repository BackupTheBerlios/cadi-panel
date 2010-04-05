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
    QString execShellProcess(int id_struct, int idParam);
	QStringList execShellProcessList(int idStruct, int idParam);
	QString execPipedShellProcess(int idStruct1, int idStruct2, int idParam1, int idParam2);
	QStringList execPipedShellProcessList(int idStruct1, int idStruct2, int idParam1, int idParam2);
    QString getShellCommand(int id_struct, int idParam);
	QString getPipedShellCommand(int idStruct1, int idStruct2, int idParam1, int idParam2);
};

#endif // PROCESS_H
