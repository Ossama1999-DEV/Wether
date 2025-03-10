#include "projet/inc/weatherAPI.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>

WeatherAPI::WeatherAPI(QObject *parent) : QObject(parent) {
    connect(&m_manager, &QNetworkAccessManager::finished, this, &WeatherAPI::replyFinished);
}

void WeatherAPI::fetchWeather(const QString &city) {
    QString url = QString("http://api.weatherapi.com/v1/forecast.json?key=35a2ea1e8bf748c6917132034250803&q=%1&days=5&aqi=no&alerts=no").arg(city);
    QNetworkRequest request{QUrl(url)};
    m_manager.get(request);
}

void WeatherAPI::replyFinished(QNetworkReply *reply) {
    if (reply->error()) {
        emit errorOccurred(reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray response = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
    QJsonObject obj = jsonDoc.object();

    QJsonObject location = obj["location"].toObject();
    QJsonObject current = obj["current"].toObject();
    QJsonObject condition = current["condition"].toObject();

    QString city = location["name"].toString();
    QString temperature = QString::number(current["temp_c"].toDouble());
    QString conditionText = condition["text"].toString();
    QString iconUrl = "https:" + condition["icon"].toString();
    bool isDay = current["is_day"].toInt() == 1;

    emit weatherDataFetched(city, temperature, conditionText, iconUrl, isDay);

    // Prévisions
    QList<ForecastDay> forecastList;
    QJsonArray forecastDays = obj["forecast"].toObject()["forecastday"].toArray();

    for (const QJsonValue &val : forecastDays) {
        QJsonObject day = val.toObject();
        QJsonObject dayInfo = day["day"].toObject();
        QJsonObject cond = dayInfo["condition"].toObject();

        ForecastDay fd;
        fd.date = day["date"].toString();
        fd.tempMin = QString::number(dayInfo["mintemp_c"].toDouble());
        fd.tempMax = QString::number(dayInfo["maxtemp_c"].toDouble());
        fd.condition = cond["text"].toString();
        fd.iconUrl = "https:" + cond["icon"].toString();
        forecastList.append(fd);
    }

    m_forecastModel.setForecastData(forecastList);
    reply->deleteLater();
}

ForecastModel* WeatherAPI::forecastDays() {
    return &m_forecastModel;
}
