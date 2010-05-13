#include "shellscripts.h"
#include "cadi.h"

//DEFINE STATIC VARIABLES
QString ShellScripts::SS_NO_PARAM = "";
//Node and attribute names (shellscripts.xml file)
QString ShellScripts::LSB_RELEASE = "LSB_RELEASE";
QString ShellScripts::LSB_RELEASE_VERSION = "LSB_RELEASE_VERSION";
QString ShellScripts::LSB_RELEASE_CODENAME = "LSB_RELEASE_CODENAME";
QString ShellScripts::GREP = "GREP";
QString ShellScripts::GREP_MODELNAME = "GREP_MODELNAME";
QString ShellScripts::GREP_MEMTOTAL = "GREP_MEMTOTAL";
QString ShellScripts::GREP_MEMFREE = "GREP_MEMFREE";
QString ShellScripts::GREP_SWAPTOTAL = "GREP_SWAPTOTAL";
QString ShellScripts::GREP_SWAPFREE = "GREP_SWAPFREE";
QString ShellScripts::CAT = "CAT";
QString ShellScripts::CAT_CPUINFO = "CAT_CPUINFO";
QString ShellScripts::CAT_MEMINFO = "CAT_MEMINFO";
QString ShellScripts::PSTREE = "PSTREE";
QString ShellScripts::PSTREE_UTF8 = "PSTREE_UTF8";
QString ShellScripts::UNAME = "UNAME";
QString ShellScripts::UNAME_KERNELVERSION = "UNAME_KERNELVERSION";
QString ShellScripts::KILLALL = "KILLALL";
QString ShellScripts::FREE = "FREE";
QString ShellScripts::FREE_MEGALOWTOTAL = "FREE_MEGALOWTOTAL";


//Public functions
ShellScripts::ShellScripts(){
}

//Gets a shell command (name + arguments) from the shellscripts.xml file
QString ShellScripts::getCommand(QString idCommand, QString idParam){
	QString com;
	Result *res = Cadi::db->getConnection("SELECT command FROM ShellScripts_commands WHERE name = '" + idCommand + "'");

	//Get the command
	if (idCommand.isNull() == false && idCommand.isEmpty() == false){
		res->execSql();
		if (res->size() > 0){
			com = res->get(0, 0);
		}
		if (idParam.isNull() == false && idParam != "" && idParam.compare(ShellScripts::SS_NO_PARAM) != 0){
			res->execSql("SELECT param FROM ShellScripts_Params WHERE name = '" + idParam + "'");
			if (res->size() > 0){
				com += " " + res->get(0, 0);
			}
		}
	}

	return com;
}

//Gets two shell commands and pipes them
QString ShellScripts::getPippedCommand(QString idCommand1, QString idCommand2, QString idParam1 = ShellScripts::SS_NO_PARAM, QString idParam2 = ShellScripts::SS_NO_PARAM){
	QString command1, command2;

	//Get first command
	command1 = getCommand(idCommand1, idParam1);
	//Get second command
	command2 = getCommand(idCommand2, idParam2);

	//Pipe them
	if (command1.isEmpty() == false && command2.isEmpty() == false){
		command1 += " | " + command2;
	} else {
		command1.clear();
	}

	return command1;
}



