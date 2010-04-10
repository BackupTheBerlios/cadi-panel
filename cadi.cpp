#include "cadi.h"

Cadi::Cadi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadi)
{
    Process pro;
    ui->setupUi(this);
    setConnections();
    generalModule = new Ui::GeneralModule;
    categoriesModule = new Ui::CategoriesModule;
    categoriesModule->setupUi(ui->centralWidget);
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

//Set the app by the current distro
void Cadi::setByDistribution()
{
	Distribution dist;

	generalModule->distroLogoButton->setIcon(QIcon(":/" + dist.name().toLower() + "-icon").pixmap(128, 128));
	generalModule->distroNameLabel->setText("<h1>" + dist.name() + "</h1>" + " " + dist.version() + " " + dist.codename());
	generalModule->kernelLabel->setText("<b>" + trUtf8("Linux Kernel") + "</b> " + dist.kernel());
}

//Set the app by the current desktop enviroment
void Cadi::setByDE()
{
	generalModule->DELabel->setText("<b>" + DE::name() + "</b>" + " " + trUtf8("Desktop Environment"));
}

//Set the connections between objects
void Cadi::setConnections()
{
	connect(ui->generalAction, SIGNAL(triggered()), this, SLOT(changeView()));
}

void Cadi::changeView()
{
    for (int i=0; i < ui->centralWidget->children().count(); i++)
    {
        ui->centralWidget->children().at(i)->deleteLater();
    }
    if (ui->generalAction->isChecked() == true)
    {
        generalModule->setupUi(ui->centralWidget);
        ui->centralWidget->layout()->deleteLater();
        ui->centralWidget->layout()->addWidget(generalModule->generalWidget);
        setByDistribution();
        setByDE();
    }
    else
    {
        categoriesModule->setupUi(ui->centralWidget);
        ui->centralWidget->layout()->deleteLater();
        ui->centralWidget->layout()->addWidget(categoriesModule->scrollArea);
    }
}
