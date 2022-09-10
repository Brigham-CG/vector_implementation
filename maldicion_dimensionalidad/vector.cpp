#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

void completar_aleatorio(vector<vector<int>> points)
{
    for(int i = 0; i < points.size(); i++)
        for(int j = 0; j < points[i].size(); j++)
        
            points[i][j] = rand() % 100;
}

void calcular_distancia(vector<int> point, vector<vector<int>> points)
{
    for(int i = 0; i < points.size(); i++)
    {
        long res = 0;
        for(int j = 0; j < points[i].size(); j++)
            res += pow(point[j] - points[i][j], 2);
        sqrt(res);
    }
}

int main()
{

    srand(time(0));
    int n_d[] = {1000, 10000, 50000};
    
    std::chrono::duration<double>  times[3];


    for(int j = 0; j < 3; j++){

        // punto a1, a2, a3, ..., an
        vector<int> point(n_d[j]);

        for(int i = 0; i < n_d[j]; i++)
            point[i] = rand() % 100;
        
        // puntos a relacionar
        vector<vector<int>> points;

        for (int i = 0; i < 100; i++)
        {
            vector<int> points_alt(n_d[j]);
            points.push_back(points_alt); 
        }
       
        completar_aleatorio(points);

        // inicio del calculo
        auto start = chrono::high_resolution_clock::now();
        
        calcular_distancia(point, points);

        auto final = chrono::high_resolution_clock::now();
        times[j] = final - start;
        
    }
    
    for(int j = 0; j < 3; j++)
        cout << n_d[j] << " : " << fixed << times[j].count() << "s\n";

}