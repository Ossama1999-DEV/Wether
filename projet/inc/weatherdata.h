#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QString>
#include <QVector>

struct ForecastEntry {
    QString date;
    double temperature;
    QString icon;
};

class WeatherData : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(double temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(QString condition READ condition WRITE setCondition NOTIFY conditionChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QVector<ForecastEntry> forecast READ forecast WRITE setForecast NOTIFY forecastChanged)

public:
    explicit WeatherData(QObject *parent = nullptr);

    QString city() const;
    void setCity(const QString &city);

    double temperature() const;
    void setTemperature(double temperature);

    QString condition() const;
    void setCondition(const QString &condition);

    QString icon() const;
    void setIcon(const QString &icon);

    QVector<ForecastEntry> forecast() const;
    void setForecast(const QVector<ForecastEntry> &forecast);

signals:
    void cityChanged();
    void temperatureChanged();
    void conditionChanged();
    void iconChanged();
    void forecastChanged();

private:
    QString m_city;
    double m_temperature;
    QString m_condition;
    QString m_icon;
    QVector<ForecastEntry> m_forecast;
};

#endif // WEATHERDATA_H
