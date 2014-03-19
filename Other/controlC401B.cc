#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

void min_max(const Matriu& mat, int& minim, int& maxim) {
    //Pre: matriu no buida
    //minim = valor minim de la matriu
    //maxim = valor maxim de la matriu

    maxim = minim = mat[0][0];

    for(int i = 0; i < mat.size(); ++i){
        for(int j = 0; j < mat[0].size(); ++j){
            if(mat[i][j] > maxim) maxim = mat[i][j];
            else if (mat[i][j] < minim) minim = mat[i][j];
        }
    }
}

int main(){
    int n, m, matriu;
    matriu = 1;
    int diferencia = 0;
    int count = 1;
    while (cin >> n >> m) {
        Matriu mat(n, vector<int>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }
        int maxim, minim;
        min_max(mat, minim, maxim);
        int resta = maxim-minim;
        if(resta > diferencia) {
            diferencia = resta;
            matriu = count;
        }
        ++count;
    }
    cout << "la diferencia maxima es " << diferencia << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << matriu << endl;
}
