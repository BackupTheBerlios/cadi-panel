#include "cadi.h"

DB *Cadi::db = new DB();

Cadi::Cadi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadi)
{
	ui->setupUi(this);
    loadModules();
    loadModule(categoriesModule->categoriesWidget);
    setConnections();
}

Cadi::~Cadi()
{
	Cadi::db->releaseDB();
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

//Set the connections between objects
void Cadi::setConnections()
{
    connect(ui->generalAction, SIGNAL(triggered()), this, SLOT(changeView()));
    connect(ui->backAction, SIGNAL(triggered()), this, SLOT(changeView()));
    connect(categoriesModule->softwareWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(loadModuleByListItem(QListWidgetItem*)));
    connect(categoriesModule->hardwareWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(loadModuleByListItem(QListWidgetItem*)));
}

void Cadi::loadModules()
{
    generalModule = new GeneralModule;
    categoriesModule = new CategoriesModule;
    updateModule = new UpdateModule;
    hardwareCPUModule = new HardwareCPUModule;
    hardwareMEMModule = new HardwareMEMModule;
}

void Cadi::loadModule(QWidget *module)
{
    if (ui->stackedWidget->currentWidget() != NULL)
    {
        ui->stackedWidget->removeWidget(ui->stackedWidget->currentWidget());
    }
    ui->stackedWidget->addWidget(module);
    if (module->objectName().contains("generalWidget") or module->objectName().contains("categoriesWidget"))
    {
        ui->backAction->setDisabled(true);
    }
    else
    {
        ui->backAction->setEnabled(true);
    }
}

void Cadi::loadModuleByListItem(QListWidgetItem *moduleItem)
{
    if (moduleItem->whatsThis() == "update")
    {
        loadModule(updateModule);
    }
    else if (moduleItem->whatsThis() == "CPU"){
        loadModule(hardwareCPUModule);
    }
    else if (moduleItem->whatsThis() == "memory"){
        loadModule(hardwareMEMModule);
    }
}

void Cadi::changeView()
{
    /*for (int i=0; i < ui->centralWidget->children().count(); i++)
    {
        ui->centralWidget->children().at(i)->deleteLater();
    }*/
    if (ui->generalAction->isChecked() == true)
    {
        loadModule(generalModule->generalWidget);
        /*generalModule->setupUi(ui->centralWidget);
        ui->centralWidget->layout()->deleteLater();
        ui->centralWidget->layout()->addWidget(generalModule->generalWidget);*/
    }
    else
    {
        loadModule(categoriesModule->categoriesWidget);
        /*categoriesModule->setupUi(ui->centralWidget);
        ui->centralWidget->layout()->deleteLater();
        ui->centralWidget->layout()->addWidget(categoriesModule->scrollArea);*/
    }
}

