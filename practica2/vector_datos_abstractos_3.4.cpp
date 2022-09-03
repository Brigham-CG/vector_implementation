#include <iostream>

using namespace std;

template <class Type>
class CVector
{
    private:
        Type *m_pVect, 
        m_nCount, 
        m_nMax, 
        m_nDelta; 
        void init(int delta);
        void resize(); 
    public:
        CVector(int delta = 10);
        void insert(int elem);

};

template <class Type>
void CVector<Type>::resize()
{
    cout << "resizing...\n";
    Type *gVectTemp = new int [m_nMax + m_nDelta];

    for (int i = 0; i < m_nMax; i++)
        gVectTemp[i] = m_pVect[i];
        
    m_nMax+=m_nDelta;

    delete [] m_pVect;
    m_pVect = gVectTemp;
}

template <class Type>
void CVector<Type>::insert(int elem)
{
    if( m_nCount == m_nMax )
        resize(); 
    m_pVect[m_nCount++] = elem;
}

template <class Type>
CVector<Type>::CVector(int delta)
{
    m_pVect = new Type[delta], 
    m_nCount = 0, 
    m_nMax = 0, 
    m_nDelta = delta; 
}

int main()
{
    CVector<int> Vect(10);
   
    for (int i = 21; i > 0; i--)
        Vect.insert(i);

}