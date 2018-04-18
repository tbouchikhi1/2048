#ifndef GRILLE_H
#define GRILLE_H
#include <iostream>
#include <vector>
#include <QObject>

using namespace std;

class Grille : public QObject
{
  Q_OBJECT

public:
  explicit Grille(QObject *parent = 0);
    // Properties
    Q_PROPERTY(QList<QString> grille READ getGrille() NOTIFY grillechanged);
    QList<QString> getGrille();
    Q_PROPERTY(QList<QString> couleurs READ getCouleurs() NOTIFY couleurschanged);
    QList<QString> getCouleurs();
    Q_PROPERTY(QString score READ getScore() NOTIFY scorechanged);
    QString getScore();
    Q_PROPERTY(int taille READ getTaille() );
    int getTaille();
  Grille(int taille);
  ~Grille();
  int get_score();
  int get_case(int x, int y);
  void afficher_console();
  Q_INVOKABLE void translate_haut();
  Q_INVOKABLE void translate_bas();
  Q_INVOKABLE void translate_gauche();
  Q_INVOKABLE void translate_droite();
  Q_INVOKABLE bool a_gagne();
  Q_INVOKABLE bool a_perdu();
  Q_INVOKABLE void alloc_dyn_grille(int taille);
  static int taille;

signals:

  void grillechanged();
  void scorechanged();
  void couleurschanged();
  
public slots:

private:
  int m_taille;
  int m_score;
  int **m_grille;
  //QT
  QList<QString> values;
  QList<QString> colors;
  //Méthodes internes

  void initial_grille_config();
  vector<int> fusion_cases(vector<int> vecteur);
};

#endif // GRILLE_H
