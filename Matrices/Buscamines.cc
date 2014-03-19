#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

int new_value (Matrix& A, int i, int j) { //retorna el numero de mines al voltant d'una posició
    int count = 0;
    if (i == 0) {
        if (A[i][j-1] == -1) ++count;
        if (A[i][j+1] == -1) ++count;
        if (A[i+1][j-1] == -1) ++count;
        if (A[i+1][j] == -1) ++count;
        if (A[i+1][j+1] == -1) ++count;
    }
    else if (i == A.size()-1) {
        if (A[i-1][j-1] == -1) ++count;
        if (A[i-1][j] == -1) ++count;
        if (A[i-1][j+1] == -1) ++count;
        if (A[i][j-1] == -1) ++count;
        if (A[i][j+1] == -1) ++count;
    }
    else {
        if (A[i-1][j-1] == -1) ++count;
        if (A[i-1][j] == -1) ++count;
        if (A[i-1][j+1] == -1) ++count;
        if (A[i][j-1] == -1) ++count;
        if (A[i][j+1] == -1) ++count;
        if (A[i+1][j-1] == -1) ++count;
        if (A[i+1][j] == -1) ++count;
        if (A[i+1][j+1] == -1) ++count;
    }
    return count;
}

void search_mines(Matrix& A, int n) { //modifica la matriu
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 0) A[i][j] = new_value(A,i,j);
        }
    }
}

void print_field(const Matrix& A, int n) { //imprimeix el camp de mines finalitzat
     for (int k = 0; k < n; ++k) {
        for (int p = 0; p < n; ++p) {
            if (p == n-1) {
                if (A[k][p] >= 0) cout << '+' << A[k][p];
                else cout << A[k][p];
            }
            else {
                if (A[k][p] >= 0) cout << '+' << A[k][p] << " ";
                else cout << A[k][p] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool error (const Matrix& A, int n) { // detecta si un camp es erroni
    bool e;
    int error = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][0] == 0 or A[i][n-1] == 0) ++error;
        }
    }
    if (error > 0) e = true;
    else e = false;
    return e;
}

int main () {
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int n;
        while (cin >> n) {
            Matrix field (n,vector<int> (n)); //Matriu cuadrada
            for (int k = 0; k < n; ++k) {
                for (int j = 0; j < n; ++j) {
                    cin >> field[k][j];
                }
            }
            if (not error(field, n)) {
                search_mines(field, n);
                print_field(field, n);
            }
            else {
                cout << "reject" << endl;
                cout << endl;
            }
        }
    }
}

