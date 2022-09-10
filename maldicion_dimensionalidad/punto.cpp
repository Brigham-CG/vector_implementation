#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <math.h>

using namespace std;

void completar_aleatorio(int **array, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
        
            array[i][j] = rand() % 100;
}


void calcular_distancia(int x, int y, int z, int **array, int n)
{
    
    for(int i = 0; i < n; i++)
        sqrt(pow((x - array[i][0]), 2) + pow((y - array[i][1]), 2) + pow((y - array[i][2]), 2));

}

int main()
{

    srand(time(0));
    int dim = 3;
    int n_p[] = {1000, 10000, 50000};
    
    std::chrono::duration<float,std::milli> times[3];

    for(int j = 0; j < 3; j++){

        int **points;
        points = new int*[n_p[j]];

        int x = rand() % 100;
        int y = rand() % 100;
        int z = rand() % 100;

        for (int i = 0; i < n_p[j]; i++)
            points[i] = new int [3];


        completar_aleatorio(points, n_p[j]);
        auto start = chrono::system_clock::now();
        
        calcular_distancia(x, y, z, points, n_p[j]);

        auto final = chrono::system_clock::now();
        times[j] = final - start;

    }
    
    for(int j = 0; j < 3; j++)
        cout << n_p[j] << " : " <<times[j].count() << "s\n";

}