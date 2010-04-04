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

