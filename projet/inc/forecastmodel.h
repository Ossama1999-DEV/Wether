#ifndef FORECASTMODEL_H
#define FORECASTMODEL_H

#include <QAbstractListModel>
#include "forecastday.h"

class ForecastModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ForecastRoles {
        DateRole = Qt::UserRole + 1,
        TempMinRole,
        TempMaxRole,
        ConditionRole,
        IconUrlRole
    };

    ForecastModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setForecastData(const QList<ForecastDay> &data);
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ForecastDay> m_data;
};

#endif // FORECASTMODEL_H
