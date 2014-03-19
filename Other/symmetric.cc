#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector< vector<int> > Matrix;

//Pre: m is a square matrix with n*n <= 0

bool is_symmetric(const Matrix& m) {
    int nrows = m.size();
    bool e = true;
    int i = 0;
    while (e and i < nrows) {
        for (int j = 0; j < nrows; ++j) {
            if (m[i][j] != m[j][i]) e = false;
        }
        ++i;
    }
    return e;
}

int main() {
    int m;
    cin >> m;
    Matrix matrix = Matrix(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << is_symmetric(matrix) << endl;

}
