#include <iostream>
#include <vector>

using namespace std;

class CMyComplexDataStructure
{
    vector<float> m_container;
    public:
    void Insert(float fVal) {
         m_container.push_back(fVal);
    }

    template <typename objclass>
    void sumone(objclass funobj)
    {
        vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end() ; iter++)
        funobj(*iter);
    }   
};

template <typename objclass>
class funcobjclass
{
    public:
    void operator ()(objclass& objinstance)
    {
        objinstance++;
    }
};


template <typename T> struct NODE
{
    T m_data; // The data goes here
    struct NODE<T> *m_pNext; // Pointer to the next node
    static long id; // Node id
    NODE() // Constructor
    : m_data(0), m_pNext(NULL) {}
    
};

template <typename T>
long NODE<T>::id = 0; // Inicialization of the node’s id

template <typename T> class CLinkedList
{
    private:
    NODE<T> *m_pRoot; // Pointer to the root
    public:
};

template <typename T> class CLinkedList2
{
    private:
    struct NODE
    {
        T m_data; 
        struct NODE * m_pNext; 
    };
    NODE* m_pRoot; 
    public: 
};

template <typename T>
class CBinaryTree
{
    private: 
    struct NODE
    {
        T m_data; 
        struct NODE *m_pLeft, *m_pRight;
        
    };

    NODE* m_pRoot;
    public: 
};

int main(int argc, char* argv[])
{
    CMyComplexDataStructure ds;
    ds.Insert(3.5);
    ds.Insert(4.5);
    ds.Insert(6.5);
    ds.Insert(3.9);
    funcobjclass<float> x;
    ds.sumone(x);
    return 0;
}