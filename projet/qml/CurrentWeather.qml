import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    property alias cityName: cityName.text
    property alias temperatureText: temperature.text
    property alias weatherConditionText: weatherCondition.text
    property alias weatherIconUrl: weatherIcon.source

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 12

        Text {
            id: cityName
            font.pixelSize: 24
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
        }

        Image {
            id: weatherIcon
            width: 100
            height: 100
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: temperature
            font.pixelSize: 32
            font.bold: true
        }

        Text {
            id: weatherCondition
            font.pixelSize: 20
        }
    }
}
