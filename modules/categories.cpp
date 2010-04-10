#include "categories.h"

CategoriesModule::CategoriesModule(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void CategoriesModule::changeEvent(QEvent *e)
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
