import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
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

                // Par ceci:
                /*
                Item {
                    //Layout.fillWidth: true
                    Layout.fillHeight: true
                }*/

                Text {
                    text: model.tempMin + "°C / " + model.tempMax + "°C"
                    font.bold: true
                }

                Connections {
                    target: weatherAPI

                    function onWeatherDataFetched(cityName, temperature, condition, iconUrl) {
                        // Traiter les données ici, par exemple :
                        stackView.push("CurrentWeather.qml", {
                            city: cityName,
                            temp: temperature,
                            conditionText: condition,
                            weatherIcon: iconUrl
                        });
                    }

                    function onErrorOccurred(errorMsg) {
                        console.log("Erreur réseau : ", errorMsg);
                    }
                }

            }
        }
    }
}
