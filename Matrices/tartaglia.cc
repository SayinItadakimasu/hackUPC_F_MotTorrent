#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Matrix;

Matrix tartaglia(int n) {
    Matrix m(n, vector<int>(n,0));
    bool first_row = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (first_row) {
                if (j == 0) m[i][j] = 1;
                else m[i][j] = 0;
                if (j == n-1) first_row = false;
            }
            else {
                if (j == 0) m[i][j] = 1;
                else m[i][j] = m[i-1][j] + m[i-1][j-1];
            }
        }
    }
    return m;
}

void print_mat(const Matrix& m, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] != 0) {
                if (j == 0) cout << m[i][j];
                else cout << " " << m[i][j];
                if (j == n-1) cout << endl;
            }
        }
        cout << endl;
    }
}


int main() {
   int n;
   while (cin >> n) {
       Matrix mat = tartaglia(n);
       print_mat(mat,n);
   }
}
