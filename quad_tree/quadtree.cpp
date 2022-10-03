#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <utility>

using namespace std;

template<typename D>
struct Node
{

    D data;
    pair<int, int> r;
    pair<int, int> c;
    Node<D> *childrens[4];
    bool is_leaf;

    Node(D data, pair<int, int> r, pair<int, int> c)
    {
        // leaf
        this->data = data;
        this->r = r;
        this->c = c;
        this->is_leaf = 1;
        childrens[0] = nullptr;
        childrens[1] = nullptr;
        childrens[2] = nullptr;
        childrens[3] = nullptr;
    }

    Node(pair<int, int> r, pair<int, int> c)
    {
        // not leaf
        this->r = r;
        this->c = c;
        this->is_leaf = 0;
        childrens[0] = nullptr;
        childrens[1] = nullptr;
        childrens[2] = nullptr;
        childrens[3] = nullptr;
    }
};

template<typename D>
class Quadtree
{
    int r;
    int c;

    Node<D>* root;

    double standar_deviation(D **matrix, int i_r, int e_r, int i_c, int e_c);
    void subdivide_matrix(Node<D> **node, D **matrix, int i_r, int e_r, int i_c, int e_c);
    void print_matrix(D **matrix, int i_r, int e_r, int i_c, int e_c);

    public:
        Quadtree(D **matrix, int r, int c);
};

template<typename D>
Quadtree<D>::Quadtree(D **matrix, int r, int c)
{
    this->r = r;
    this->c = c;

    subdivide_matrix(&root, matrix, 0, r - 1, 0, c - 1);
}

template<typename D>
void Quadtree<D>::print_matrix(D **matrix, int i_r, int e_r, int i_c, int e_c)
{

    cout << "\n";
    for(int i = i_r; i <= e_r; i++)
    {
        for(int j = i_c; j <= e_c; j++)
            cout << "\t" << matrix[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

template<typename D> 
double Quadtree<D>::standar_deviation(D **matrix, int i_r, int e_r, int i_c, int e_c)
{
    //formule
    
    double avg = 0,
        size = (e_r - i_r + 1) * (e_c - i_c + 1); 

    if (size == 1)
        return 0;

    for(int i = i_r; i <= e_r; i++)
        for(int j = i_c; j <= e_c; j++)
            avg += matrix[i][j];
    
    avg /= size;

    double d_s = 0;

    for(int i = i_r; i <= e_r; i++)
        for(int j = i_c; j <= e_c; j++)
            d_s += pow(matrix[i][j] - avg, 2);

    return sqrt(d_s / (size - 1));
}

template<typename D>
void Quadtree<D>::subdivide_matrix(Node<D> **node, D **matrix, int i_r, int e_r, int i_c, int e_c)
{
    if (i_r > e_r || i_c > e_c)
        return;

    print_matrix(matrix, i_r, e_r, i_c, e_c);

    if(!standar_deviation(matrix, i_r, e_r, i_c, e_c))
    {  
        //leaf
        *node = new Node<D>(matrix[i_r][i_c], {i_r, e_r}, {i_c, e_c});
        cout << "\tFinish node!\n\n";
        return;
    }

    // not leaf
    *node = new Node<D>({i_r, e_r}, {i_c, e_c});

    int m_r = (i_r + e_r) / 2,
        m_c = (i_c + e_c) / 2;

    //(1,1)
    subdivide_matrix(&((*node)->childrens[0]),matrix, i_r, m_r, i_c, m_c);

    // (1,2)
    subdivide_matrix(&((*node)->childrens[1]), matrix, i_r, m_r, m_c + 1, e_c);

    // (2,1)
    subdivide_matrix(&((*node)->childrens[2]), matrix, m_r + 1, e_r, i_c, m_c );

    // (2,2)
    subdivide_matrix(&((*node)->childrens[3]), matrix, m_r + 1, e_r, m_c + 1, e_c);
}

template<typename D>
void generate_matrix_sqrt(D **&matrix, int r, int c)
{
    matrix = new int * [r];

    for(int i = 0; i < r; i++)
    {
        matrix[i] = new int [c];
        for(int j = 0; j < c; j++)
        {
            if(i < r / 2 && j < c / 2) // 1 1
                matrix [i][j] = 1;
            if(i >= r / 2 && j < c / 2) //  1 2
                matrix [i][j] = 2;
            if(i < r / 2 && j >= c / 2) // 2 1
                matrix [i][j] = 3;
            if(i >= r / 2 && j >= c / 2) // 2 2
                matrix [i][j] = 4;
        }
    }
}

template<typename D>
void generate_matrix_random(D **&matrix, int r, int c)
{

    srand(time(0));
    matrix = new int * [r];

    for(int i = 0; i < r; i++)
    {
        matrix[i] = new int [10];
        for(int j = 0; j < c; j++)
            matrix[i][j] = rand() % (r + c);
    }

}

int main()
{
 
    int **matrix;

    int r = 10, c = 10;

    // generate_matrix_sqrt(matrix, r, c); // matrix square (four elements)
    generate_matrix_random(matrix, r, c); // matrix with random elements [0, r + c]

    Quadtree<int> q(matrix, r, c);
}   
