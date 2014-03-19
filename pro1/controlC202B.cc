#include <iostream>
using namespace std;

int main() {

    cout.setf(ios::fixed);
    cout.precision(2);

    double n, x, suma1, suma2, quadrat, frac1, frac2, resultat;
    suma1=0;
    suma2=0;

    cin >> n;
    while (cin >> x) {

            suma1=suma1+x*x;
            suma2=suma2+x;
        }
    frac1= 1/(n-1);
    frac2= 1/(n*(n-1));
    quadrat= suma2*suma2;
    resultat= suma1*frac1-quadrat*frac2;
    cout << resultat << endl;
}
