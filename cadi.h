#ifndef CADI_H
#define CADI_H

#include <QMainWindow>
#include <QIcon>
#include <QFile>
#if QT_VERSION >= 0x040600
    #include <QProcessEnvironment>
#else
    #include <QProcess>
#endif
//#include <KDE/KCModuleLoader>
//#include <gconf/2/gconf/gconf.h>
#include "build/ui_cadi.h"
#include "distribution.h"
#include "de.h"
#include "process.h"
#include "shellscripts.h"
#include "modules/general.h"
#include "modules/categories.h"
#include "modules/update.h"
#include "modules/hardwareCPU.h"
#include "modules/hardwareMEM.h"
#include "data/db.h"

namespace Ui {
    class Cadi;
}

class Cadi : public QMainWindow {
    Q_OBJECT
public:
    Cadi(QWidget *parent = 0);
    ~Cadi();
    Ui::Cadi *ui;
    GeneralModule *generalModule;
    CategoriesModule *categoriesModule;
    UpdateModule *updateModule;
	HardwareCPUModule *hardwareCPUModule;
	HardwareMEMModule *hardwareMEMModule;
	static DB *db;


public slots:
    void setConnections();
    void loadModules();
    void loadModule(QWidget *module);
    void loadModuleByListItem(QListWidgetItem *moduleItem);
    void changeView();

protected:
    void changeEvent(QEvent *e);
};

#endif // CADI_H
