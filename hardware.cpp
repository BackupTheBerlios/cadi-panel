#include "cadi.h"
#include "shellscripts.h"
#include "process.h"

Hardware::Hardware()
{
}

QStringList Hardware::processor()
{
	QStringList processors;

	Process pro;
	processors = pro.execPipedShellProcessList(ShellScripts::SS_CAT, ShellScripts::SS_CAT_CPUINFO, ShellScripts::SS_GREP, ShellScripts::SS_GREP_CPUMODELNAME);

	return processors;
}
