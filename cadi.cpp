#include "cadi.h"
#include "ui_cadi.h"
#include "distribution.h"
#include "de.h"
#include "hardware.h"

Cadi::Cadi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadi)
{
    ui->setupUi(this);
    qDebug(Distribution::name().toAscii());
    qDebug(Distribution::version().toAscii());
    qDebug(Distribution::codename().toAscii());
    qDebug(DE::name().toAscii());
    setIconsByTheme();
    setByDistribution();
    setByDE();
    //qDebug(Hardware::processor().first().toAscii());
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

//Set the icons
void Cadi::setIconsByTheme()
{
    #if QT_VERSION >= 0x040600
        ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->softwareTab), QIcon::fromTheme("preferences-system"));
        ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->hardwareTab), QIcon::fromTheme("preferences-desktop-peripherals"));
        ui->updateButton->setIcon(QIcon::fromTheme("system-software-update"));
    #else

    #endif
}

//Set the app by the current distro
void Cadi::setByDistribution()
{
    if (Distribution::name() == "Asturix")
    {
        ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->generalTab), QIcon(":/asturix-icon"));
        ui->distroLogoButton->setIcon(QIcon(":/asturix-icon").pixmap(128, 128));
    }
    else if (Distribution::name() == "Kademar")
    {
        ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->generalTab), QIcon(":/kademar-icon"));
        ui->distroLogoButton->setIcon(QIcon(":/kademar-icon"));
    }
    else if (Distribution::name() == "Ubuntu")
    {
        ui->tabWidget->setTabIcon(ui->tabWidget->indexOf(ui->generalTab), QIcon(":/ubuntu-icon"));
        ui->distroLogoButton->setIcon(QIcon(":/ubuntu-icon"));
    }
    ui->distroNameLabel->setText("<h1>" + Distribution::name() + "</h1>" + " " + Distribution::version() + " " + Distribution::codename());
    ui->kernelLabel->setText("<b>" + trUtf8("Linux Kernel") + "</b> " + Distribution::kernel());
}

//Set the app by the current desktop enviroment
void Cadi::setByDE()
{
    ui->DELabel->setText("<b>" + DE::name() + "</b>" + " " + trUtf8("desktop enviroment"));
}
