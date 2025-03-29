import QtQuick
import QtQuick.Controls
import projet1QtWether 1.0

Item {
    id: forecastScreen
    property string city: ""  // obligatoire !

    Column {
        anchors.fill: parent
        spacing: 10
        padding: 15

        Text {
            text: "Prévisions météo pour " + forecastScreen.city
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ListView {
            anchors.fill: parent
            model: ForecastModel { cityName: forecastScreen.city }

            delegate: Rectangle {
                width: parent.width
                height: 40
                color: index % 2 === 0 ? "#f0f0f0" : "#ffffff"

                Row {
                    anchors.fill: parent
                    spacing: 10
                    padding: 5

                    Text { text: day; font.bold: true }
                    Text { text: condition }
                    Text { text: temp + " °C"; anchors.right: parent.right }
                }
            }
        }
    }
}
