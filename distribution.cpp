#include "distribution.h"
#include "cadi.h"

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
    QProcess *distroVersion = new QProcess();
    distroVersion->setProcessChannelMode(QProcess::MergedChannels);
    distroVersion->start("lsb_release -s -r");
    if (distroVersion->waitForFinished())
    {
        QString distroVersionString = QString(distroVersion->readAll());
        return distroVersionString.trimmed();
    }
    distroVersion->close();
}

//Return the codename of the distribution in use
QString Distribution::codename()
{
    QProcess *distroCodename = new QProcess();
    distroCodename->setProcessChannelMode(QProcess::MergedChannels);
    distroCodename->start("lsb_release -s -c");
    if (distroCodename->waitForFinished())
    {
        QString distroCodenameString = QString(distroCodename->readAll());
        return distroCodenameString.trimmed();
    }
    distroCodename->close();
}

//Return the kernel version of the distribution in use
QString Distribution::kernel()
{
    QProcess *distroKernel = new QProcess();
    distroKernel->setProcessChannelMode(QProcess::MergedChannels);
    distroKernel->start("uname -r -m");
    if (distroKernel->waitForFinished())
    {
        QString distroKernelString = QString(distroKernel->readAll());
        return distroKernelString.trimmed();
    }
    distroKernel->close();
}
