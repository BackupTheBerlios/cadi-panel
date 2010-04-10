#ifndef HARDWARE_H
#define HARDWARE_H

#include <QObject>
#include "process.h"

class Hardware : public QObject
{
private:
	Process pro;
public:
    Hardware();
	QStringList processor();
	QStringList memory();
};

#endif // HARDWARE_H
