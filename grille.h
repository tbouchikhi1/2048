#ifndef GRILLE_H
#define GRILLE_H
#include "case.h"
#include <vector>
using namespace std;

class Grille
{
    public:
        Grille(int taille);
        int get_score();
        Case get_case(int x, int y);
        void translate_haut();
        void translate_bas();
        void translate_gauche();
        void translate_droite();


    private:
        int m_taille;
        int m_score;
        vector<vector<Case>> m_cases;
};

#endif // GRILLE_H
