#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
class matrix
{
private:
    int nm, mm;
    float **mas;
public:
    matrix(int n, int m, float** a);
    matrix();
    matrix(int nulx, int nuly);
    void printMatrix();
    matrix operator = (matrix c);
    matrix operator + (matrix c);
    matrix operator - (matrix c);
    matrix operator * (matrix c);
    matrix operator / (matrix c);
    float det(matrix c);
    float det2(matrix c);
    float det3(matrix c);
    float det4(matrix c);
    float det5(matrix c);
    matrix adjm(matrix c);
    matrix transm(matrix c);
    matrix skal(matrix c, float n);
    matrix rvrsm(matrix c);
    matrix powm(matrix c, int n);
    matrix newm(matrix b, int elx, int ely);
    //~matrix();
};
#endif // MATRIX_H_INCLUDED
