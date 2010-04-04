#include "shellscripts.h"

//Public functions
ShellScripts::ShellScripts(){
}

ShellScripts::~ShellScripts(){
    if (this->LSB_RELEASE != NULL){
        delete this->LSB_RELEASE;
    }
}

QString ShellScripts::getCommand(int idStruct, QString param){
    QString command;

    switch(idStruct){
         //_LSB_RELEASE
        case SS_LSB_RELEASE:
            command = get_lsb_release(param);
            break;
        default:
            break;
    }

    return command;
}

//Private functions
QString ShellScripts::get_lsb_release(QString param){
    QString command, par;

    this->LSB_RELEASE = new _LSB_RELEASE();
    if (this->LSB_RELEASE->init() == true){
        command = this->LSB_RELEASE->name;
        if (param.compare(this->LSB_RELEASE->LSB_CODENAME) == 0){
            par = this->LSB_RELEASE->param_codename;
        } else if (param.compare(this->LSB_RELEASE->LSB_VERSION) == 0) {
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
