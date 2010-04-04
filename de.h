#ifndef DE_H
#define DE_H

#include <QObject>

class DE : public QObject
{
    Q_OBJECT
public:
    DE();
    static QString name();
};

#endif // DE_H
