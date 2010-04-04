#include "cadi.h"

Process::Process()
{
}

bool Process::isRunning(QString processName)
{
    QProcess *pstree = new QProcess();
    pstree->setProcessChannelMode(QProcess::MergedChannels);
    pstree->start("pstree -U");
    if (pstree->waitForFinished())
    {
        QString processes = QString(pstree->readAll());
        pstree->close();
        if (processes.contains(processName) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
