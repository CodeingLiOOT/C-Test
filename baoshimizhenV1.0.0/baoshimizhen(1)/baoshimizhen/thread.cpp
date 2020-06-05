#include "thread.h"

myThread::myThread()
{
    data=0;
}

void myThread::run()
{
   while(1)
    {
        if(data<100)
        {
            data++;
        }
        else
        {
            data=0;
        }
        sleep(1);
    }
}
