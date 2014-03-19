#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector <vector <char> > Matrix;

void llegeix (Matrix& m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) cin >> m[i][j];
    }
}

bool enfonsat (Matrix& m, int x, int y)  {
    //mirar a la esquerra
    bool esq = true;
    bool found = false;
    for (int i = y; i >= 0 and esq and not found; --i) {
        if (m[x][i] == 'V') esq = false;
        else if (m[x][i] == '.') found = true;
    }
    //mirar dreta
    bool dr = true;
    found = false;
    for (int i = y; i < m[0].size() and dr and not found; ++i) {
        if (m[x][i] == 'V') dr = false;
        else if (m[x][i] == '.') found = true;
    }
    if (esq and dr) return true;
    return false;
}

void recullir (Matrix& m, int x, int y) {
    //mirar esqe
    bool found = false;
    for (int i = y; i >= 0 and not found; --i) {
        if (m[x][i] == 'T') m[x][i] = 'R';
        else if (m[x][i] == '.') found = true;
    }
    //mirar dreta
    found = false;
    for (int i = y; i < m[0].size() and not found; ++i) {
        if (m[x][i] == 'T') m[x][i] = 'R';
        else if (m[x][i] == '.') found = true;
    }
}

void tocat (Matrix& m, int x, int y, char c) {
    if (m[x][y] == '.' or m[x][y] == 'R') cout << c << y << ": aigua" << endl;
    else if (m[x][y] == 'T') cout << c << y << ": tocat" << endl;
    else if (m[x][y] == 'V') {
        m[x][y] = 'T';
        if (enfonsat(m, x, y)) {
            cout << c << y << ": enfonsat" << endl;
            recullir(m, x, y);
        }
        else cout << c << y << ": tocat" << endl;
    }
}

void traduir (Matrix& m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            if (m[i][j] == 'R') m[i][j] = '.';
        }
    }
}

void imprimeix (Matrix& m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    Matrix mat(x, vector<char> (y));
    llegeix (mat);
    char c;
    int cord;
    while (cin >> c >> cord) {
        int num = c - 'a';
        tocat (mat, num, cord, c);
    }
    cout << endl;
    traduir (mat);
    imprimeix (mat);

}

