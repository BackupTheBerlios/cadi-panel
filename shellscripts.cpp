#include "shellscripts.h"

//Public functions
ShellScripts::ShellScripts(){
}

ShellScripts::~ShellScripts(){
}

QString ShellScripts::getCommand(int idStruct, int idParam){
    QString command;

    switch(idStruct){
        case SS_LSB_RELEASE:
            command = get_lsb_release(idParam);
            break;
        case SS_UNAME:
            command = get_uname(idParam);
            break;
		case SS_PSTREE:
			command = get_pstree(idParam);
			break;
        default:
            break;
    }

    return command;
}

QString ShellScripts::getPipedCommand(int idStruct1, int idStruct2, int idParam1 = ShellScripts::SS_NO_PARAM, int idParam2 = ShellScripts::SS_NO_PARAM){
	QString command1, command2;

	command1 = getCommand(idStruct1, idParam1);
	command2 = getCommand(idStruct2, idParam2);

	if (command1.isEmpty() == false && command2.isEmpty() == false){
		command1 += " | " + command2;
	} else {
		command1.clear();
	}

	return command1;
}

//Private functions
QString ShellScripts::get_lsb_release(int idParam){
    QString command, par;

    this->LSB_RELEASE = new _LSB_RELEASE();

    if (this->LSB_RELEASE->init() == true){
        command = this->LSB_RELEASE->name;

		if (idParam == this->SS_LSB_RELEASE_CODENAME){
            par = this->LSB_RELEASE->param_codename;
		} else if (idParam == this->SS_LSB_RELEASE_VERSION) {
            par = this->LSB_RELEASE->param_version;
        }

        if (par.isEmpty() == false){
            command += par;
        } else {
            command.clear();
        }
    }

    return command;
}

QString ShellScripts::get_uname(int idParam){
    QString command, par;

    this->UNAME = new _UNAME();

    if (this->UNAME->init() == true){
        command = this->UNAME->name;

		if (idParam == this->SS_UNAME_KERNEL_VERSION){
            par = this->UNAME->param_kernel_version;
        }

		if (par.isEmpty() == false){
            command += par;
        } else {
            command.clear();
        }
    }

    return command;
}

QString ShellScripts::get_pstree(int idParam){
	QString command, par;

	this->PSTREE = new _PSTREE();

	if (this->PSTREE->init() == true){
		command = this->PSTREE->name;

		if (idParam == this->SS_PSTREE_UTF8){
			par = this->PSTREE->param_utf8;
		}

		if (par.isEmpty() == false){
			command += par;
		} else {
			command.clear();
		}
	}

	return command;
}

QString ShellScripts::get_cat(int idParam){
	QString command, par;

	this->CAT = new _CAT();

	if (this->CAT->init() == true){
		command = this->CAT->name;

		if (idParam == this->SS_CAT_CPUINFO){
			par = this->CAT->param_cpuinfo;
		}

		if (par.isEmpty() == false){
			command += par;
		} else {
			command.clear();
		}
	}

	return command;
}

QString ShellScripts::get_grep(int idParam){
	QString command, par;

	this->GREP = new _GREP();

	if (this->GREP->init() == true){
		command = this->GREP->name;

		switch(idParam){
			case SS_GREP_CPUMODELNAME:
				par = this->GREP->param_cpumodelname;
				break;
			case SS_GREP_MEMTOTAL:
				par = this->GREP->param_meminfomemtotal;
				break;
			case SS_GREP_MEMFREE:
				par = this->GREP->param_meminfomemfree;
				break;
			case SS_GREP_SWAPTOTAL:
				par = this->GREP->param_meminfoswaptotal;
				break;
			case SS_GREP_SWAPFREE:
				par = this->GREP->param_meminfoswapfree;
				break;
			default:
				break;
		}

		if (par.isEmpty() == false){
			command += par;
		} else {
			command.clear();
		}
	}

	return command;
}


