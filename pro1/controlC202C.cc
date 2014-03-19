#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    char x;
    a=0;
    b=0;
    c=0;

    cin >> n;
    while (cin >> x) {
        if (x=='a') {
            a++;
        }
        if (x=='b') {
            b++;
        }
        if (x=='c') {
            c++;
        }
    }

    if ((a>=b and a>=c)) {
       cout << "majoria de a" << endl;
       cout << a << " repeticio(ns)" << endl;
    }
    else if (b>a and b>=c) {
        cout << "majoria de b" << endl;
        cout << b << " repeticio(ns)" << endl;
    }
    else if (c>a and c>b) {
        cout << "majoria de c" << endl;
        cout << c << " repeticio(ns)" << endl;
    }
}
