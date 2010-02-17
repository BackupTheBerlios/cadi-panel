#ifndef DE_H
#define DE_H

#include <QObject>

class DE : public QObject
{
public:
    DE();
    static QString name();
};

#endif // DE_H
