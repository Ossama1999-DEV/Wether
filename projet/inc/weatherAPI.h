#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "forecastday.h"

class WeatherAPI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cityName READ cityName NOTIFY cityNameChanged)

public:
    explicit WeatherAPI(QObject *parent = nullptr);

    Q_INVOKABLE void fetchWeather(const QString &city);
    QString cityName() const;

    // Méthode ajoutée
    QList<ForecastDay> getForecastForCity(const QString &cityName);

signals:
    void weatherDataFetched(const QString &city, const QString &temperature, const QString &condition, const QString &iconUrl);
    void errorOccurred(const QString &errorMessage);
    void cityNameChanged();

private slots:
    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager m_manager;
    QString m_cityName;
};

#endif // WEATHERAPI_H
