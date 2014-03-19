#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Matrix;

int sum_diagonals(const Matrix& mat) {
    int size = mat.size();
    int sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
    while (i < size and j < size) {
        sum1 += mat[i][j];
        if (size%2 != 0 and i+j == size-1) sum1 -= mat[i][j]; // we don't have to add the number shared by the two diagonals
        ++i;
        ++j;        
    }
    int k = 0, m = size-1;
    while (k < size and m >= 0) {
        sum2 += mat[k][m];
        --m;
        ++k;
    }

    return sum1 + sum2;
}


int main() {
    int m, n;
    while (cin >> m) {
        if (m == 1) {
            cin >> n;
            cout << n << endl;
        }
        else {
            Matrix A = Matrix(m, vector<int>(m));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    cin >> A[i][j];
                }
            }
            cout << sum_diagonals(A) << endl;
        }
    }
}
