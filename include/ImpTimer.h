#ifndef IMPTIMER_H
#define IMPTIMER_H

#include <CommonFunc.h>
class ImpTimer
{
    public:
        ImpTimer();
        void start();
        int get_ticks();
    private:
        int start_tick;
};

#endif // IMPTIMER_H
