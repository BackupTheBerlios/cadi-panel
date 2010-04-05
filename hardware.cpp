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

        processors = pro.execPippedShellProcessList(ShellScripts::SS_CAT, ShellScripts::SS_CAT_CPUINFO, ShellScripts::SS_GREP, ShellScripts::SS_GREP_CPUMODELNAME);

	return processors;
}

QStringList Hardware::memory(){
	QString result;
	QStringList mem, aux;
	Process pro;

	//TOTAL MEMORY
        result = pro.execPippedShellProcess(ShellScripts::SS_CAT, ShellScripts::SS_CAT_MEMINFO, ShellScripts::SS_GREP, ShellScripts::SS_GREP_MEMTOTAL);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	//FREE MEMORY
        result = pro.execPippedShellProcess(ShellScripts::SS_CAT, ShellScripts::SS_CAT_MEMINFO, ShellScripts::SS_GREP, ShellScripts::SS_GREP_MEMFREE);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	//TOTAL SWAP
        result = pro.execPippedShellProcess(ShellScripts::SS_CAT, ShellScripts::SS_CAT_MEMINFO, ShellScripts::SS_GREP, ShellScripts::SS_GREP_SWAPTOTAL);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	//FREE SWAP
        result = pro.execPippedShellProcess(ShellScripts::SS_CAT, ShellScripts::SS_CAT_MEMINFO, ShellScripts::SS_GREP, ShellScripts::SS_GREP_SWAPFREE);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	return mem;
}
