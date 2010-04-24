#include "shellscripts.h"

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
	//XML file representing shell commands and arguments
    this->ficXml = "../common/shellscripts.xml";
	//Required node names (shellscripts.xml file)
	this->name = "name";
	this->param = "par";
	//Open shellscripts.xml file and create DOM document
	QFile fic(ficXml);
	if (fic.open(QIODevice::ReadOnly) == true){
		this->doc.setContent(&fic);
		fic.close();
	}
}

//Gets a shell command (name + arguments) from the shellscripts.xml file
QString ShellScripts::getCommand(QString idCommand, QString idParam){
    QString command;
	QDomNodeList nl;
	QDomNode n, a;
	QDomElement e;
	QDomText t;
	QTextStream out(stdout);

	//Get the command node
	if (idCommand.isNull() == false && idCommand.isEmpty() == false){
		nl = this->doc.elementsByTagName(idCommand);
		if (nl.isEmpty() == false){
			n = nl.item(0);
		}

		//Get the command name
		if (n.isNull() == false){
			//Get the node elements
			e = n.toElement();
			if (e.isNull() == false){
				//Get the "name" node
				nl = e.elementsByTagName(this->name);
				if (nl.isEmpty() == false){
					n = nl.item(0);
					//Get the value of the node
					command += n.firstChild().nodeValue();
				}
			}
		}
	}

	//Get the param
	if (command.isEmpty() == false && idParam.isNull() == false && idParam.isEmpty() == false){
		if (e.isNull() == false){
			//Get the "params" nodes
			nl = e.elementsByTagName(this->param);
			if (nl.isEmpty() == false){
				for (int i = 0; i < nl.count(); ++i){
					n = nl.item(i);
					if (n.isNull() == false){
						//Get the "name" attribute
						if (n.hasAttributes() == true){
							e = n.toElement();
							QString atrName = e.attribute(this->name);
							//is it the wanted param?
							if (atrName.compare(idParam) == 0){
								//Get the value of the node
								if (n.firstChild().isText() == true){
									command += " " + n.firstChild().nodeValue();
									break;
								}
							}
						}
					}
				}
			}
		}
	}

    return command;
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



