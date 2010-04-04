#include "cadi.h"
#include "shellscripts.h"

Process::Process()
{
    this->setCom(false);
}

bool Process::isRunning(QString processName)
{
	QString processes;
	processes = this->execShellProcess(ShellScripts::SS_PSTREE, ShellScripts::SS_PSTREE_UTF8);

	if (processes.contains(processName) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

QString Process::getShellCommand(int idStruct, int idParam = ShellScripts::SS_NO_PARAM){
    QString command;
    ShellScripts shsc;

    command = shsc.getCommand(idStruct, idParam);

	if (command.isEmpty() == false){
        this->setCom(true);
    } else {
        this->setCom(false);
    }

    return command;
}

QString Process::execShellProcess(int idStruct, int idParam = ShellScripts::SS_NO_PARAM){
    QString result, command;
    QProcess *pro = NULL;

    //Get command
	command = this->getShellCommand(idStruct, idParam);
    //Process command
    if (this->isCommandSet() == true){
        pro = new QProcess();
        pro->setProcessChannelMode(QProcess::MergedChannels);
        pro->start(command);
        if (pro->waitForFinished()) {
            result = QString(pro->readAll());
            //Trim
            if (result != NULL && result.isEmpty() == false){
                result = result.trimmed();
            }
        }
        pro->close();
		this->setCom(false);
	}

    //Free mem
    if (pro != NULL){
        delete pro;
    }

    return result;
}

void Process::setCom(bool status){
	this->com = status;
}

bool Process::isCommandSet(){
	return this->com;
}
