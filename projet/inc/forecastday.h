<<<<<<< HEAD
#ifndef FORECASTDAY_H
#define FORECASTDAY_H

#include <QString>

struct ForecastDay {
    QString date;
    QString tempMin;
    QString tempMax;
    QString condition;
    QString iconUrl;
=======
/**
 * @file forecastday.h
 * @brief Déclaration de la classe ForecastDay
 * @version 1.0
 * @date 2021-03-08
 * @author Ossama1999-DEV
 */
#ifndef FORECASTDAY_H
#define FORECASTDAY_H

#include <QObject>

class ForecastDay : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QString condition READ condition WRITE setCondition NOTIFY conditionChanged)
    Q_PROPERTY(QString iconUrl READ iconUrl WRITE setIconUrl NOTIFY iconUrlChanged)
    Q_PROPERTY(double tempMin READ tempMin WRITE setTempMin NOTIFY tempMinChanged)
    Q_PROPERTY(double tempMax READ tempMax WRITE setTempMax NOTIFY tempMaxChanged)

public:
    explicit ForecastDay(QObject *parent = nullptr);

    QString date() const;
    void setDate(const QString &date);

    QString condition() const;
    void setCondition(const QString &condition);

    QString iconUrl() const;
    void setIconUrl(const QString &iconUrl);

    double tempMin() const;
    void setTempMin(double tempMin);

    double tempMax() const;
    void setTempMax(double tempMax);

signals:
    void dateChanged();
    void conditionChanged();
    void iconUrlChanged();
    void tempMinChanged();
    void tempMaxChanged();

private:
    QString m_date;
    QString m_condition;
    QString m_iconUrl;
    double m_tempMin;
    double m_tempMax;
>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
};

#endif // FORECASTDAY_H
