/**
 * @file forecastmodel.h
 * @brief Déclaration de la classe ForecastModel
 * @version 1.0
 * @date 2021-03-08
 * @author Ossama1999-DEV
 */

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
        ConditionRole,
        IconUrlRole,
        TempMinRole,
        TempMaxRole
    };

    ForecastModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void setForecast(const QList<ForecastDay*> &forecast);

private:
    QList<ForecastDay*> m_forecast;
};

#endif // FORECASTMODEL_H
