#include "projet/inc/forecastmodel.h"

ForecastModel::ForecastModel(QObject *parent) : QAbstractListModel(parent) {}

<<<<<<< HEAD
int ForecastModel::rowCount(const QModelIndex &) const {
    return m_data.size();
}

QVariant ForecastModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_data.size())
        return {};

    const ForecastDay &item = m_data[index.row()];
    switch (role) {
        case DateRole: return item.date;
        case TempMinRole: return item.tempMin;
        case TempMaxRole: return item.tempMax;
        case ConditionRole: return item.condition;
        case IconUrlRole: return item.iconUrl;
        default: return {};
    }
}

void ForecastModel::setForecastData(const QList<ForecastDay> &data) {
    beginResetModel();
    m_data = data;
    endResetModel();
}

QHash<int, QByteArray> ForecastModel::roleNames() const {
    return {
        {DateRole, "date"},
        {TempMinRole, "tempMin"},
        {TempMaxRole, "tempMax"},
        {ConditionRole, "condition"},
        {IconUrlRole, "iconUrl"}
    };
}
=======
int ForecastModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return m_forecast.size();
}

QVariant ForecastModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_forecast.size()) return QVariant();

    ForecastDay *day = m_forecast.at(index.row());
    switch (role) {
        case DateRole: return day->date();
        case ConditionRole: return day->condition();
        case IconUrlRole: return day->iconUrl();
        case TempMinRole: return day->tempMin();
        case TempMaxRole: return day->tempMax();
        default: return QVariant();
    }
}

QHash<int, QByteArray> ForecastModel::roleNames() const {
    return {
        { DateRole, "date" },
        { ConditionRole, "condition" },
        { IconUrlRole, "iconUrl" },
        { TempMinRole, "tempMin" },
        { TempMaxRole, "tempMax" }
    };
}

void ForecastModel::setForecast(const QList<ForecastDay*> &forecast) {
    beginResetModel();
    m_forecast = forecast;
    endResetModel();
}
>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
