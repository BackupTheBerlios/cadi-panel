#include "cadi.h"
#include "shellscripts.h"
#include "process.h"

Distribution::Distribution()
{
}

//Return the distribution in use
QString Distribution::name()
{
    QFile *lsb_release = new QFile("/etc/lsb-release");
    lsb_release->open(QIODevice::ReadOnly);
    QString *lsb_releaseContent = new QString(lsb_release->readAll());
    if (lsb_releaseContent->contains("Asturix"))
    {
        return "Asturix";
    }
    else if (lsb_releaseContent->contains("kademar"))
    {
        return "kademar";
    }
    else if (lsb_releaseContent->contains("Ubuntu"))
    {
        return "Ubuntu";
    }
    else
    {
        return "other";
    }
    lsb_release->close();
}

//Return the version of the distribution in use
QString Distribution::version()
{
	return pro.execShellProcess(ShellScripts::LSB_RELEASE, ShellScripts::LSB_RELEASE_VERSION);
}

//Return the codename of the distribution in use
QString Distribution::codename()
{
	return pro.execShellProcess(ShellScripts::LSB_RELEASE, ShellScripts::LSB_RELEASE_CODENAME);
}

//Return the kernel version of the distribution in use
QString Distribution::kernel()
{
	return pro.execShellProcess(ShellScripts::UNAME, ShellScripts::UNAME_KERNELVERSION);
}
