/**
 * @file weatherdata.h
 * @brief Déclaration de la classe WeatherData
 * @version 1.0
 * @date 2021-03-08
 * @author Ossama1999-DEV
 */
#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QString>
#include <QList>

struct ForecastEntry {
    QString date;
    QString condition;
    QString iconUrl;
    QString tempMin;
    QString tempMax;
};

class WeatherData : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(QString condition READ condition WRITE setCondition NOTIFY conditionChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QList<ForecastEntry> forecast READ forecast WRITE setForecast NOTIFY forecastChanged)

public:
    explicit WeatherData(QObject *parent = nullptr);

    QString city() const;
    QString temperature() const;
    QString condition() const;
    QString icon() const;
    QList<ForecastEntry> forecast() const;

    void setCity(const QString &city);
    void setTemperature(const QString &temperature);
    void setCondition(const QString &condition);
    void setIcon(const QString &icon);
    void setForecast(const QList<ForecastEntry> &forecast);

signals:
    void cityChanged();
    void temperatureChanged();
    void conditionChanged();
    void iconChanged();
    void forecastChanged();

private:
    QString m_city;
    QString m_temperature;
    QString m_condition;
    QString m_icon;
    QList<ForecastEntry> m_forecast;
};

#endif // WEATHERDATA_H
