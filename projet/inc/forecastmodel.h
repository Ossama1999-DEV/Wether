#ifndef FORECASTMODEL_H
#define FORECASTMODEL_H

#include <QAbstractListModel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "forecastday.h"

class ForecastModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString cityName READ cityName WRITE setCityName NOTIFY cityNameChanged)

public:
    explicit ForecastModel(QObject *parent = nullptr);

    enum ForecastRoles {
        DayRole = Qt::UserRole + 1,
        ConditionRole,
        TempRole
    };

    QString cityName() const;
    void setCityName(const QString &city);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

signals:
    void cityNameChanged();

private slots:
    void updateForecast(); // déclaration correcte
    void parseNetworkReply(QNetworkReply *reply);

private:
    QString m_cityName;
    QList<ForecastDay> m_forecastDays; // correcte déclaration
    QNetworkAccessManager m_manager;
};

#endif // FORECASTMODEL_H
