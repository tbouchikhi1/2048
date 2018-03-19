#ifndef CASE_H
#define CASE_H


class Case
{
public:
    Case(int x, int y, int value = 2);
    int get_value();
    void set_value(int val);

private:
    int m_abs; // abscisse
    int m_ord; // ordonnée
    int m_value; // valeur de la case
};

#endif // CASE_H
