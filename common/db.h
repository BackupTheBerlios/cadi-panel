#ifndef __DB_H__
#define __DB_H__

#include <QtSql>

#define DATABASE_MAX_CONN 50

//! Manages a database connection.
/*!
  The class manages a database connection: creation and deletion, queries, statements, results and timeouts.
  The database is SQLite located at \c data directory.
*/
class Result {
private:
	//! \c db holds the database connection; \c ptrDb is a convenience pointer to that connection.
	QSqlDatabase *ptrDb, db;
	//! List of \c QSqlRecord containing the query results.
	QList<QSqlRecord> *ql;
	//! Holds the statement to query the database
	QString stmt;
	//! The \c QSqlQuery object related to the database
	QSqlQuery *qsq;
	//! Holds the database connection name
	QString connName;
	//! Indicates the query state: \c true if the query has been executed; \false otherwise
	bool executed;
	//! Holds the connection state: \c true if the connection is being renewed due to timeout; \c false otherwise.
	bool blocked;
	//! Holds the date and time when a query was executed.
	QDateTime dateTime;
public:
	//! Initializes the pointers: \c ql, \c ptrDb and \c qsq
	Result();
	//! Gets a new database connection.
	/*!	Gets a new database connection of type \c type, on \host with a name \db + \numConn
		@param type The name of the database driver needed by QSqlDatabase::addDatabase.
		@param host The machine address where stands the database.
		@param db The connection base name.
		@param numConn The connection number to be added to the connection base name.
	*/
	void newDatabase(QString type, QString host, QString db, int numConn);
	//! Initializes the QSqlQuery pointer.
	/*!	Gets a new QSqlQuery object and assigns to the \ref qsq pointer.
	*/
	void initQuery();
	//! Gets a QString holding the result of a statement placed at row \c x, column \c y \ref ql coordinates.
	/*!	The results are stored in a \c QList holding a number of \c QSqlRecord objects. This forms a table of results which can be accessed through row \c x, column \c y coordinates.
		@param x The zero index row number.
		@param y The zero index column number.
		@returns A \c QString representing the result placed at row \c x, column \c y coordinates.
	*/
	QString get(int x, int y);
	//! Gets a QString holding the result of a statement placed on row \c x, and column \c columnName \ref ql coordinates.
	/*!	The results are stored in a \c QList holding a number of \c QSqlRecord objects. This forms a table of results which can be accessed through row \c x, column \c columnName coordinates.
		@param x The zero index row number.
		@param columnName The name of the column.
		@returns A \c QString representing the result placed at row \c x, column \c columnName coordinates.
	*/
	QString get(int x, QString columnName);
	//! The number of results.
	/*!	The results are stored in a \c QList. This function returns the number of \c QSqlRecord objects returned by the query.
		@returns The number of \c QSqlRecord objects returned by the query.
	*/
	int size();
	//! Executes a query with the statement \c stmt.
	/*!	Stores the statement represented by \c stmt, and executes a query with it.
		@param The statement to be executed.
	*/
	void execSql(QString stmt);
	//! Executes a query with the statement stored in \ref Result::stmt.
	/*!	Executes a query obtaining the statement from \ref Result::stmt.
	*/
	void execSql();
	//! Returns a \c boolean indicating wheather the database connection is open or not.
	/*!	Returns a \c boolean indicating wheather the database connection is open or not.
		@returns \c true if the database connection is open; \c false otherwise.
	*/
	bool isOpen();
	//! Returns a \c boolean indicating wheather the database connection is a valid connection.
	/*!	Returns a \c boolean indicating wheather the database connection is a valid connection.
		@returns \c true if the database connection is a valid connection; \c false otherwise.
	*/
	bool isValid();
	//! Closes the database connection.
	/*!	Closes the database connection.
	*/
	void close();
	//! Initializes the database connection.
	/*!	Initializes the database connection through a call to QSqlDatabase() which returns an invalid database connection.
	*/
	void initDb();
	//! Sets the \ref stmt member.
	/*!	Sets the \ref stmt member which holds the statement to query the database.
		@param stmt The statement to execute.
	*/
	void setStmt(QString stmt);
	//! Sets the \ref connName member.
	/*!	Sets the \ref connName member which holds the database connection name.
		@param The connection name to store.
	*/
	void setConnName(QString connName);
	//! Gets the \ref connName member.
	/*!	Gets the \ref connName member which holds the database connection name.
		@returns A \c QString with the database connection name.
	*/
	QString getConnName();
	//! Gets the pointer to the database.
	/*!	Gets the \ref ptrDb pointer to the database.
		@returns A \c QSqlDatabase pointer which points to the \ref db member variable.
	*/
	QSqlDatabase *getDB();
	//! Indicates weather the query has been executed or not.
	/*!	Indicates weather the query has been executed or not.
		@returns \c true if the query has been executed; \c false otherwise.
	*/
	bool isExecuted();
	//! Sets the \ref executed member.
	/*!	Sets the \ref executed member to \c true when the query has been executed, and to \c false when database timeout has expired.
		@param executed \c true when the query has been executed; \c false when database renewal has ocurred due to timeout.
	*/
	void setExecuted(bool executed);
	//! Indicates if database is in renewal process.
	/*!	Indicates if database is in renewal process. Prevents to obtain this database connection to execute queries when it is in the renewal process due to expired timeout.
		@returns \c true if the database is in renewal process; \c false otherwise.
	*/
	bool isBlocked();
	//! Sets the \ref blocked member.
	/*!	Sets the \ref blocked member to mark if the database is in the renewal process due to timeout, or if it is ready to execute queries.
		@param \c true if the database is about to enter in the renewal process; \c false otherwise.
	*/
	void setBlocked(bool blocked);
	//! Deletes all resources related to the database and closes it.
	/*!	Deletes all resources related to the database: closes \c QSqlRecords, deletes \ref ql and \ref qsq objectes, closes the database and removes the connectin from \c QSqlDatabase.
	*/
	void deleteDB();
	//! Indicates the number of seconds from the last executed query.
	/*! Indicates the number of seconds from the last executed query, to be compared with the timeot.
		@returns The number of seconds from the last executed query.
	*/
	int elapsed();
	//! Sets the \ref dateTime member.
	/*! Sets the \ref dateTime member, which holds the date and time of the last executed query.
	*/
	void setDateTime();
};

