#ifndef KEYTHREAD_H
#define KEYTHREAD_H

#include <QThread>
#include "wiringPi.h"

class keythread : public QThread
{
    Q_OBJECT
public:
    explicit keythread(QObject *parent=0);
    void run();

signals:
    void rpikeyevent();

public slots:

private :

};

#endif // KEYTHREAD_H
