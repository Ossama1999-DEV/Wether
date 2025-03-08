#include "weatherdata.h"

WeatherData::WeatherData(QObject *parent) : QObject(parent), m_temperature(0.0) {}

QString WeatherData::city() const {
    return m_city;
}

void WeatherData::setCity(const QString &city) {
    if (m_city != city) {
        m_city = city;
        emit cityChanged();
    }
}

double WeatherData::temperature() const {
    return m_temperature;
}

void WeatherData::setTemperature(double temperature) {
    if (m_temperature != temperature) {
        m_temperature = temperature;
        emit temperatureChanged();
    }
}

QString WeatherData::condition() const {
    return m_condition;
}

void WeatherData::setCondition(const QString &condition) {
    if (m_condition != condition) {
        m_condition = condition;
        emit conditionChanged();
    }
}

QString WeatherData::icon() const {
    return m_icon;
}

void WeatherData::setIcon(const QString &icon) {
    if (m_icon != icon) {
        m_icon = icon;
        emit iconChanged();
    }
}

QVector<ForecastEntry> WeatherData::forecast() const {
    return m_forecast;
}

void WeatherData::setForecast(const QVector<ForecastEntry> &forecast) {
    m_forecast = forecast;
    emit forecastChanged();
}
