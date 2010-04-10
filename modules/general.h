#ifndef GENERAL_H
#define GENERAL_H

#include <QWidget>

#include "ui_general.h"

namespace Ui {
    class GeneralModule;
}

class GeneralModule : public QWidget, public Ui::GeneralModule {
    Q_OBJECT
public:
    GeneralModule(QWidget *parent = 0);

public slots:
    void setByDistribution();
    void setByDE();

protected:
    void changeEvent(QEvent *e);
};

#endif // GENERAL_H
