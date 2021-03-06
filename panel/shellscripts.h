#ifndef __SHELLSCRIPTS_H__
#define __SHELLSCRIPTS_H__

#include <QObject>
#include <QString>

//! Returns shell scripts commands ready to be executed.
/*!
  This class is able to build a \c QString containing a shell command.
  The commands are read from a \c xml file defined in its \c ficXml \c private member. For now, the file is shellscripts.xml, located in \c data folder.
  Provides functions to get one single commad or two pipped shell commands.
  Declares the \c xml node names in <tt>static QString</tt> member variables.
*/
class ShellScripts{
public:

	/** @defgroup staticNodeNames Static variables containing command and param ids.
	 *  This are <tt>public static Qstring</tt> which holds the node names which contains the ids definning commands: name and arguments (if needed).
	 *  @{
	 */
	static QString SS_NO_PARAM;									/*!< Use it to get a command with no arguments */
	//Node names
	static QString LSB_RELEASE;									/*!< \c lsb_release shell command */
	static QString LSB_RELEASE_VERSION;							/*!< <tt>-s -r</tt> argument from \c lsb_release shell command */
	static QString LSB_RELEASE_CODENAME;						/*!< <tt>-s -c</tt> argument from \c lsb_release shell command */
	static QString GREP;										/*!< \c grep shell command */
	static QString GREP_MODELNAME;								/*!< <tt>'model name'</tt> argument from \c grep shell command */
	static QString GREP_MEMTOTAL;								/*!< <tt>'MemTotal'</tt> argument from \c grep shell command */
	static QString GREP_MEMFREE;								/*!< <tt>'MemFree'</tt> argument from \c grep shell command */
	static QString GREP_SWAPTOTAL;								/*!< <tt>'SwapTotal'</tt> argument from \c grep shell command */
	static QString GREP_SWAPFREE;								/*!< <tt>'SwapFree'</tt> argument from \c grep shell command */
	static QString CAT;											/*!< <tt>cat</tt> shell command */
	static QString CAT_CPUINFO;									/*!< <tt>/proc/cpuinfo</tt> argument from \c cat shell command */
	static QString CAT_MEMINFO;									/*!< <tt>/proc/meminfo</tt> argument from \c cat shell command */
	static QString PSTREE;										/*!< <tt>pstree</tt> shell command */
	static QString PSTREE_UTF8;									/*!< <tt>-U</tt> argument from \c pstree shell command */
	static QString UNAME;										/*!< <tt>uname</tt> shell command */
	static QString UNAME_KERNELVERSION;							/*!< <tt>-rm</tt> argument from \c uname shell command */
	static QString KILLALL;										/*!< <tt>killall</tt> shell command */
	static QString FREE;										/*!< <tt>free</tt> shell command */
	static QString FREE_MEGALOWTOTAL;							/*!< <tt>-mlt</tt> arguments from \c free shell command */
	/** @} */ //End of staticNodeNames doxygen group

	ShellScripts();

	//! Gets a shell command.
	/*!	Gets a QString representing a shell command identified in the database by \c idCommand and \c idParam.
		@param idCommand The command id.
		@param idParam The command arguments id. The default vaule is <tt>ShellScripts::SS_NO_PARAM</tt>.
		@returns A \c QString representing the shell command.
	*/
	QString getCommand(QString idCommand, QString idParam);

	//! Gets a \c QString representing two pipped shell commands.
	/*!
		Gets a \c QString representing two pipped shell commands. The pipe is in the form: <tt>idCommand1 idParam1 | idCommand2 idParam2</tt>.
		@param idCommand1 The command id of the first command.
		@param idCommand2 The command id of the second command.
		@param idParam1 The command arguments id for the first command. The default vaule is <tt>ShellScripts::SS_NO_PARAM</tt>.
		@param idParam2 The command arguments id for the second command. The default vaule is <tt>ShellScripts::SS_NO_PARAM</tt>.
		@returns A \c QString representing the shell command.
	*/
	QString getPippedCommand(QString idCommand1, QString idCommand2, QString idParam1, QString idParam2);

};


#endif // __SHELLSCRIPTS_H__
