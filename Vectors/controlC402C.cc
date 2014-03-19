#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int x;
    cin >> x;

    vector<int> V1(x); //llegim el primer vector
    for (int i = 0; i < x; ++i) cin >> V1[i];

    vector<int> Aux(x); //el nou vector tindrà a la posició y del segon vector el número corresponent del primer vector
    for (int k = 0; k < x; ++k) {
        int y;
        cin >> y;
        Aux[y] = V1[k];
    }

    for(int y = 0; y < x -1; ++y) cout << Aux[y] << " "; //imprimim el vector
    cout << Aux[x-1] << endl;
}
