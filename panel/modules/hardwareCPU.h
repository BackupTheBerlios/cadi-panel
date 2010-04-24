#ifndef __HARDWARECPU_H__
#define __HARDWARECPU_H__

#include <QWidget>

#include "ui_hardwareCPU.h"
#include <QStandardItemModel>
#include "process.h"

namespace Ui {
	class HardwareCPU;
}

class HardwareCPUModule : public QWidget, public Ui::HardwareCPUModule {
	Q_OBJECT
public:
	HardwareCPUModule(QWidget *parent = 0);

public slots:
	QStandardItemModel* processor();
protected:
	void changeEvent(QEvent *e);
};

#endif // HARDWARECPU_H
