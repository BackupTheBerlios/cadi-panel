#include "de.h"
#include "cadi.h"

DE::DE()
{
}

//Return the desktop enviroment in use
QString DE::name()
{
    #if QT_VERSION >= 0x040600
        if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("kde"))
        {
            return "KDE";
        }
        else if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("gnome"))
        {
            return "GNOME";
        }
        else if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("lxde"))
        {
            return "LXDE";
        }
        else if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("xfce"))
        {
            return "XFCE";
        }
        else
        {
            return "Other";
        }
    #else
        if (QProcess::systemEnvironment().contains("DESKTOP_SESSION=kde"))
        {
            return "KDE";
        }
        else if (QProcess::systemEnvironment().contains("DESKTOP_SESSION=gnome"))
        {
            return "GNOME";
        }
        else if (QProcess::systemEnvironment().contains("DESKTOP_SESSION=lxde"))
        {
            return "LXDE";
        }
        else if (QProcess::systemEnvironment().contains("DESKTOP_SESSION=xfce"))
        {
            return "XFCE";
        }
        else
        {
            return "Other";
        }
    #endif
}
