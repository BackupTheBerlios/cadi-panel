#ifndef __DB_H__
#define __DB_H__

#include <QtSql>

#define DATABASE_MAX_CONN 50


class DB {
private:
	QVector<QSqlDatabase*> *vecDBC;
	int pool();
	QSqlDatabase *db;
public:
	DB();
	~DB();
	QSqlDatabase* getConnection();
	QList<QSqlRecord> prueba();
	QList<QSqlRecord> execSql(QString stmt);
	void releaseDB();
};

#endif // DB_H
