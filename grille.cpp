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
    initial_grille_config();
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
    afficher_console();
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
    return m_grille[x][y];
}

vector<int> Grille::fusion_cases(vector<int> vecteur){
    int taille = vecteur.size();
    vector<int> vect1(taille), vect2(taille);
    int j = 0;
    // Recopie des éléments non nuls de vecteur dans vect2
    //si vect = [2,0,0,4] alors vect1 = [2,4,NULL,NULL]
    for (int i=0; i < taille; i++){
        if (vecteur[i] != 0){
            vect1[j] = vecteur[i];
            j++;
        }
    }
    // Fusion des cases identiques 2 par 2 et recopie dans vect2
    // gestion du score 
    j = 0;
    for (int i = 1; i<taille; i++){
        if (vect1[i-1]==vect1[i]){
            vect2[j]=2*vect1[i-1];
            m_score += vect2[j];
            //Verification qu'on ne vient pas de fusionner deux cases nulles
            if (vect2[j] != 0){
                j++;
            }
        }

        
        //Si elements non identiques : recopie un à un 
        else{
            vect2[j] = vect1[i-1];
            j++;
        }
    }
    //gestion du dernier élement non géré par la boucle
    if (vect1[taille - 1] != 0){
        vect2[j] = vect1[taille -1];
        j++;
    }
    //Remplissage de 0 dans les autres cases
    for (int i = j; i<taille; i++){
        vect2[i] = 0;
    }
    return vect2;
}

void Grille::translate_bas()
{
    vector<int> vect1(m_taille), vect2(m_taille);
    for(int i=0; i<m_taille; i++){
        for(int j =0; j<m_taille; j++){
            vect1[m_taille - 1 - j] = m_grille[j][i];
            
        }
        cout<<"vect1"<<vect1[0]<<endl;
        cout<<"vect1"<<vect1[1]<<endl;
        cout<<"vect1"<<vect1[2]<<endl;
        cout<<"vect1"<<vect1[3]<<endl;
        vect2 = fusion_cases(vect1);
        cout<<"vect2"<<vect2[0]<<endl;
        cout<<"vect2"<<vect2[1]<<endl;
        cout<<"vect2"<<vect2[2]<<endl;
        cout<<"vect2"<<vect2[3]<<endl;
        for(int j = 0; j< m_taille; j ++){
            m_grille[j][i] = vect2[m_taille -1 -j];
        }
    }
    int i = rand()%m_taille;
    int j = rand()%m_taille;
    while(m_grille[i][j] != 0){
        int i = rand()%m_taille;
        int j = rand()%m_taille;
    }
    m_grille[i][j] = 2;
    afficher_console();
}

void Grille::translate_haut()
{
    vector<int> vect1(m_taille), vect2(m_taille);
    for(int i=0; i<m_taille; i++){
        for(int j =0; j<m_taille; j++){
            vect1[j] = m_grille[j][i];
        }
        vect2 = fusion_cases(vect1);
        for(int j = 0; j< m_taille; j ++){
            m_grille[j][i] = vect2[j];
        }
    }
    int i = rand()%m_taille;
    int j = rand()%m_taille;
    while(m_grille[i][j] != 0){
        int i = rand()%m_taille;
        int j = rand()%m_taille;
    }
    m_grille[i][j] = 2;
    afficher_console();
}

void Grille::translate_droite()
{
    vector<int> vect1(m_taille), vect2(m_taille);
    for(int i=0; i<m_taille; i++){
        for(int j =0; j<m_taille; j++){
            vect1[m_taille - 1 - j] = m_grille[i][j];
        }
        vect2 = fusion_cases(vect1);
        for(int j = 0; j< m_taille; j ++){
            m_grille[i][j] = vect2[m_taille -1 -j];
        }
    }
    int i = rand()%m_taille;
    int j = rand()%m_taille;
    while(m_grille[i][j] != 0){
        int i = rand()%m_taille;
        int j = rand()%m_taille;
    }
    m_grille[i][j] = 2;
    afficher_console();
}

void Grille::translate_gauche()
{
    vector<int> vect1(m_taille), vect2(m_taille);
    for(int i=0; i<m_taille; i++){
        for(int j =0; j<m_taille; j++){
            vect1[j] = m_grille[i][j];
        }
        vect2 = fusion_cases(vect1);
        for(int j = 0; j< m_taille; j ++){
            m_grille[i][j] = vect2[j];
        }
    }
    int i = rand()%m_taille;
    int j = rand()%m_taille;
    while(m_grille[i][j] != 0){
        int i = rand()%m_taille;
        int j = rand()%m_taille;
    }
    m_grille[i][j] = 2;
    afficher_console();
}
