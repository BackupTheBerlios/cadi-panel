#include "cadi.h"
#include "ui_cadi.h"

Cadi::Cadi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadi)
{
    ui->setupUi(this);
    qDebug(distribution().toAscii());
    qDebug(desktopEnviroment().toAscii());
    setIconsByTheme();
}

Cadi::~Cadi()
{
    delete ui;
}

void Cadi::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//Return the distribution in use
QString Cadi::distribution()
{
    QFile *lsb_release = new QFile("/etc/lsb_release");
    lsb_release->open(QIODevice::ReadOnly);
    if (lsb_release->readAll().contains("Asturix"))
    {
        return "Asturix";
    }
    else if (lsb_release->readAll().contains("Kademar"))
    {
        return "Kademar";
    }
    else
    {
        return "other";
    }
    lsb_release->close();
}

//Return the desktop enviroment in use
QString Cadi::desktopEnviroment()
{
    if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("kde"))
    {
        return "kde";
    }
    else if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("gnome"))
    {
        return "gnome";
    }
    else if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("lxde"))
    {
        return "lxde";
    }
    else if (QProcessEnvironment::systemEnvironment().value("DESKTOP_SESSION", "").contains("xfce"))
    {
        return "xfce";
    }
    else
    {
        return "other";
    }
}

//Set the icons
void Cadi::setIconsByTheme()
{
    if (distribution() == "Asturix")
    {
        ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->softwareTab), QIcon(":/distributions/asturix.png"));
    }
    else if (distribution() == "Kademar")
    {
        ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->softwareTab), QIcon(":/distributions/kademar.png"));
    }
    ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->hardwareTab), QIcon::fromTheme("preferences-desktop-peripherals"));
    ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->systemTab), QIcon::fromTheme("preferences-system"));
}
