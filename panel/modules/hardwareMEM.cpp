#include "hardwareMEM.h"

QString HardwareMEMModule::comboMegabytes = "Megabytes";
QString HardwareMEMModule::comboKilobytes = "Kilobytes";
QString HardwareMEMModule::comboGigabytes = "Gigabytes";
QString HardwareMEMModule::comboBytes = "Bytes";


HardwareMEMModule::HardwareMEMModule(QWidget *parent) :
	QWidget(parent)
{
	setupUi(this);
	hardwareMEMComboBox->addItems(*(memoryComboList()));
	hardwareMEMTreeView->setModel(memory());
}

void HardwareMEMModule::changeEvent(QEvent *e)
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

QStandardItemModel* HardwareMEMModule::memory(){
	QString result;
	QStringList mem, aux;
	QStandardItemModel *model = new QStandardItemModel(7, 7);
	QStandardItem *item = NULL;
	Process pro;

	mem = pro.execShellProcessList(ShellScripts::FREE, ShellScripts::FREE_MEGALOWTOTAL);

	//Header
	aux = mem.at(0).split(" ", QString::SkipEmptyParts);
	item = new QStandardItem("");
	model->setHorizontalHeaderItem(0, item);
	for (int i = 0; i < 6; ++i){
		item = new QStandardItem(aux.at(i));
		model->setHorizontalHeaderItem(i + 1, item);
	}

	for (int i = 1; i < mem.size(); ++i){
		aux = mem.at(i).split(" ", QString::SkipEmptyParts);
		for (int j = 0; j < aux.size(); ++j){
			if (aux.at(j).startsWith("-/+")){
				QString a = aux.at(j) + aux.at(j + 1);
				item = new QStandardItem(a);
				model->setItem(i - 1, j, item);
				++j;
			} else {
				item = new QStandardItem(aux.at(j));
				model->setItem(i - 1, j, item);
			}
		}
	}
	return model;
}

QStringList *HardwareMEMModule::memoryComboList(){
	QStringList *units = new QStringList();

	units->append(HardwareMEMModule::comboMegabytes);
	units->append(HardwareMEMModule::comboKilobytes);
	units->append(HardwareMEMModule::comboGigabytes);
	units->append(HardwareMEMModule::comboBytes);

	return units;
}


