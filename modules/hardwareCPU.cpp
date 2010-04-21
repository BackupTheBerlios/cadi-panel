#include "cadi.h"
#include "hardwareCPU.h"

HardwareCPUModule::HardwareCPUModule(QWidget *parent) :
	QWidget(parent)
{
	setupUi(this);
	cpuTreeView->setHeaderHidden(true);
	cpuTreeView->setModel(processor());
}

void HardwareCPUModule::changeEvent(QEvent *e)
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

QStandardItemModel* HardwareCPUModule::processor()
{
	QStandardItemModel *model = new QStandardItemModel();
	QStringList processors;
	QStringList filt, auxList, auxLi2;
	QString aux;
	Process pro;

	processors = pro.execPippedShellProcessList(ShellScripts::CAT, ShellScripts::CAT_CPUINFO, ShellScripts::GREP, ShellScripts::GREP_MODELNAME);

	filt = processors.filter("processor", Qt::CaseSensitive);

	if (filt.size() > 0){
		QStandardItem *parentItem = model->invisibleRootItem();
		QStandardItem *stdItem, *item, *itemRoot;
		QStringList::const_iterator it;
		int i = 0;
		for (i = 0, it = filt.constBegin(); it != filt.constEnd(); ++i, ++it){
			//Nivel 0: procesador
			itemRoot = new QStandardItem(QIcon(":/icons/48x48/devices/cpu.png").pixmap(32, 32), trUtf8("Processor ") + QString::number(i));
			parentItem->appendRow(itemRoot);

			auxList = processors.filter("model name", Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				item = new QStandardItem(aux);
				itemRoot->appendRow(item);
			}

			auxList = processors.filter("vendor_id", Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				stdItem = new QStandardItem(trUtf8("Vendor: ") + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter("cpu family", Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				stdItem = new QStandardItem(trUtf8("Family: ") + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter("model", Qt::CaseSensitive);
			if (auxList.size() > 0){
				if (auxList.at(i).startsWith("model name") == true){
					aux = auxList.at(i + 1).right(auxList.at(i + 1).length() - auxList.at(i + 1).indexOf(":") - 1).trimmed();
				} else {
					aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				}
				stdItem = new QStandardItem(trUtf8("Model: ") + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter("stepping", Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				stdItem = new QStandardItem(trUtf8("Revision: ") + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter("cpu MHz", Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed() + " MHz";
				auxLi2 = processors.filter("bogomips", Qt::CaseSensitive);
				if (auxLi2.size() > 0){
					aux += " - Bogomips: " + auxLi2.at(i).right(auxLi2.at(i).length() - auxLi2.at(i).indexOf(":") - 2).trimmed();
				}
				stdItem = new QStandardItem(trUtf8("Frequency: ") + aux);
				itemRoot->appendRow(stdItem);
			}
		}
	}

	return model;
}


