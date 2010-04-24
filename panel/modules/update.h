#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>

#include "ui_update.h"

namespace Ui {
    class UpdateModule;
}

class UpdateModule : public QDialog, public Ui::UpdateModule {
    Q_OBJECT
public:
    UpdateModule(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);
};

#endif // UPDATE_H
