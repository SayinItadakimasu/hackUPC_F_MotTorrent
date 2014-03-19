#include <iostream>
using namespace std;

int main() {
    int a, b, x, suma;


    while (cin >> a >> b) {
        cout << "suma dels cubs entre " << a << " i " << b << ": ";
        suma=0;
        if (b-a<0) {
            cout << '0' << endl;
           }
        else {
            for (x=a; x<=b; x++) {
            suma=suma+x*x*x;
           }
             cout << suma << endl;
           }
       }
}
