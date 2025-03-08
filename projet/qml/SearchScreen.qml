import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects

Item {
    width: 450
    height: 700
    Column {
        anchors.centerIn: parent
        spacing: 20

        TextField {
            id: cityInput
            width: 300
            placeholderText: "Entrez une ville 🌍"
            font.pixelSize: 18
        }

        Button {
            text: "🔎 Rechercher"
            width: 150
            onClicked: weatherAPI.fetchWeather(cityInput.text)
        }
    }

    Connections {
        target: weatherAPI

        function onWeatherDataFetched(cityName, temperature, condition, iconUrl) {
            stackView.push("CurrentWeather.qml", {
                city: cityName,
                temp: temperature,
                conditionText: condition,
                weatherIcon: iconUrl
            });
        }

        function onErrorOccurred(errorMsg) {
            console.log("Erreur réseau : " + errorMsg);
        }
    }
}

