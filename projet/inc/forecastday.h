#ifndef FORECASTDAY_H
#define FORECASTDAY_H

#include <QString>

struct ForecastDay {
    QString date;
    QString tempMin;
    QString tempMax;
    QString condition;
    QString iconUrl;
};

#endif // FORECASTDAY_H
