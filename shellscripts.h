#ifndef __SHELLSCRIPTS_H__
#define __SHELLSCRIPTS_H__

#include <QObject>
#include <QString>

class ShellScripts : public QObject{
public:
    enum SS_STRUCTS {SS_LSB_RELEASE = 1};
    ShellScripts();
    ~ShellScripts();
    QString getCommand(int idStruct, QString param = NULL);

private:
    struct _LSB_RELEASE{
      QString LSB_VERSION;
      QString LSB_CODENAME;
      QString name;
      QString param_version;
      QString param_codename;

      inline bool init(){
        bool ret = false;
        this->LSB_VERSION = "LSB_VERSION";
        this->LSB_CODENAME = "LSB_CODENAME";
        this->name = "lsb_release";
        this->param_version = " -s -r";
        this->param_codename = " -s -c";
        ret = true;
        return ret;
      }
    } *LSB_RELEASE;

    QString get_lsb_release(QString param);
};

#endif // __SHELLSCRIPTS_H__
