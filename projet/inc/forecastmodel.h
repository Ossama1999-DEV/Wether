<<<<<<< HEAD
=======
/**
 * @file forecastmodel.h
 * @brief Déclaration de la classe ForecastModel
 * @version 1.0
 * @date 2021-03-08
 * @author Ossama1999-DEV
 */

>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
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
<<<<<<< HEAD
        TempMinRole,
        TempMaxRole,
        ConditionRole,
        IconUrlRole
=======
        ConditionRole,
        IconUrlRole,
        TempMinRole,
        TempMaxRole
>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
    };

    ForecastModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

<<<<<<< HEAD
    void setForecastData(const QList<ForecastDay> &data);
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ForecastDay> m_data;
=======
    QHash<int, QByteArray> roleNames() const override;

    void setForecast(const QList<ForecastDay*> &forecast);

private:
    QList<ForecastDay*> m_forecast;
>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
};

#endif // FORECASTMODEL_H
