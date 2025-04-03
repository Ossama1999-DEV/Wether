import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import projet1QtWether 1.0

Page {
    id: forecastScreen
    property string city: ""

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: "← Retour"
                font.pixelSize: 16
                onClicked: stack.pop()
            }
        }
    }

    background: Rectangle {
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#6BB9F0" }
            GradientStop { position: 1.0; color: "#C5EFF7" }
        }
    }

    ListView {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10
        model: ForecastModel { cityName: city }

        delegate: Rectangle {
            width: parent.width - 20
            height: 80
            radius: 15
            color: "white"
            border.color: "#CCCCCC"
            border.width: 1
            anchors.horizontalCenter: parent.horizontalCenter

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 20

                Rectangle {
                    width: 60
                    height: 60
                    radius: 30
                    color: "#2C82C9"
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft

                    Text {
                        anchors.centerIn: parent
                        text: day
                        font.pixelSize: 16
                        font.bold: true
                        color: "white"
                    }
                }

                ColumnLayout {
                    spacing: 5
                    Layout.fillWidth: true

                    Text {
                        text: condition
                        font.pixelSize: 16
                        color: "#34495E"
                        font.bold: true
                    }

                    Text {
                        text: temp + " °C"
                        font.pixelSize: 14
                        color: "#7F8C8D"
                    }
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }
    }
}
