#include <iostream>

using namespace std;


int main(){

    cin >> option;
    
    switch(option)
    {
        case INT_TYPE_ENUM:
    { CArray<int> a;
        Insert_Elements(a);
        break;
    }
        case DOUBLE_TYPE_ENUM:
    { CArray<double> a;
        Insert_Elements(a);
        break;
        } // More cases for other types go here
    }
}