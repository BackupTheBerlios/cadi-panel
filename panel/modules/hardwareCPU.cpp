#include "cadi.h"
#include "hardwareCPU.h"
#include "../../common/db.h"

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
	Result *res = Cadi::db->getConnection("SELECT val1, val2, val3, val4 FROM HardwareCPUModule_processor");

	res->execSql();

	processors = pro.execPippedShellProcessList(ShellScripts::CAT, ShellScripts::CAT_CPUINFO, ShellScripts::GREP, ShellScripts::GREP_MODELNAME);

	filt = processors.filter(res->get(0, 0), Qt::CaseSensitive);

	if (filt.size() > 0){
		QStandardItem *parentItem = model->invisibleRootItem();
		QStandardItem *stdItem, *item, *itemRoot;
		QStringList::const_iterator it;
		int i = 0;
		for (i = 0, it = filt.constBegin(); it != filt.constEnd(); ++i, ++it){
			//Nivel 0: processor
			itemRoot = new QStandardItem(QIcon(res->get(1, "val1")).pixmap(32, 32), trUtf8(res->get(1, "val2").toStdString().c_str()) + QString::number(i + 1));
			parentItem->appendRow(itemRoot);

			auxList = processors.filter(res->get(2, "val1"), Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				item = new QStandardItem(aux);
				itemRoot->appendRow(item);
			}

			auxList = processors.filter(res->get(3, "val1"), Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				stdItem = new QStandardItem(trUtf8(res->get(3, "val2").toStdString().c_str()) + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter(res->get(4, "val1"), Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				stdItem = new QStandardItem(trUtf8(res->get(4, "val2").toStdString().c_str()) + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter(res->get(5, "val1"), Qt::CaseSensitive);
			if (auxList.size() > 0){
				if (auxList.at(i).startsWith(res->get(5, "val2")) == true){
					aux = auxList.at(i + 1).right(auxList.at(i + 1).length() - auxList.at(i + 1).indexOf(":") - 1).trimmed();
				} else {
					aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				}
				stdItem = new QStandardItem(trUtf8(res->get(5, "val3").toStdString().c_str()) + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter(res->get(6, "val1"), Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed();
				stdItem = new QStandardItem(trUtf8(res->get(6, "val2").toStdString().c_str()) + aux);
				item->appendRow(stdItem);
			}

			auxList = processors.filter(res->get(7, "val1"), Qt::CaseSensitive);
			if (auxList.size() > 0){
				aux = auxList.at(i).right(auxList.at(i).length() - auxList.at(i).indexOf(":") - 2).trimmed() + " MHz";
				auxLi2 = processors.filter(res->get(7, "val2"), Qt::CaseSensitive);
				if (auxLi2.size() > 0){
					aux += res->get(7, "val3") + auxLi2.at(i).right(auxLi2.at(i).length() - auxLi2.at(i).indexOf(":") - 2).trimmed();
				}
				stdItem = new QStandardItem(trUtf8(res->get(7, "val4").toStdString().c_str()) + aux);
				itemRoot->appendRow(stdItem);
			}
		}
	}

	return model;
}


