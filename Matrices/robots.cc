#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector< vector<char> > Matriucar;
typedef vector< vector<bool> > Matbool;

void moviment (Matriucar& m, Matbool A, int n, int i, int j) {
    string resultat;
    if (A[i][j] == true) cout << "no escape" << endl;
    else {
        if (m[i][j] == 'S') {
            if (i == n-1) cout << "escape" << endl;
            else {
                A[i][j] = true;
                moviment(m,A,n,i+1,j);
            }
        }
        else if (m[i][j] == 'N') {
            if (i == 0) cout << "escape" << endl;
            else {
                A[i][j] = true;
                moviment(m,A,n,i-1,j);
            }
        }
        else if (m[i][j] == 'E') {
            if (j == n-1) cout << "escape" << endl;
            else {
                A[i][j] = true;
                moviment(m,A,n,i,j+1);
            }
        }
        else if (m[i][j] == 'W') {
            if (j == 0) cout << "escape" << endl;
            else {
                A[i][j] = true;
                moviment(m,A,n,i,j-1);
            }
        }
        else if (m[i][j] == 'X') cout << "kaputt" << endl;
    }

}

int main() {
   int casos;
   cin >> casos; //num casos
   for (int k = 0; k < casos; ++k) {
       int n; //mida matriu
       cin >> n;
       int i, j; //posicio inicial
       cin >> i >> j;
       Matriucar a(n, vector<char>(n));
       Matbool b(n, vector<bool>(n,0));
       for (int m = 0; m < n; ++m) {
           for (int p = 0; p < n; ++p) cin >> a[m][p];
       }
       moviment(a,b,n,i,j);
   }
}
