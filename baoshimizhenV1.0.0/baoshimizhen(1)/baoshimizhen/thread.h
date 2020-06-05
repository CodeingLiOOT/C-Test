#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    myThread();
    int data;
private slots:
    void run();

};

#endif // THREAD_H
