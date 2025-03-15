#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "projet/inc/weatherAPI.h"
<<<<<<< HEAD
#include "projet/inc/forecastModel.h"
=======
#include "projet/inc/forecastmodel.h"
#include "projet/inc/forecastday.h"
>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
<<<<<<< HEAD
    QQmlApplicationEngine engine;

    WeatherAPI weatherApi;
    engine.rootContext()->setContextProperty("weatherAPI", &weatherApi);
    engine.rootContext()->setContextProperty("forecastModel", weatherApi.forecastDays());

=======

    qmlRegisterType<WeatherAPI>("projet", 1, 0, "WeatherAPI");
    qmlRegisterType<ForecastModel>("projet", 1, 0, "ForecastModel");
    qmlRegisterType<ForecastDay>("projet", 1, 0, "ForecastDay");

    QQmlApplicationEngine engine;
>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
    const QUrl url(u"qrc:/projet/projet/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
<<<<<<< HEAD
=======

>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
    engine.load(url);
    return app.exec();
}
