#ifndef __SHELLSCRIPTS_H__
#define __SHELLSCRIPTS_H__

#include <QObject>
#include <QString>

class ShellScripts : public QObject{
private:
    //SCRIPT: LSB_RELEASE
    struct _LSB_RELEASE{
        QString name;
        QString param_version;
        QString param_codename;

        inline bool init(){
			bool ret = false;
			this->name = "lsb_release";
			this->param_version = " -s -r";
			this->param_codename = " -s -c";
			ret = true;
			return ret;
        }
	} *LSB_RELEASE;

    QString get_lsb_release(int param);

    //SCRIPT: UNAME
    struct _UNAME{
        QString name;
        QString param_kernel_version;

        inline bool init(){
            bool ret = false;
            this->name = "uname";
            this->param_kernel_version = " -r -m";
            ret = true;
            return ret;
        }
	} *UNAME;

	QString get_uname(int param);

	//SCRIPT: PSTREE
	struct _PSTREE{
		QString name;
		QString param_utf8;

		inline bool init(){
			bool ret = false;
			this->name = "pstree";
			this->param_utf8 = " -U";
			ret = true;
			return ret;
		}
	} *PSTREE;

	QString get_pstree(int param);

	//SCRIPT: CAT
	struct _CAT{
		QString name;
		QString param_cpuinfo;

		inline bool init(){
			bool ret = false;
			this->name = "cat";
			this->param_cpuinfo = " /proc/cpuinfo";
			ret = true;
			return ret;
		}
	} *CAT;

	QString get_cat(int param);

	//SCRIPT: GREP
	struct _GREP{
		QString name;
		QString param_cpumodelname;

		inline bool init(){
			bool ret = false;
			this->name = "grep";
			this->param_cpumodelname = " 'model name'";
			ret = true;
			return ret;
		}
	} *GREP;

	QString get_grep(int param);

public:
	enum SS_STRUCTS {SS_LSB_RELEASE = 1, SS_UNAME, SS_PSTREE, SS_CAT, SS_GREP};
	enum SS_PARAM {SS_NO_PARAM = 0, SS_LSB_RELEASE_VERSION, SS_LSB_RELEASE_CODENAME, SS_UNAME_KERNEL_VERSION, SS_PSTREE_UTF8, SS_CAT_CPUINFO, SS_GREP_CPUMODELNAME};

	static SS_STRUCTS ID;
    static SS_PARAM PAR;

    ShellScripts();
    ~ShellScripts();
    QString getCommand(int idStruct, int idParam = ShellScripts::SS_NO_PARAM);
	QString getPipedCommand(int idStruct1, int idStruct2, int idParam1, int idParam2);

};

#endif // __SHELLSCRIPTS_H__
