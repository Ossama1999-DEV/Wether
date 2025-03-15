#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WeatherAPI : public QObject
{
    Q_OBJECT
public:
    explicit WeatherAPI(QObject *parent = nullptr);

    Q_INVOKABLE void fetchWeather(const QString &city);

signals:
    void weatherDataFetched(const QString &cityName, const QString &temperature, const QString &condition, const QString &iconUrl);
    void errorOccurred(const QString &errorMsg);

private slots:
    void replyFinished(QNetworkReply *reply); // Corrigé ici !

private:
    QNetworkAccessManager m_manager;
};

#endif // WEATHERAPI_H
