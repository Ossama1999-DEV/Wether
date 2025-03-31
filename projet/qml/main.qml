import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
//import QtQuick.Effects 1.0
import projet1QtWether 1.0


ApplicationWindow {
    visible: true
    width: 450
    height: 700
    color: weatherAPI.isDay ? "#87CEEB" : "#2C3E50"  // Bleu jour / Bleu nuit
    title: qsTr("🌤️ Weather Dashboard")

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: searchScreen
    }

    Component {
        id: searchScreen

        Rectangle {
            anchors.fill: parent
            color: "transparent"

            ColumnLayout {
                anchors.centerIn: parent
                spacing: 20

                TextField {
                    id: cityInput
                    placeholderText: "🌍 Enter city name"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 40
                    Layout.margins: 20
                }

                Button {
                    text: "🔍 Get Weather"
                    Layout.alignment: Qt.AlignHCenter
                    onClicked: {
                                weatherAPI.fetchWeather(cityInput.text);
                                stack.push(currentWeatherScreen);  // ← ajoute précisément cette ligne !
                    }
                }
            }
        }
    }

    Component {
        id: currentWeatherScreen

        Rectangle {
            property string cityName
            property string temperature
            property string condition
            property string iconUrl
            property bool isDay

            anchors.fill: parent
            color: isDay ? "#87CEEB" : "#2C3E50"

            Image {
                source: (new Date().getHours() >= 6 && new Date().getHours() < 19) ?
                    "qrc:/images/projet/images/sunny.png" :
                    "qrc:/images/projet/images/night.png"
                anchors.fill: parent
                opacity: 0.5
            }

            ColumnLayout {
                anchors.centerIn: parent
                spacing: 20

                Text {
                    text: cityName
                    font.pixelSize: 28
                    font.bold: true
                    color: "white"
                }

                Image {
                    source: iconUrl
                    width: 100
                    height: 100
                }

                Text {
                    text: temperature + " °C"
                    font.pixelSize: 40
                    color: "white"
                }

                Text {
                    text: condition
                    font.pixelSize: 20
                    color: "white"
                }

                Button {
                    text: "📅 Voir prévisions"
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter

                    onClicked: {
                        stack.push("Forecast.qml", { city: weatherAPI.cityName });
                    }
                }

            }
        }
    }

    Component {
        id: forecastScreen

        Rectangle {
            anchors.fill: parent
            color: weatherAPI.isDay ? "#87CEEB" : "#2C3E50"

            ListView {
                anchors.fill: parent
                model: weatherAPI.forecastDays

                delegate: Rectangle {
                    width: parent.width
                    height: 80
                    color: index % 2 === 0 ? "#ffffff" : "#f0f8ff"

                    Row {
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 20

                        Image {
                            source: model.iconUrl
                            width: 50; height: 50
                        }

                        Column {
                            Text { text: model.date; font.bold: true }
                            Text { text: model.condition }
                        }

                        Text {
                            text: model.tempMin + "°C / " + model.tempMax + "°C"
                            font.bold: true
                        }
                    }
                }
            }
        }
    }

    Connections {
        target: weatherAPI

        function onWeatherDataFetched(cityName, temperature, condition, iconUrl, isDay) {
            stack.push(currentWeatherScreen, {
                cityName: cityName,
                temperature: temperature,
                condition: condition,
                iconUrl: iconUrl,
                isDay: isDay
            });
        }

        function onErrorOccurred(message) {
            console.error("Erreur réseau : " + message);
        }
    }

    WeatherAPI {
        id: weatherAPI
    }
}
