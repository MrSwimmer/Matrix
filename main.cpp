#include <iostream>
#include <fstream>
#include <math.h>
#include "matrix.h"
using namespace std;

int main()
{
    int x, y;
    ifstream fin("file.txt");
    fin >> x >> y;
    float **s=new float*[x];
    for(int i=0; i<x; i++)
    {
        s[i]=new float[y];
    }
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            fin >> s[i][j];
        }
    }
    fin.close();
    matrix four(x, y, s);
    matrix m(5,5);
    m=four.powm(four, 2);
    //cout << four.det5(four);
    m.printMatrix();
    return 0;
}
