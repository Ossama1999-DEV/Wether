#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "projet/inc/weatherAPI.h"
#include "projet/inc/forecastmodel.h" // obligatoire !

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<WeatherAPI>("projet1QtWether", 1, 0, "WeatherAPI");
    qmlRegisterType<ForecastModel>("projet1QtWether", 1, 0, "ForecastModel"); // ✅ Ajoute cette ligne !

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
