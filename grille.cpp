#include "grille.h"
#include "case.h"
using namespace std;

Grille::Grille(int taille)
{
    m_taille = taille;
    m_cases = vector<vector<Case>> ();
    m_score = 0;
    for (int i = 0; i < m_taille; i++){
        m_cases.push_back(vector<Case>());
        for (int j = 0; j < m_taille; j++){
            m_cases[i].push_back(Case(i,j));
        }
    }
}

int Grille::get_score(){
    return m_score;
}

Case Grille::get_case(int x, int y){
    return this->m_cases[x][y];
}

void Grille::translate_bas(){

}

void Grille::translate_haut(){

}

void Grille::translate_droite(){

}

void Grille::translate_gauche(){

}
