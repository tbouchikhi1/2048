#include "case.h"

Case::Case(int x, int y, int val)
{
    m_abs = x;
    m_ord = y;
    m_value = val;
}

int Case::get_value(){
    return m_value;
}

void Case::set_value(int val){
    m_value = val;
}
