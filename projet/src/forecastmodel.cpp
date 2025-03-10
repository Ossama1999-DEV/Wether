#include "projet/inc/forecastmodel.h"

ForecastModel::ForecastModel(QObject *parent) : QAbstractListModel(parent) {}

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
