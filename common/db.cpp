#include "db.h"
#include <QDir>
#include <QApplication>

DB::DB(){
	int i = 0;
	maxConnections = 0;
	Result *res = new Result();
	res->newDatabase("QSQLITE", "localhost", "../data/data.sqlite", i);
	if (res->isOpen() == true && res->isValid() == true){
		res->initQuery();
		res->execSql("SELECT val2 FROM db_configure WHERE val1 = 'DB_MAX_CONNECTIONS'");
		maxConnections = res->get(0, "val2").toInt();
		if (maxConnections > 0){
			vecDBC = new QVector<Result*>(maxConnections);
			if (vecDBC != NULL){
				vecDBC->replace(0, res);
				while (++i < vecDBC->size()){
					pool(i);
				}
			}
		}
		res->execSql("SELECT val2 FROM db_configure WHERE val1 = 'DB_CONNECTION_TIMEOUT'");
		timeout = res->get(0, "val2").toInt();
	}
}

DB::~DB(){
	releaseDB();
}

Result* DB::updateDBs(){
	int i = 0;
	Result * res = NULL;
	for (i = 0; i < maxConnections; ++i){
		if (vecDBC->at(i)->isExecuted() == true){
			if (vecDBC->at(i)->elapsed() > timeout){
				vecDBC->at(i)->setBlocked(true);
				vecDBC->at(i)->close();
				vecDBC->at(i)->initDb();
				vecDBC->at(i)->deleteDB();
				QSqlDatabase::removeDatabase(vecDBC->at(i)->getConnName());
				vecDBC->at(i)->newDatabase("QSQLITE", "localhost", "../data/data.sqlite", i);
			} else {
				vecDBC->at(i)->setDateTime();
			}
		} else {
			break;
		}
	}

	if (res == NULL){
		res = vecDBC->at(i);
	}

	return res;
}

Result* DB::getConnection(){
	return updateDBs();
}

Result* DB::getConnection(QString stmt){
	Result *res = NULL;

	res = getConnection();
	if (res != NULL){
		res->setStmt(stmt);
	}

	return res;
}

void DB::releaseDB(){
	for (int i = 0; i < vecDBC->size(); ++i){
		releaseDB(i);
	}
}

void DB::releaseDB(int i){
	Result *res = vecDBC->at(i);

	res->deleteDB();
	vecDBC->remove(i);
	delete res;
}

int DB::pool(int i){
	int index = -1;
	Result *res = new Result();
	res->newDatabase("QSQLITE", "localhost", "../data/data.sqlite", i);
	if (res->isOpen() == true && res->isValid() == true){
		if (i > 0 && i < maxConnections){
			vecDBC->replace(i, res);
			index = vecDBC->size() - 1;
		}
		res->initQuery();
		res->setExecuted(false);
		res->setBlocked(false);
	}

	return index;
}

Result::Result(){
	ql = NULL;
	ptrDb = NULL;
	qsq = NULL;
}

int Result::size(){
	return ql->size();
}

QString Result::get(int x, int y){
	dateTime = QDateTime::currentDateTime();
	return ql->at(x).value(y).toString();
}

QString Result::get(int x, QString columnName){
	dateTime = QDateTime::currentDateTime();
	return ql->at(x).value(columnName).toString();
}

void Result::execSql(QString stmt){
	if (ptrDb != NULL && ptrDb->isOpen() == true && ptrDb->isValid() == true){
		this->stmt = stmt;
		execSql();
	}
}

void Result::execSql(){
	while(blocked == true){
		QBasicTimer t;
		t.start(10, NULL);
		t.stop();
	}
	executed = false;
	if (ql == NULL){
		ql = new QList<QSqlRecord>();
	}
	if (size() > 0){
		while(!ql->isEmpty()){
			ql->removeFirst();
		}
	}
	if (qsq->size() > 0){
		qsq->clear();
	}
	if (ptrDb != NULL && ptrDb->isOpen() == true && ptrDb->isValid() == true){
		qsq->exec(stmt);
		while(qsq->next()){
			ql->append(qsq->record());
		}
		executed = true;
		dateTime = QDateTime::currentDateTime();
	}
}

bool Result::isOpen(){
	bool open = false;

	if (ptrDb != NULL && ptrDb->isOpen() == true){
		open = true;
	}

	return open;
}

bool Result::isValid(){
	bool valid = false;

	if (ptrDb != NULL && ptrDb->isValid() == true){
		valid = true;
	}

	return valid;
}

void Result::close(){
	db.close();
}

void Result::initDb(){
	db = QSqlDatabase();
}

void Result::setStmt(QString stmt){
	this->stmt = stmt;
}

void Result::newDatabase(QString type, QString host, QString dbName, int numConn){
	db = QSqlDatabase::addDatabase(type, "Conn" + QString::number(numConn));
	ptrDb = &db;
	ptrDb->setHostName(host);
	ptrDb->setDatabaseName(dbName);
	ptrDb->open();
	connName = ptrDb->connectionName();
	initQuery();
	setExecuted(false);
	setBlocked(false);
}

void Result::initQuery(){
	if (qsq != NULL){
		qsq->clear();
		delete qsq;
	}
	qsq = new QSqlQuery(db);
}

void Result::setConnName(QString connName){
	this->connName = connName;
}

QString Result::getConnName(){
	return connName;
}

QSqlDatabase *Result::getDB(){
	return ptrDb;
}

bool Result::isExecuted(){
	return executed;
}

void Result::setExecuted(bool executed){
	this->executed = executed;
}

bool Result::isBlocked(){
	return blocked;
}

void Result::setBlocked(bool blocked){
	this->blocked = blocked;
}

void Result::deleteDB(){

	if (ql != NULL){
		QSqlRecord rec;
		for (int i = 0; i < ql->size(); ++i){
			rec = ql->at(i);
			rec.clear();
			ql->removeAt(i);
		}
		delete ql;
		ql = NULL;
	}
	if (qsq != NULL){
		qsq->clear();
		qsq->finish();
		delete qsq;
		qsq = NULL;
	}
	if (db.isOpen()){
		db.close();
	}
	db.removeDatabase(connName);
	ptrDb = NULL;
}

int Result::elapsed(){
	int secs = 0;

	secs = dateTime.secsTo(QDateTime::currentDateTime());

	return secs;
}

void Result::setDateTime(){
	dateTime = QDateTime::currentDateTime();
}
