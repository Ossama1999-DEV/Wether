import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: currentWeatherScreen
    property string city: ""
    property string temperature: ""
    property string condition: ""
    property string iconUrl: ""

    background: Rectangle {
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#87CEEB" }
            GradientStop { position: 1.0; color: "#E0FFFF" }
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 15

        Image {
            source: iconUrl
            width: 80
            height: 80
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: city
            font.pixelSize: 28
            font.bold: true
            color: "#ffffff"
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: temperature + " °C"
            font.pixelSize: 32
            color: "#ffffff"
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: condition
            font.pixelSize: 20
            color: "#ffffff"
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout {
            spacing: 20
            Layout.alignment: Qt.AlignHCenter

            Button {
                text: "📅 All days"
                onClicked: stack.push("Forecast.qml", { city: city })
            }

            Button {
                text: "Retour"
                width: 400
                onClicked: weatherAPI.fetchWeather(cityInput.text)
            }
        }

    }
}
