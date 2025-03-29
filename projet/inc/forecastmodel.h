#ifndef FORECASTMODEL_H
#define FORECASTMODEL_H

#include <QAbstractListModel>
#include "forecastday.h"

class ForecastModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(QString cityName READ cityName WRITE setCityName NOTIFY cityNameChanged)

public:
    explicit ForecastModel(QObject *parent = nullptr);

    enum Roles {
        DayRole = Qt::UserRole + 1,
        ConditionRole,
        TempRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    QString cityName() const;
    void setCityName(const QString &city);

signals:
    void cityNameChanged();

private slots:
    void updateForecast();

private:
    QString m_cityName;
    QList<ForecastDay> m_forecastList;
};

#endif // FORECASTMODEL_H
