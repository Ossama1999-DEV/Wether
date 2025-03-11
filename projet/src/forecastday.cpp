#include "projet/inc/forecastday.h"

ForecastDay::ForecastDay(QObject *parent) : QObject(parent), m_tempMin(0), m_tempMax(0) {}

QString ForecastDay::date() const { return m_date; }
void ForecastDay::setDate(const QString &date) {
    if (m_date != date) {
        m_date = date;
        emit dateChanged();
    }
}

QString ForecastDay::condition() const { return m_condition; }
void ForecastDay::setCondition(const QString &condition) {
    if (m_condition != condition) {
        m_condition = condition;
        emit conditionChanged();
    }
}

QString ForecastDay::iconUrl() const { return m_iconUrl; }
void ForecastDay::setIconUrl(const QString &iconUrl) {
    if (m_iconUrl != iconUrl) {
        m_iconUrl = iconUrl;
        emit iconUrlChanged();
    }
}

double ForecastDay::tempMin() const { return m_tempMin; }
void ForecastDay::setTempMin(double tempMin) {
    if (m_tempMin != tempMin) {
        m_tempMin = tempMin;
        emit tempMinChanged();
    }
}

double ForecastDay::tempMax() const { return m_tempMax; }
void ForecastDay::setTempMax(double tempMax) {
    if (m_tempMax != tempMax) {
        m_tempMax = tempMax;
        emit tempMaxChanged();
    }
}
