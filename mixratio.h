#ifndef MIXRATIO_H
#define MIXRATIO_H

#include <QMainWindow>
#include <QObject>
#include "pump.h"


class MixRatio
{
public:
    MixRatio(int pumpID, double ratio);
    double ratio;
    Pump *pump;
};

#endif // MIXRATIO_H
