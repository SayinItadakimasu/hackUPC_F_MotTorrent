#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Matriu;

Matriu llegir_matriu(Matriu& m) { // Llegeix una matriu quadrada
    int a = m.size();
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j) {
            cin >> m[i][j];
        }
    }
    return m;
}

void es_ok (const Matriu& A) { // Comprova si la matriu és univariada
    int a = A.size();
    int imax = 0;
    int imin = a;
    int jmax = 0;
    int jmin = a;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j) {
            if (A[i][j] == 0) {
                if (imax < i) imax = i;
                if (jmax < j) jmax = j;
            }
        }
    }

    for (int k = a-1; k != 0; --k) {
        for (int p = a-1; p != 0; --p) {
            if (A[k][p] == 0) {
                if (imin > k) imin = k;
                if (jmin > p) jmin = p;
            }
        }
    }
    bool result = true;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j) {
            if (A[i][j] == 0) {
                if (imin > i and i > imax and jmin > j and j > jmax) {
                    result = false;
                    i = a;
                    j = a;
                }
            }
        }
    }
    return result;
    //cout << imin << " " << imax << " " << jmin << " " << jmax << endl;
}

int main () {
    int m;
    cin >> m;
    for (int k = 0; k < m; ++k) {
        int n;
        cin >> n;
        Matriu a(n, vector<int>(n));
        llegir_matriu(a);
        es_ok(a);
        //if (es_ok(a)) cout << "ok" << endl;
        //else cout << "ko" << endl;
    }
}
