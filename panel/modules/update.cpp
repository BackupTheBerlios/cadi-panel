#include "update.h"
#include "ui_update.h"

UpdateModule::UpdateModule(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void UpdateModule::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}
