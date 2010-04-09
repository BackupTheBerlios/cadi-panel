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

	processors = pro.execPippedShellProcessList(ShellScripts::CAT, ShellScripts::CAT_CPUINFO, ShellScripts::GREP, ShellScripts::GREP_MODELNAME);

	return processors;
}

QStringList Hardware::memory(){
	QString result;
	QStringList mem, aux;
	Process pro;

	//TOTAL MEMORY
	result = pro.execPippedShellProcess(ShellScripts::CAT, ShellScripts::CAT_MEMINFO, ShellScripts::GREP, ShellScripts::GREP_MEMTOTAL);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	//FREE MEMORY
	result = pro.execPippedShellProcess(ShellScripts::CAT, ShellScripts::CAT_MEMINFO, ShellScripts::GREP, ShellScripts::GREP_MEMFREE);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	//TOTAL SWAP
	result = pro.execPippedShellProcess(ShellScripts::CAT, ShellScripts::CAT_MEMINFO, ShellScripts::GREP, ShellScripts::GREP_SWAPTOTAL);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	//FREE SWAP
	result = pro.execPippedShellProcess(ShellScripts::CAT, ShellScripts::CAT_MEMINFO, ShellScripts::GREP, ShellScripts::GREP_SWAPFREE);
	aux = result.split(" ", QString::SkipEmptyParts);
	mem.append(aux.at(1) + aux.at(2));

	return mem;
}
