#ifndef __HARDWAREMEM_H__
#define __HARDWAREMEM_H__

#include <QWidget>

#include "ui_hardwareMEM.h"
#include <QStandardItemModel>
#include "process.h"

namespace Ui {
	class HardwareMEM;
}

class HardwareMEMModule : public QWidget, public Ui::HardwareMEMModule {
	Q_OBJECT
private:
	static QString comboMegabytes;
	static QString comboKilobytes;
	static QString comboGigabytes;
	static QString comboBytes;

public:
	HardwareMEMModule(QWidget *parent = 0);

public slots:
	QStandardItemModel* memory();
	QStringList *memoryComboList();

protected:
	void changeEvent(QEvent *e);
};



#endif // HARDWAREMEM_H
