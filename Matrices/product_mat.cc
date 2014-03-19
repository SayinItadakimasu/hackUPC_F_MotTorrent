#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector< vector<int> > Matrix;

//Pre: a and b are square matrices with n*n <= 0

Matrix product(const Matrix& a, const Matrix& b) {
    int size = a.size();
    Matrix c = Matrix(size, vector<int>(size));
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
    while (i < size) {
        sum1 = a[i][0]*b[i][0];
        while (j < size) {
            sum2 = a[0][j]*b[0][j];
            ++j;
        }
        ++i;
        c[i][j] = sum1 + sum2;
    }
    return c;
}

int main() {
    int m;
    cin >> m;
    Matrix A = Matrix(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    Matrix B = Matrix(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++i) {
            cin >> B[i][j];
        }
    }
    Matrix C = product(A,B);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++i) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
