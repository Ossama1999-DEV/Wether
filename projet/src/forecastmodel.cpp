#include "../inc/forecastmodel.h"
#include "../inc/weatherAPI.h"

ForecastModel::ForecastModel(QObject *parent)
    : QAbstractListModel(parent) {
    connect(this, &ForecastModel::cityNameChanged, this, &ForecastModel::updateForecast);
}

int ForecastModel::rowCount(const QModelIndex &) const {
    return m_forecastList.size();
}

QVariant ForecastModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_forecastList.size())
        return QVariant();

    const ForecastDay &day = m_forecastList.at(index.row());

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
    beginResetModel();
    WeatherAPI api;
    m_forecastList = api.getForecastForCity(m_cityName); // Implémente cette méthode dans WeatherAPI
    endResetModel();
}
