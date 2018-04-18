import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("2048")

    Page1Form {
        anchors.fill: parent
        focus: true
        Keys.onPressed: {
          switch (event.key) {
            case Qt.Key_Up:
              partieDeJeu.translate_haut();
              break;
            case Qt.Key_Down:
                console.log('fleche du bas');
              partieDeJeu.translate_bas();
              break;
            case Qt.Key_Left:
              partieDeJeu.translate_gauche();
              break;
            case Qt.Key_Right:
              partieDeJeu.translate_droite();
              break;
          }
    
    
        }

}


}
