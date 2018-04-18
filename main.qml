import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 710
    height: 700
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
              partieDeJeu.translate_bas();
              break;
            case Qt.Key_Left:
              partieDeJeu.translate_gauche();
              break;
            case Qt.Key_Right:
              partieDeJeu.translate_droite();
              break;
          }
          if (partieDeJeu.a_perdu()===true)
            a_perdu_jeu.open();
            if (partieDeJeu.a_gagne()===true)
                a_gagne_jeu.open();
    
    
        }

}
MessageDialog {
        id: a_perdu_jeu
        title: qsTr("Game Over")
        text: qsTr(" You lost the game you looser!")
        standardButtons: StandardButton.Retry | StandardButton.Abort
        onAccepted: {
            partieDeJeu.alloc_dyn_grille(4);

        }
        onRejected:Qt.quit();
    }
    MessageDialog {
        id: a_gagne_jeu
        title: qsTr("You win!")
        text: qsTr("Congratulations! You just won the game")
        standardButtons: StandardButton.Retry | StandardButton.Abort
        onAccepted: {
            partieDeJeu.alloc_dyn_grille(4);

        }
        onRejected:Qt.quit();
    }


}
