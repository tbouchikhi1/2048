#include "grille.h"
#include "case.h"
#include <iostream>
#include <vector>

using namespace std;

Grille::Grille(int taille)
{
    m_taille = taille;
    m_score = 0;
    alloc_dyn_grille(m_taille);
}

Grille::~Grille()
{
    if (m_grille != NULL)
    {
        for (int i = 0; i < m_taille; i++)
        {
            delete[] m_grille[i];
        }
        delete[] m_grille;
        m_grille = NULL;
    }
}

void Grille::alloc_dyn_grille(int taille)
{
    m_grille = new int *[taille];
    for (int i = 0; i < taille; i++)
    {
        m_grille[i] = new int[taille];
    }
}

void Grille::initial_grille_config()
{
    for (int i = 0; i < m_taille; i++)
    {
        for (int j = 0; j < m_taille; j++)
        {
            m_grille[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        int j = rand() % m_taille;
        int k = rand() % m_taille;
        m_grille[j][k] = 2;
    }
}

void Grille::afficher_console()
{
    cout << endl;
    for (int x = 0; x < m_taille; x++)
    {
        for (int y = 0; y < m_taille; y++)
        {
            cout << m_grille[x][y] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
    cout << endl;
}

int Grille::get_score()
{
    return m_score;
}

int Grille::get_case(int x, int y)
{
}

void Grille::translate_bas()
{
}

void Grille::translate_haut()
{
}

void Grille::translate_droite()
{
}

void Grille::translate_gauche()
{
}
