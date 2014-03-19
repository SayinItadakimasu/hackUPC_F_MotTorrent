#include <iostream>
#include <vector>
using namespace std;

void v(vector< vector<bool> >& sopa_b, vector< vector<char> > sopa, int i, int j, int a, int b, string p){
    for (int x = 0; x < p.size(); ++x){
        if (p[x] != sopa[i + a*x][j + b*x]) return;
    }
    for (int x = 0; x < p.size(); ++x){
        sopa_b[i + a*x][j + b*x] = true;
    }
}

void search(vector< vector<bool> >& sopa_b, vector< vector<char> > sopa, int m, int n, string p, int i, int j){
    if (p.size() <= m - i){
        v(sopa_b, sopa, i, j, 1, 0, p);
    }
    if (p.size() <= n - j){
        v(sopa_b, sopa, i, j, 0, 1, p);
    }
    if (p.size() <= n - j and p.size() <= m - i){
        v(sopa_b, sopa, i, j, 1, 1, p);
    }
}

int main(){
    int x, m, n;
    bool primer = true;
    while (cin >> x >> m >> n){
        vector<string> p(x);
        for (int i = 0; i < x; ++i) cin >> p[i]; // Llegir paraules a buscar
        vector< vector<char> > sopa(m, vector<char>(n)); // Matriu de lletres
        vector< vector<bool> > sopa_b(m, vector<bool>(n, false)); // Matriu de booleans
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) cin >> sopa[i][j]; // Llegir matriu de lletres
        }
        for (int k = 0; k < x; ++k){
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    if (sopa[i][j] == p[k][0]){ // Si coincideix la 1a lletra de la paraula
                        search(sopa_b, sopa, m, n, p[k], i, j);
                    }
                }
            }
        }
        if (not primer) cout << endl;
        else primer = false;
        for (int i = 0; i < m; ++i){
            bool first = true;
            for (int j = 0; j < n; ++j){
                if (not first) cout << " ";
                else first = false;
                if (sopa_b[i][j]) cout << char(sopa[i][j] - 'a' + 'A');
                else cout << sopa[i][j];
            }
            cout << endl;
        }
    }
}
