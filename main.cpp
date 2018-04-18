#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "grille.h"
#include <iostream>
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
    Grille jeu_test_console(4);
    cout<<"translation bas"<<endl;
    jeu_test_console.translate_bas();
     cout<<"translation droite"<<endl;
     jeu_test_console.translate_droite();
     cout<<"translation haut"<<endl;
     jeu_test_console.translate_haut();
     cout<<"translation gauche"<<endl;
     jeu_test_console.translate_gauche();
    cout<<"afficher"<<endl;


}
