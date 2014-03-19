#include <iostream>
using namespace std;

int gcd(int a, int b) {

    int aux = a%b;
    a=b;
    b=aux;
    if (b == 0) return a;
    else return gcd(a,b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;

}

