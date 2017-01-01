#ifndef GRILLE_H
#define GRILLE_H
#include <iostream>
#include <vector>
using namespace std;

class Grille
{
  public:
    Grille(int taille);
    ~Grille();
    int get_score();
    int get_case(int x, int y);
    void afficher_console();
    void translate_haut();
    void translate_bas();
    void translate_gauche();
    void translate_droite();

  private:
    int m_taille;
    int m_score;
    int **m_grille;
    //Méthodes internes
    void alloc_dyn_grille(int taille);
    void initial_grille_config();
};

#endif // GRILLE_H
