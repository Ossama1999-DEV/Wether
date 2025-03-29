#include "../inc/forecastday.h"

ForecastDay::ForecastDay(const QString &day, const QString &condition, const QString &temp)
    : m_day(day), m_condition(condition), m_temp(temp) {}

QString ForecastDay::day() const { return m_day; }
QString ForecastDay::condition() const { return m_condition; }
QString ForecastDay::temp() const { return m_temp; }
