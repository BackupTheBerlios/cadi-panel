#include "cadi.h"

DE::DE()
{
}

//Return the desktop enviroment in use
QString DE::name()
{
	Process pro;

	if (pro.isRunning(QString("ksmserver")))
    {
        return "KDE";
    }
	else if (pro.isRunning(QString("gnome-panel")))
    {
        return "GNOME";
    }
	else if (pro.isRunning(QString("lxpanel")))
    {
        return "LXDE";
    }
	else if (pro.isRunning(QString("xfce-mcs-manage")))
    {
        return "XFCE";
    }
	else if (pro.isRunning(QString("enlightenment")))
    {
        return "Enlightenment";
    }
	else if (pro.isRunning(QString("fluxbox")))
    {
        return "Fluxbox";
    }
    else
    {
        return "Other";
    }
}
