#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "projet/inc/weatherAPI.h"
#include "projet/inc/forecastmodel.h"
#include "projet/inc/forecastday.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<WeatherAPI>("projet", 1, 0, "WeatherAPI");
    qmlRegisterType<ForecastModel>("projet", 1, 0, "ForecastModel");
    qmlRegisterType<ForecastDay>("projet", 1, 0, "ForecastDay");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/projet/projet/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    return app.exec();
}
