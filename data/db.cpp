#include "db.h"
#include <QDir>
#include <QApplication>

DB::DB(){
	vecDBC = new QVector<QSqlDatabase*>();
	this->db = getConnection();
}

DB::~DB(){
	for (int i = 0; i < this->vecDBC->size(); ++i){
		if (this->vecDBC->at(i)->isOpen() == true){
			this->vecDBC->at(i)->close();
			*(this->vecDBC->at(i)) = QSqlDatabase();
		}
	}
}

QList<QSqlRecord> DB::prueba(){
	QList<QSqlRecord>ql;

	if (this->db != NULL && this->db->isOpen() == true && this->db->isValid() == true){
		QSqlQuery qsq(*(this->db));
		qsq.exec("SELECT * FROM Prueba");
		while(qsq.next()){
			ql.append(qsq.record());
		}
		qsq.finish();
	}

	return ql;
}

QList<QSqlRecord> DB::execSql(QString stmt){
	QList<QSqlRecord>ql;

	if (this->db != NULL && this->db->isOpen() == true && this->db->isValid() == true){
		QSqlQuery qsq(*(this->db));
		qsq.exec(stmt);
		while(qsq.next()){
			ql.append(qsq.record());
		}
		qsq.finish();
	}

	return ql;
}

void DB::releaseDB(){
	for (int i = 0; i < this->vecDBC->size(); ++i){
		if (this->vecDBC->at(i)->isOpen() == true){
			this->vecDBC->at(i)->close();
			*(this->vecDBC->at(i)) = QSqlDatabase();
		}
	}
}


int DB::pool(){
	int index = -1;
	this->db = new QSqlDatabase();
	*(this->db) = QSqlDatabase::addDatabase("QSQLITE");
	this->db->setHostName("localhost");
	this->db->setDatabaseName("data/data.sqlite");
	this->db->open();
	if (this->db->isOpen() == true && this->db->isValid() == true){
		if (this->vecDBC->size() < DATABASE_MAX_CONN){
			this->vecDBC->append(this->db);
			index = this->vecDBC->size() - 1;
		}
	}

	return index;
}

QSqlDatabase* DB::getConnection(){
	int index = -1;

	this->db = NULL;
	index = pool();

	if (index > -1){
		this->db = this->vecDBC->at(index);
	}

	return db;
}
