import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: item1
    width: 710
    height: 700
    Rectangle {
        id: rect_global
        color: "#faf8ef"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Rectangle {
            id: rectangle1
            y: 200
            width: 480
            height: 480
            color: "#bbada0"
            anchors.left: parent.left
            anchors.leftMargin: 15
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 15
            scale: 1
            transformOrigin: Item.Center

            Grid {
                id: grilledujeu
                anchors.fill: parent

                opacity: 1
                clip: false
                visible: true
                scale: 0.9
                transformOrigin: Item.Center
                rows: partieDeJeu.taille
                columns: partieDeJeu.taille
                spacing: 10
                Repeater {
                    id: modelegrille
                    model: partieDeJeu.taille * partieDeJeu.taille
                    anchors.fill: parent
                    delegate: Rectangle {
                        id: cases
                        width: 430 / partieDeJeu.taille
                        height: 430 / partieDeJeu.taille
                        radius: 5
                        color: partieDeJeu.couleurs[index]
                        Text {
                            id: remplissage
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.family: "Tahoma"
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: 40
                            focus: true
                            text: partieDeJeu.grille[index]
                        }

                        property int moveAnimTime: 300
                        property int newTileAnimTime: 600
                        property bool runNewTileAnim: false
                    }
                }
            }
        }
    }

    Rectangle {
        id: score_box
        x: 286
        y: 32
        width: 220
        height: 40
        color: "#8c8178"
        radius: 2

        Text {
            height: 38
            text: qsTr("Score : ")
            renderType: Text.NativeRendering
            anchors.fill: parent
            font.family: "Verdana"
            verticalAlignment: Text.AlignVCenter
            visible: true
            scale: 1
            wrapMode: Text.NoWrap
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.RichText
            font.pixelSize: 28
            font.bold: false
            color: "#ffffff"
        }
    }
    Rectangle {
        id: score_container
        x: 286
        y: 71
        width: 220
        height: 40
        radius: 2
        color: "#8c8178"
        Text {
            text: partieDeJeu.score
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.fill: parent
            visible: true
            scale: 1
            wrapMode: Text.NoWrap
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.RichText
            font.pixelSize: 28
            font.bold: false
            color: "#ffffff"
        }
    }

    Label {
        id: logo_jeu_2048
        width: 152
        height: 71
        color: "#8c7878"
        text: qsTr("2048")
        textFormat: Text.RichText
        renderType: Text.QtRendering
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
        anchors.left: parent.left
        anchors.leftMargin: 54
        anchors.top: parent.top
        horizontalAlignment: Text.AlignHCenter
        anchors.topMargin: 32
        font.pixelSize: 55
        font.family: "Arial"
        font.bold: true
        fontSizeMode: Text.Fit
        wrapMode: Text.WordWrap
    }
}
