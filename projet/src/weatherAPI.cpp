#include "projet/inc/weatherAPI.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>

WeatherAPI::WeatherAPI(QObject *parent) : QObject(parent)
{
    connect(&m_manager, &QNetworkAccessManager::finished, this, &WeatherAPI::replyFinished);
}

void WeatherAPI::fetchWeather(const QString &city)
{
    const QString apiKey = "35a2ea1e8bf748c6917132034250803";
    QString url = QString("http://api.weatherapi.com/v1/current.json?key=%1&q=%2&aqi=no").arg(apiKey, city);
    QNetworkRequest request{QUrl(url)};
    m_manager.get(request);
}

void WeatherAPI::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QByteArray jsonResponse = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonResponse);

        if(jsonDoc.isNull()){
            emit errorOccurred("Invalid JSON");
            return;
        }

        QJsonObject jsonObj = jsonDoc.object();
        m_cityName = jsonObj["location"].toObject()["name"].toString();
        emit cityNameChanged();

        QString temperature = QString::number(jsonObj["current"].toObject()["temp_c"].toDouble()) + "°C";
        QString condition = jsonObj["current"].toObject()["condition"].toObject()["text"].toString();
        QString iconUrl = QString("https:%1").arg(jsonObj["current"].toObject()["condition"].toObject()["icon"].toString());

        emit weatherDataFetched(m_cityName, temperature, condition, iconUrl);
    } else {
        emit errorOccurred("Erreur réseau: " + reply->errorString());
    }

    reply->deleteLater();
}

// Nouvelle méthode implémentée
QString WeatherAPI::cityName() const {
    return m_cityName;
}
QList<ForecastDay> WeatherAPI::getForecastForCity(const QString &cityName)
{
    QList<ForecastDay> forecastList;

    const QString apiKey = "35a2ea1e8bf748c6917132034250803";
    QString url = QString("http://api.weatherapi.com/v1/forecast.json?key=%1&q=%2&days=5&aqi=no&alerts=no")
                  .arg(apiKey, cityName);

    QNetworkRequest request{QUrl(url)};
    m_manager.get(request);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(request);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if(reply->error() == QNetworkReply::NoError){
        QByteArray jsonResponse = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonResponse);

        if(!jsonDoc.isNull()){
            QJsonObject jsonObj = jsonDoc.object();
            QJsonArray forecastArray = jsonObj["forecast"].toObject()["forecastday"].toArray();

            foreach (const QJsonValue &value, forecastArray) {
                QJsonObject dayObj = value.toObject();
                QString date = dayObj["date"].toString();
                QString condition = dayObj["day"].toObject()["condition"].toObject()["text"].toString();
                double avgTemp = dayObj["day"].toObject()["avgtemp_c"].toDouble();

                forecastList.append(ForecastDay(date, condition, QString::number(avgTemp)));
            }
        }
    }

    reply->deleteLater();

    return forecastList;
}
