import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: currentWeatherScreen

    header: ToolBar {
        RowLayout {
            anchors.fill: parent

            ToolButton {
                text: "← Retour"
                font.pixelSize: 16
                onClicked: stack.pop() // Retour vers SearchScreen.qml
            }

            Label {
                text: "Météo actuelle"
                font.pixelSize: 18
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 10

        Image {
            id: weatherIcon
            source: iconUrl
            width: 100
            height: 100
        }

        Label {
            id: cityLabel
            text: city
            font.pixelSize: 32
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            id: temperatureLabel
            text: temperature
            font.pixelSize: 28
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            id: conditionLabel
            text: condition
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
        }
    }
}