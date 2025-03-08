#include "weatherAPI.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

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
        QString city = jsonObj["location"].toObject()["name"].toString();
        QString temperature = QString::number(jsonObj["current"].toObject()["temp_c"].toDouble()) + "°C";
        QString condition = jsonObj["current"].toObject()["condition"].toObject()["text"].toString();
        QString iconUrl = QString("https:%1").arg(jsonObj["current"].toObject()["condition"].toObject()["icon"].toString());

        emit weatherDataFetched(city, temperature, condition, iconUrl);
    } else {
        emit errorOccurred("Erreur réseau: " + reply->errorString());
    }

    reply->deleteLater();
}