//! Manages a database connection pool.
/*!
  The class manages a database connection pool: gives connections on demand, stores and updates database connections an releases them.
  The database is SQLite located at \c data directory.
*/
class DB {
private:
	//! Holds the maximum number of connections allowed.
	int maxConnections;
	//! Holds the \ref Result objects which manage the connections to the database.
	QVector<Result*> *vecDBC;
	//! Creates the \ref Result objects, initializes the database connections and stores this objects into the vector.
	int pool(int i);
	//! Holds the maximum time a database connection is to be considered valid.
	int timeout;
public:
	//! Initializes the \ref maxConnections and \ref timeout members, and creates all \ref Result database connection instances.
	DB();
	//! Releases all database connections and related resources
	~DB();
	//! Gets a database connection
	/*! Gets a database connection, setting its \c stmt member.
		@param stmt The statement to be executed through this database connection.
		@returns A pointer to a \ref Result object
	*/
	Result* getConnection(QString stmt);
	//! Gets a database connection
	/*! Gets a database connection through a \ref Result object.
		@returns A pointer to a \ref Result object
	*/
	Result* getConnection();
	//! Releases all database connections stored in vector
	void releaseDB();
	//! Releases a database connection
	/*! Releases a database connection by deletion of the \ref Result object and all its associated resources.
		@param i The index of the \ref Result object inside the vector holding all database connections.
	*/
	void releaseDB(int i);
	//! Updates the database connections.
	/*! Updates all the database connections by checking its timeouts and returns the first available database connection.
		@returns A \ref Result object containing a valid database connection.
	*/
	Result* updateDBs();
};

#endif // DB_H
