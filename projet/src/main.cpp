#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "projet/inc/weatherAPI.h"
#include "projet/inc/forecastModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    WeatherAPI weatherApi;
    engine.rootContext()->setContextProperty("weatherAPI", &weatherApi);
    engine.rootContext()->setContextProperty("forecastModel", weatherApi.forecastDays());

    const QUrl url(u"qrc:/projet/projet/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
