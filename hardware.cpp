#include "cadi.h"

Hardware::Hardware()
{
}

//TOFIX: Crash when executing this function
QStringList Hardware::processor()
{
    QStringList *processors = new QStringList();

    QProcess *cpuInfo = new QProcess();
    cpuInfo->setProcessChannelMode(QProcess::MergedChannels);
    cpuInfo->start("cat /proc/cpuinfo | grep 'model name'");
    //system("cat /proc/cpuinfo | grep 'model name'");
    if (cpuInfo->waitForFinished())
    {
        QString *cpuInfoString = new QString(cpuInfo->readAll());
        qDebug(cpuInfoString->toAscii());
        for (int i; i < cpuInfoString->count("\n"); i++)
        {
            processors->append(cpuInfo->readLine().right(cpuInfo->readLine().length() - 13));
        }
    }
    cpuInfo->close();

    return *processors;
}
