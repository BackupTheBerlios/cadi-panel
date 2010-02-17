#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include <QObject>

class Distribution : public QObject
{
public:
    Distribution();
    static QString name();
    static QString version();
    static QString codename();
    static QString kernel();
};

#endif // DISTRIBUTION_H
