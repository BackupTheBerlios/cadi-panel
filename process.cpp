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

QString Process::getPippedShellCommand(int idStruct1, int idStruct2, int idParam1 = ShellScripts::SS_NO_PARAM, int idParam2 = ShellScripts::SS_NO_PARAM){
	QString command;
	ShellScripts shsc;

        command = shsc.getPippedCommand(idStruct1, idStruct2, idParam1, idParam2);

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

QStringList Process::execShellProcessList(int idStruct, int idParam = ShellScripts::SS_NO_PARAM){
	QString res;
	QStringList result;

	res = execShellProcess(idStruct, idParam);

	if (res.contains("\n") == true){
		result = res.split("\n", QString::SkipEmptyParts);
	} else {
		result.append(res);
	}

	return result;
}

QString Process::execPippedShellProcess(int idStruct1, int idParam1, int idStruct2, int idParam2){
	QString result, command;
	QProcess pro;

	//Get command
        command = this->getPippedShellCommand(idStruct1, idStruct2, idParam1, idParam2);
	//Process command
	if (this->isCommandSet() == true){
		pro.setProcessChannelMode(QProcess::MergedChannels);
		pro.start(command);
		if (pro.waitForFinished()) {
			result = QString(pro.readAll());
			//Trim
			if (result != NULL && result.isEmpty() == false){
				result = result.trimmed();
			}
		}
		pro.close();
		this->setCom(false);
	}

	return result;
}

QStringList Process::execPippedShellProcessList(int idStruct1, int idParam1, int idStruct2, int idParam2){
	QString res;
	QStringList result;

        res = execPippedShellProcess(idStruct1, idParam1, idStruct2, idParam2);

	if (res.isEmpty() == false){
		res = res.trimmed();
	}

	if (res.contains("\n") == true){
		result = res.split("\n", QString::SkipEmptyParts);
	} else {
		result.append(res);
	}

	return result;
}

//Kill the indicated process
bool Process::kill(QString processName)
{
    if (isRunning(processName) == true)
    {
        QProcess *killall = new QProcess();
        killall->start("killall " + processName);
        if (killall->waitForFinished())
        {
            killall->close();
            if (isRunning(processName) == false)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

void Process::setCom(bool status){
	this->com = status;
}

bool Process::isCommandSet(){
	return this->com;
}
