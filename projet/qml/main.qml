import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import projet 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 450
    height: 700
    title: qsTr("🌤️ Weather Dashboard")
    color: weatherAPI.isDay ? "#87CEEB" : "#2C3E50"

    // Déclaration de l'objet backend
    WeatherAPI {
        id: weatherAPI
    }

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
                    onClicked: weatherAPI.fetchWeather(cityInput.text)
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
                source: isDay ? "qrc:/images/sunny.png" : "qrc:/images/night.png"
                anchors.fill: parent
                opacity: 0.2
                fillMode: Image.PreserveAspectCrop
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
                    onClicked: stack.push(forecastScreen)
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
                            source: iconUrl
                            width: 50
                            height: 50
                        }

                        Column {
                            Text { text: date; font.bold: true }
                            Text { text: condition }
                        }

                        Text {
                            text: tempMin + "°C / " + tempMax + "°C"
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
            console.error("❌ Error: " + message);
        }
    }
}
