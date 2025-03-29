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
            Label {
                text: "Prévisions pour " + forecastScreen.city
                font.pixelSize: 18
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }

    background: Rectangle {
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#87CEFA" }
            GradientStop { position: 1.0; color: "#E0FFFF" }
        }
    }

    ListView {
        id: forecastList
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10
        model: ForecastModel { cityName: forecastScreen.city }

        delegate: Rectangle {
            width: parent.width
            height: 70
            radius: 10
            color: "#ffffff"
            border.color: "#dddddd"
            border.width: 1

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 20

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    color: "#87CEEB"
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft

                    Text {
                        anchors.centerIn: parent
                        text: day // Affiche désormais Lun, Mar, etc.
                        font.pixelSize: 14
                        font.bold: true
                        color: "white"
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 5

                    Text {
                        text: condition
                        font.pixelSize: 16
                        font.bold: true
                        color: "#333333"
                    }

                    Text {
                        text: temp + " °C"
                        font.pixelSize: 14
                        color: "#555555"
                    }
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }
    }
}