#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "forecastmodel.h"

class WeatherAPI : public QObject
{
    Q_OBJECT
public:
    explicit WeatherAPI(QObject *parent = nullptr);
    Q_INVOKABLE void fetchWeather(const QString &city);
    ForecastModel* forecastDays();

signals:
    void weatherDataFetched(const QString &cityName,
                            const QString &temperature,
                            const QString &condition,
                            const QString &iconUrl,
                            bool isDay);
    void errorOccurred(const QString &message);

private slots:
    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager m_manager;
    ForecastModel m_forecastModel;
};

#endif // WEATHERAPI_H
