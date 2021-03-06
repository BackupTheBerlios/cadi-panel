#include "cadi.h"
#include "shellscripts.h"

Process::Process()
{
    this->setCom(false);
}

bool Process::isRunning(QString processName)
{
	QString processes;
	processes = this->execShellProcess(ShellScripts::PSTREE, ShellScripts::PSTREE_UTF8);

	if (processes.contains(processName) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

QString Process::getShellCommand(QString idCommand, QString idParam = ShellScripts::SS_NO_PARAM){
    QString command;

	command = this->shsc.getCommand(idCommand, idParam);

	if (command.isEmpty() == false){
        this->setCom(true);
    } else {
        this->setCom(false);
    }

    return command;
}

QString Process::getPippedShellCommand(QString idCommand1, QString idParam1, QString idCommand2, QString idParam2){
	QString command;

	command = this->shsc.getPippedCommand(idCommand1, idCommand2, idParam1, idParam2);

	if (command.isEmpty() == false){
		this->setCom(true);
	} else {
		this->setCom(false);
	}

	return command;
}

QString Process::execShellProcess(QString idCommand, QString idParam = ShellScripts::SS_NO_PARAM){
    QString result, command;
    QProcess *pro = NULL;

    //Get command
	command = this->getShellCommand(idCommand, idParam);
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

QString Process::execShellProcessCustomParam(QString idCommand, QString custParam){
	QString result, command;
	QProcess *pro = NULL;

	command = getShellCommand(idCommand, ShellScripts::SS_NO_PARAM);

	if (this->isCommandSet() == true){
		pro = new QProcess();
		pro->setProcessChannelMode(QProcess::MergedChannels);
		pro->start(command + " " + custParam);
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

QStringList Process::execShellProcessList(QString idCommand, QString idParam = ShellScripts::SS_NO_PARAM){
	QString res;
	QStringList result;

	res = execShellProcess(idCommand, idParam);

	if (res.contains("\n") == true){
		result = res.split("\n", QString::SkipEmptyParts);
	} else {
		result.append(res);
	}

	return result;
}

QString Process::execPippedShellProcess(QString idCommand1, QString idParam1, QString idCommand2, QString idParam2){
	QString result, command;
	QProcess pro;

	//Get command
	command = this->getPippedShellCommand(idCommand1, idParam1, idCommand2, idParam2);
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

QStringList Process::execPippedShellProcessList(QString idCommand1, QString idParam1, QString idCommand2, QString idParam2){
	QString res;
	QStringList result;

	res = execPippedShellProcess(idCommand1, idParam1, idCommand2, idParam2);

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
	bool ret = false;

    if (isRunning(processName) == true)
    {
		execShellProcessCustomParam(ShellScripts::KILLALL, processName);
		ret = true;
    }

	return ret;
}

void Process::setCom(bool status){
	this->com = status;
}

bool Process::isCommandSet(){
	return this->com;
}
