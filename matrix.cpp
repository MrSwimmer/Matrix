#include "matrix.h"
#include <iostream>
#include <math.h>
using namespace std;

matrix::matrix(int n, int m, float** a)
    {
        nm=n;
        mm=m;
        mas = new float*[nm];
        for(int i=0; i<nm; i++)
        {
            mas[i]=new float[mm];
        }
        for(int i=0; i<nm; i++)
        {
            for(int j=0; j<mm; j++)
            {
                mas[i][j]=a[i][j];
            }
        }
    }
matrix::matrix()
    {
        nm = 3;
        mm = 3;
        mas = new float*[nm];
        for(int i=0; i<nm; i++)
        {
            mas[i]=new float[mm];
        }
        for(int i=0; i<nm; i++)
        {
            for(int j=0; j<mm; j++)
            {
                mas[i][j]=0;
                //cout << mas[i][j] << " ";
            }
        }
    }
    matrix::matrix(int nulx, int nuly)
    {
        nm=nulx;
        mm=nuly;
        mas = new float*[nm];
        for(int i=0; i<nm; i++)
        {
            mas[i]=new float[mm];
        }
        for(int i=0; i<nm; i++)
        {
            for(int j=0; j<mm; j++)
            {
                mas[i][j]=0;
            }
        }
    }
    void matrix::printMatrix()
    {

        for(int i=0; i<nm; i++)
        {
            for(int j=0; j<mm; j++)
            {
                cout << mas[i][j] << " ";
            }
            cout << endl;
        }
    }
    matrix matrix::operator = (matrix c)https://drive.google.com/open?id=0Bzyu0-W-Tvi1UzBWS3MtaTR3ckk
    {
        nm=c.nm;
        mm=c.mm;
        for(int i=0; i<c.nm; i++)
        {
            for(int j=0; j<c.mm; j++)
            {
                mas[i][j]=c.mas[i][j];
            }
        }
        return *this;
    }
    matrix matrix::operator + (matrix c)
    {
        matrix m2(c.nm, c.mm);
        for(int i=0; i<c.nm; i++)
        {
            for(int j=0; j<c.mm; j++)
            {
                m2.mas[i][j]=this->mas[i][j]+c.mas[i][j];
            }
        }
        return m2;
    }
    matrix matrix::operator - (matrix c)
    {
        matrix m2(c.nm, c.mm);
        for(int i=0; i<c.nm; i++)
        {
            for(int j=0; j<c.mm; j++)
            {
                m2.mas[i][j]=this->mas[i][j]-c.mas[i][j];
            }
        }
        return m2;
    }
    matrix matrix::operator * (matrix c)
    {
        matrix m2(c.nm, c.mm);
        nm=c.nm;
        mm=c.mm;
        float buf=0;
        int xk=0, yk=0;
        for(int y=0; y<nm; y++)
        {
            for(int i=0; i<nm; i++)
            {
                for(int j=0; j<mm; j++)
                {
                    buf+=this->mas[i][j]*c.mas[j][y];
                }
                m2.mas[xk][yk]=buf;
                buf=0;
                yk++;
            }
            yk=0;
            xk++;
        }
        return m2;
    }
    matrix matrix::operator / (matrix c)
    {
        matrix m2(c.nm, c.mm), mr(c.nm, c.mm);
        mr=rvrsm(c);
        nm=c.nm;
        mm=c.mm;
        float buf=0;
        int xk=0, yk=0;
        for(int y=0; y<nm; y++)
        {
            for(int i=0; i<nm; i++)
            {
                for(int j=0; j<mm; j++)
                {
                    buf+=this->mas[i][j]*mr.mas[j][y];
                }
                m2.mas[xk][yk]=buf;
                buf=0;
                yk++;
            }
            yk=0;
            xk++;
        }
        return m2;
    }
    float matrix::det(matrix c)
    {
        if(c.nm==2)
        {
            return det2(c);
        }
        if(c.nm==3)
        {
            return det3(c);
        }
        if(c.nm==4)
        {
            return det4(c);
        }
        if(c.nm==5)
        {
            return det5(c);
        }
    }
    float matrix::det2(matrix c)
    {
        float buf;
        buf=c.mas[0][0]*c.mas[1][1]-c.mas[0][1]*c.mas[1][0];
        return buf;
    }
    float matrix::det3(matrix c)
    {
        float buf;
        buf=c.mas[0][0]*c.mas[1][1]*c.mas[2][2]+
        c.mas[0][1]*c.mas[1][2]*c.mas[2][0]+
        c.mas[0][2]*c.mas[1][0]*c.mas[2][1]-
        c.mas[0][2]*c.mas[1][1]*c.mas[2][0]-
        c.mas[0][1]*c.mas[1][0]*c.mas[2][2]-
        c.mas[0][0]*c.mas[1][2]*c.mas[2][1];
        return buf;
    }
    float matrix::det4(matrix c)
    {
        float buf=0;
        buf+=c.mas[0][0]*det3(newm(c, 0, 0))-c.mas[0][1]*det3(newm(c, 0, 1))+c.mas[0][2]*det3(newm(c, 0, 2))-c.mas[0][3]*det3(newm(c, 0, 3));
        return buf;
    }
    float matrix::det5(matrix c)
    {
        float buf=0;
        //cout << c.mas[0][0]*det4(newm(c, 0, 0)) << " " << c.mas[0][1]*det4(newm(c, 0, 1)) << " " << c.mas[0][2]*det4(newm(c, 0, 2)) << " " << c.mas[0][3]*det4(newm(c, 0, 3)) << " " << c.mas[0][4]*det4(newm(c, 0, 4));
        buf+=c.mas[0][0]*det4(newm(c, 0, 0))-c.mas[0][1]*det4(newm(c, 0, 1))+c.mas[0][2]*det4(newm(c, 0, 2))-c.mas[0][3]*det4(newm(c, 0, 3))+c.mas[0][4]*det4(newm(c, 0, 4));
        return buf;
    }
    matrix matrix::adjm(matrix c)
    {
        matrix m(c.nm, c.mm);
        for(int i=0; i<c.nm; i++)
        {
            for(int j=0; j<c.mm; j++)
            {
                m.mas[i][j]=pow(-1, i+j)*det(newm(c, i, j));
            }
        }
        return m;
    }
    matrix matrix::transm(matrix c)
    {
        matrix t(c.mm, c.nm);
        for(int i=0; i<c.nm; i++)
        {
            for(int j=0; j<c.mm; j++)
            {
                t.mas[j][i]=c.mas[i][j];
            }
        }
        return t;
    }
    matrix matrix::skal(matrix c, float n)
    {
        matrix sk(c.nm, c.mm);
        for(int i=0; i<c.nm; i++)
        {
            for(int j=0; j<c.mm; j++)
            {
                sk.mas[i][j]=c.mas[i][j]*n;
            }
        }
        return sk;
    }
    matrix matrix::rvrsm(matrix c)
    {
        matrix rvrs(c.nm, c.mm);
        rvrs=adjm(c);
        rvrs=transm(rvrs);
        rvrs=skal(rvrs, 1/det(c));
        return rvrs;
    }
    matrix matrix::powm(matrix c, int n)
    {
        matrix m2(c.nm, c.mm);
        for(int i=0; i<n; i++)
        {
            m2=m2+(c*c);
        }
        return m2;
    }
    matrix matrix::newm(matrix b, int elx, int ely)
    {
        matrix m2(b.nm-1,b.mm-1);
        int x=0, y=0;
        for(int i=0; i<b.nm; i++)
        {
            for(int j=0; j<b.mm; j++)
            {
                if(i!=elx&&j!=ely)
                {
                    //cout << b.mas[i][j] << " ";
                    m2.mas[x][y]=b.mas[i][j];
                    y++;
                    if(y==b.nm-1)//--
                    {
                        x++;
                        y=0;
                        //cout << endl;
                    }
                }
            }
        }
        //cout << endl;
        return m2;
    }
    /*matrix:: ~matrix()
    {
        delete [] mas;
    }*/
