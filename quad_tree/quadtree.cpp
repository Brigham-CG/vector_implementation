#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

template<typename D>
void print_matrix(D **matrix, int i_r, int e_r, int i_c, int e_c)
{
    for(int i = i_r; i <= e_r; i++)
    {
        for(int j = i_c; j <= e_c; j++)
            cout << "\t" << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

template<typename D> 
double standar_deviation(D **matrix, int i_r, int e_r, int i_c, int e_c)
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
void subdivide_matrix(D **matrix, int i_r, int e_r, int i_c, int e_c)
{

    print_matrix(matrix, i_r, e_r, i_c, e_c);

    double s_d = standar_deviation(matrix, i_r, e_r, i_c, e_c);

    if(!standar_deviation(matrix, i_r, e_r, i_c, e_c))
    {
        cout << "\tFinish node!\n\n";
        return;
    }

    int m_r = (i_r + e_r) / 2,
        m_c = (i_c + e_c) / 2;

    // (1,1)
    subdivide_matrix(matrix, i_r, m_r, i_c, m_c);

    // (1,2)
    subdivide_matrix(matrix, i_r, m_r, m_c + 1, e_c);

    // (2,1)
    subdivide_matrix(matrix, m_r + 1, e_r, i_c, m_c );

    // (2,2)
    subdivide_matrix(matrix, m_r + 1, e_r, m_c + 1, e_c);

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

    generate_matrix_sqrt(matrix, r, c);
    // generate_matrix_random(matrix, r, c);
    subdivide_matrix(matrix, 0, r - 1, 0, c - 1);
}