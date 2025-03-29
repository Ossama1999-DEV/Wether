#ifndef FORECASTDAY_H
#define FORECASTDAY_H

#include <QString>

class ForecastDay {
public:
    ForecastDay(const QString &day, const QString &condition, const QString &temp);

    QString day() const;
    QString condition() const;
    QString temp() const;

private:
    QString m_day;
    QString m_condition;
    QString m_temp;
};

#endif // FORECASTDAY_H
