#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Matrix;
void change(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

void swap(Matrix& mat, int j, int k) {
    int nrows = mat.size();
    int ncols = mat[0].size();
    for (int a = 0; a < nrows; ++a) {
        change(mat[a][j], mat[a][k]);
    }
    for (int a = 0; a < nrows; ++a) {
        for (int b = 0; b < ncols; ++b) {
            if (b == ncols -1) cout << mat[a][b];
            else cout << mat[a][b] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    Matrix mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    cout << "-----" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == m-1) cout << mat[i][j];
            else cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int j, k;
    while (cin >> j >> k) {
        cout << "-----" << endl;
        swap(mat,j,k);
    }
    cout << "-----" << endl;
}
