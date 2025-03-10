#include "projet/inc/weatherdata.h"

WeatherData::WeatherData(QObject *parent) : QObject(parent) {}

QString WeatherData::city() const { return m_city; }
QString WeatherData::temperature() const { return m_temperature; }
QString WeatherData::condition() const { return m_condition; }
QString WeatherData::icon() const { return m_icon; }
QList<ForecastEntry> WeatherData::forecast() const { return m_forecast; }

void WeatherData::setCity(const QString &city) {
    if (m_city != city) {
        m_city = city;
        emit cityChanged();
    }
}

void WeatherData::setTemperature(const QString &temperature) {
    if (m_temperature != temperature) {
        m_temperature = temperature;
        emit temperatureChanged();
    }
}

void WeatherData::setCondition(const QString &condition) {
    if (m_condition != condition) {
        m_condition = condition;
        emit conditionChanged();
    }
}

void WeatherData::setIcon(const QString &icon) {
    if (m_icon != icon) {
        m_icon = icon;
        emit iconChanged();
    }
}

void WeatherData::setForecast(const QList<ForecastEntry> &forecast) {
    m_forecast = forecast;
    emit forecastChanged();
}
