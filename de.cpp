#include "cadi.h"

DE::DE()
{
}

//Return the desktop enviroment in use
QString DE::name()
{
    if (Process::isRunning(QString("ksmserver")))
    {
        return "KDE";
    }
    else if (Process::isRunning(QString("gnome-panel")))
    {
        return "GNOME";
    }
    else if (Process::isRunning(QString("lxpanel")))
    {
        return "LXDE";
    }
    else if (Process::isRunning(QString("xfce-mcs-manage")))
    {
        return "XFCE";
    }
    else if (Process::isRunning(QString("enlightenment")))
    {
        return "Enlightenment";
    }
    else if (Process::isRunning(QString("fluxbox")))
    {
        return "Fluxbox";
    }
    else
    {
        return "Other";
    }
}
