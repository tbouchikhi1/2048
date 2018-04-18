#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "grille.h"
#include <iostream>
#include <QtQml>
int main(int argc, char *argv[])
{
//#if defined(Q_OS_WIN)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

    QGuiApplication app(argc, argv);
    Grille partie_de_jeu;
    QQmlApplicationEngine engine;
    
    engine.rootContext()->setContextProperty("partieDeJeu", &partie_de_jeu);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
    partie_de_jeu.translate_bas();
    partie_de_jeu.translate_droite();

}
