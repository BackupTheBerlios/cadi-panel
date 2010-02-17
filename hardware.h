#ifndef HARDWARE_H
#define HARDWARE_H

#include <QObject>

class Hardware : public QObject
{
public:
    Hardware();
    static QStringList processor();
};

#endif // HARDWARE_H
