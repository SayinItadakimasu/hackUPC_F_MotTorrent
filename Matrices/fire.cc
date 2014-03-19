#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matrix;

void fire(Matrix& A, int i, int j) {
    A[i][j] = '.';
    int n = A.size();
    int m = A[0].size();
    if (i+1 < n and A[i+1][j] == 'A') fire(A, i+1, j);
    if (i > 0 and A[i-1][j] == 'A') fire(A, i-1, j);
    if (j+1 < m and A[i][j+1] == 'A') fire(A, i, j+1);
    if (j > 0 and A[i][j-1] == 'A') fire(A, i, j-1);
}

void print_forest(const Matrix& A, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        Matrix forest (n,vector<char> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> forest[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (forest[i][j] == 'F') fire(forest, i, j);
            }
        }
        print_forest(forest, n, m);
    }
}
