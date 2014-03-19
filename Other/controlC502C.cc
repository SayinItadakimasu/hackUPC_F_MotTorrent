#include <iostream>
#include <vector>
#include <string>
using namespace std;

int pes(char c) {
    int pes_car = c - 'a';
    return pes_car;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> sumes(n,0);
        vector<string> cad(n);
        int maxim = 0;
        for (int i = 0; i < n; ++i) {
            cin >> cad[i];
            int size = cad[i].size();
            int suma = 0;
            for (int j = 0; j < size; ++j) {
                suma += pes(cad[i][j]);
            }
            sumes[i] = suma;
            if (suma > maxim) maxim = suma;
        }
        bool primer = true;
        if (primer) {
            primer = false;
            cout << "----------" << endl;
        }
        for (int i = 0; i < n; ++i) {
            if (sumes[i] < maxim) cout << cad[i] << endl;
        }
        cout << "----------" << endl;
    }
}
