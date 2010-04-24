#include "cadi.h"
#include "general.h"

GeneralModule::GeneralModule(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setByDistribution();
    setByDE();
}

void GeneralModule::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

//Set the app by the current distro
void GeneralModule::setByDistribution()
{
        Distribution dist;
        distroLogoButton->setIcon(QIcon(":/" + dist.name().toLower() + "-icon").pixmap(128, 128));
        distroNameLabel->setText("<h1>" + dist.name() + "</h1>" + " " + dist.version() + " " + dist.codename());
        kernelLabel->setText("<b>" + trUtf8("Linux Kernel") + "</b> " + dist.kernel());
}

//Set the app by the current desktop enviroment
void GeneralModule::setByDE()
{
        DELabel->setText("<b>" + DE::name() + "</b>" + " " + trUtf8("Desktop Environment"));
}
