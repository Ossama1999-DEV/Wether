#include "../inc/forecastmodel.h"
#include "../inc/weatherAPI.h"
#include <QLocale>
#include <QDate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ForecastModel::ForecastModel(QObject *parent)
    : QAbstractListModel(parent) {
    connect(this, &ForecastModel::cityNameChanged, this, &ForecastModel::updateForecast);
}

int ForecastModel::rowCount(const QModelIndex &) const {
    return m_forecastDays.size();
}

QVariant ForecastModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_forecastDays.size())
        return QVariant();

    const ForecastDay &day = m_forecastDays.at(index.row());

    switch (role) {
        case DayRole:
            return day.day();
        case ConditionRole:
            return day.condition();
        case TempRole:
            return day.temp();
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> ForecastModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DayRole] = "day";
    roles[ConditionRole] = "condition";
    roles[TempRole] = "temp";
    return roles;
}

QString ForecastModel::cityName() const {
    return m_cityName;
}

void ForecastModel::setCityName(const QString &city) {
    if (m_cityName != city) {
        m_cityName = city;
        emit cityNameChanged();
    }
}

void ForecastModel::updateForecast() {
    const QString apiKey = "35a2ea1e8bf748c6917132034250803";
    QString url = QString("http://api.weatherapi.com/v1/forecast.json?key=%1&q=%2&days=5&aqi=no&alerts=no")
                      .arg(apiKey, m_cityName);

    QNetworkRequest request{QUrl(url)};
    QNetworkReply *reply = m_manager.get(request);

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        parseNetworkReply(reply);
        reply->deleteLater();
    });
}

void ForecastModel::parseNetworkReply(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray jsonResponse = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonResponse);
        QJsonArray forecastArray = jsonDoc.object()["forecast"].toObject()["forecastday"].toArray();

        beginResetModel();
        m_forecastDays.clear();
        for (const QJsonValue &val : forecastArray) {
            QJsonObject dayObj = val.toObject();

            QString dateStr = dayObj["date"].toString();
            QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
            QString shortDayName = QLocale("fr_FR").toString(date, "ddd");

            QString condition = dayObj["day"].toObject()["condition"].toObject()["text"].toString();
            QString temp = QString::number(dayObj["day"].toObject()["avgtemp_c"].toDouble(), 'f', 1);

            ForecastDay day(shortDayName, condition, temp);
            m_forecastDays.append(day);
        }
        endResetModel();
    }
}
