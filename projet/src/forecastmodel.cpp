#include "projet/inc/forecastmodel.h"

ForecastModel::ForecastModel(QObject *parent) : QAbstractListModel(parent) {}

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
