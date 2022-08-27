#include <iostream>

using namespace std;

void resize(
    int *&m_pVect,    
    int m_nCount,
    int &m_nMax,
    int m_nDelta
 )
{
    cout << "resizing...\n";
    int *gVectTemp = new int [m_nMax + m_nDelta];

    for (int i = 0; i < m_nMax; i++)
        gVectTemp[i] = m_pVect[i];
        
    m_nMax+=m_nDelta;

    delete [] m_pVect;
    m_pVect = gVectTemp;
}

void insert(
    int elem,
    int *&m_pVect,    
    int &m_nCount,
    int &m_nMax,
    int m_nDelta)
{
    if (m_nCount == m_nMax)
        resize(
        m_pVect,    
        m_nCount,
        m_nMax,
        m_nDelta);
    m_pVect[m_nCount++] = elem;
}

struct Vector
{
    int *m_pVect,    
    m_nCount = 0,
    m_nMax = 0,
    m_nDelta = 0;
};

int main()
{

    Vector Vect;
    Vect.m_pVect = new int [0];
    Vect.m_nDelta = 10;
   
    for (int i = 21; i > 0; i--)
        insert(i, Vect.m_pVect, Vect.m_nCount,Vect.m_nMax, Vect.m_nDelta);

    for (int i = 0; i < Vect.m_nCount; i++)
        cout << Vect.m_pVect[i] << " ";
    cout << endl;
    
}