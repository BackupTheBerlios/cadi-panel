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
#include "hardware.h"
#include "shellscripts.h"
#include "build/ui_general.h"
#include "build/ui_categories.h"

namespace Ui {
    class Cadi;
}

class Cadi : public QMainWindow {
    Q_OBJECT
public:
    Cadi(QWidget *parent = 0);
    ~Cadi();
    Ui::Cadi *ui;
    Ui::GeneralModule *generalModule;
    Ui::CategoriesModule *categoriesModule;

public slots:
    void setByDistribution();
    void setByDE();
    void setConnections();
    void changeView();

protected:
    void changeEvent(QEvent *e);
};

#endif // CADI_H
