#ifndef CADI_H
#define CADI_H

#include <QMainWindow>
#include <QIcon>
#include <QFile>
#include <QProcessEnvironment>
//#include <KDE/KCModuleLoader>
//#include <gconf/2/gconf/gconf.h>

namespace Ui {
    class Cadi;
}

class Cadi : public QMainWindow {
    Q_OBJECT
public:
    Cadi(QWidget *parent = 0);
    ~Cadi();
    QString distribution();
    QString desktopEnviroment();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Cadi *ui;

public slots:
    void setIconsByTheme();
    void setByDistribution();
    void setByDE();
};

#endif // CADI_H
