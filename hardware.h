#ifndef HARDWARE_H
#define HARDWARE_H

#include <QObject>

class Hardware : public QObject
{
public:
    Hardware();
    static QStringList processor();
	static QStringList memory();
};

#endif // HARDWARE_H
