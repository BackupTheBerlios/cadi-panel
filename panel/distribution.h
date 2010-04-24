#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include <QObject>
#include "process.h"

class Distribution : public QObject
{
    Q_OBJECT
private:
	Process pro;
public:
    Distribution();
	QString name();
	QString version();
	QString codename();
	QString kernel();
};

#endif // DISTRIBUTION_H
