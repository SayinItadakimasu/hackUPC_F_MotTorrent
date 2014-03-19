#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Persona {
    string nom;
    bool dona;
    int edat;
};

void read (Persona& p) {
    string sexe;
    cin >> p.nom >> sexe >> p.edat;
    p.dona = sexe == "dona";
}

int main() {
    int n;
    int max = 0;
    cin >> n;
    vector<Persona> gent(n);
    for (int i = 0; i < n; ++i){
        read(gent[i]);
        if (not gent[i].dona and gent[i].edat > max) max = gent[i].edat;
    }
    for (int i = 0; i < n; ++i){
        if (gent[i].dona and gent[i].edat < max){
            cout << gent[i].nom << " " << gent[i].edat << endl;
        }
    }
}
