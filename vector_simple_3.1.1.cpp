#include <iostream>

using namespace std;

int gVect[100];
int gnCount = 0;

void insert(int elem)
{
    if (gnCount < 100)
        gVect[gnCount++] = elem;
}

int main()
{

    for (int i = 10; i > 0; i--)
        insert(i);

    for (int i = 0; i < gnCount; i++)
        cout << gVect[i] << " ";
    cout << endl;
}