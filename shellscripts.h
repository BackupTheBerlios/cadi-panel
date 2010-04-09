#ifndef __SHELLSCRIPTS_H__
#define __SHELLSCRIPTS_H__

#include <QObject>
#include <QString>
#include <QtXml>

class ShellScripts{
private:
	QString ficXml;
	QString name;
	QString param;
	QDomDocument doc;

public:

	//Command without param
	static QString SS_NO_PARAM;
	//Node names
	static QString LSB_RELEASE;
	static QString LSB_RELEASE_VERSION;
	static QString LSB_RELEASE_CODENAME;
	static QString GREP;
	static QString GREP_MODELNAME;
	static QString GREP_MEMTOTAL;
	static QString GREP_MEMFREE;
	static QString GREP_SWAPTOTAL;
	static QString GREP_SWAPFREE;
	static QString CAT;
	static QString CAT_CPUINFO;
	static QString CAT_MEMINFO;
	static QString PSTREE;
	static QString PSTREE_UTF8;
	static QString UNAME;
	static QString UNAME_KERNELVERSION;
	static QString KILLALL;


    ShellScripts();
    ~ShellScripts();
	QString getCommand(QString idNode, QString idParam);
	QString getPippedCommand(QString idStruct1, QString idStruct2, QString idParam1, QString idParam2);

};


#endif // __SHELLSCRIPTS_H__
