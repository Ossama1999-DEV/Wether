import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import projet1QtWether 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 450
    height: 700
    title: qsTr("🌤️ Weather Dashboard")
    color: weatherAPI.isDay ? "#87CEEB" : "#2C3E50"

    WeatherAPI { id: weatherAPI }

    ColumnLayout {
        anchors.fill: parent
        spacing: 10
        padding: 10

        Rectangle {
            width: parent.width
            height: 50
            color: "transparent"
            TextField {
                id: cityInput
                placeholderText: "🌍 Enter city name"
                Layout.fillWidth: true
            }
        }

        Button {
            text: "🔍 Get Weather"
            Layout.alignment: Qt.AlignHCenter
            onClicked: weatherAPI.fetchWeather(cityInput.text)
        }

        Image {
            id: backgroundImage
            source: weatherAPI.isDay ? "qrc:/images/sunny.png" : "qrc:/images/night.png"
            anchors.fill: parent
            opacity: 0.2
            z: -1
        }

        ColumnLayout {
            spacing: 10
            Layout.alignment: Qt.AlignHCenter
            Text {
                text: weatherAPI.cityName
                font.pixelSize: 28
                color: "white"
                visible: weatherAPI.cityName !== ""
            }
            Image {
                source: weatherAPI.iconUrl
                width: 100; height: 100
                visible: weatherAPI.iconUrl !== ""
            }
            Text {
                text: weatherAPI.temperature + " °C"
                font.pixelSize: 40
                color: "white"
                visible: weatherAPI.temperature !== ""
            }
            Text {
                text: weatherAPI.condition
                font.pixelSize: 20
                color: "white"
                visible: weatherAPI.condition !== ""
            }
        }

        Rectangle {
            width: parent.width
            height: 250
            color: "transparent"
            ListView {
                anchors.fill: parent
                model: weatherAPI.forecastDays
                delegate: Rectangle {
                    width: parent.width
                    height: 60
                    color: index % 2 === 0 ? "#ffffff" : "#e0f7fa"
                    RowLayout {
                        anchors.fill: parent
                        spacing: 10
                        Image {
                            source: model.iconUrl
                            width: 40; height: 40
                        }
                        ColumnLayout {
                            spacing: 2
                            Text { text: model.date; font.bold: true }
                            Text { text: model.condition }
                        }
                        Text {
                            text: model.tempMin + "°C / " + model.tempMax + "°C"
                            Layout.alignment: Qt.AlignRight
                            Layout.fillWidth: true
                        }
                    }
                }
            }
        }
    }

    Connections {
        target: weatherAPI
        function onErrorOccurred(message) {
            console.error("Erreur réseau : ", message)
        }
    }
}
