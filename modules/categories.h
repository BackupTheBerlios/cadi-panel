#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <QWidget>

#include "ui_categories.h"

namespace Ui {
    class CategoriesModule;
}

class CategoriesModule : public QWidget, public Ui::CategoriesModule {
    Q_OBJECT
public:
    CategoriesModule(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);
};

#endif // CATEGORIES_H
