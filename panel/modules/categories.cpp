#include "categories.h"

CategoriesModule::CategoriesModule(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    QStyleOption style;
    qDebug(style.palette.color(QPalette::Window).toRgb().name().toAscii());
    categoriesWidget->setStyleSheet(QString("QListWidget {background: " + style.palette.color(QPalette::Window).toRgb().name() + ";}"));
    categoriesWidget->update();
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
