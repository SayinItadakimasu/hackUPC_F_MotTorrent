#include <iostream>
using namespace std;

int main() {

    int n, suma, c, x;
    cin >> n;
    suma=0;
    x=0;
    while (x<3) {
        c=n%10;
        suma=suma+c;
        n=n/10;
        x=x+1;
    }
    cout << suma << endl;

}
