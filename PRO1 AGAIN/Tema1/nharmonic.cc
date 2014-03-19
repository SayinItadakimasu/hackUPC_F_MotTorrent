#include <iostream>
using namespace std;

int main() {

    cout.setf(ios::fixed);
    cout.precision(4);

    double h, n, x;
    cin >> n;
    x=1;
    h=0;

    while (x<=n) {
        h=h+1/x;
        x=x+1;
    }

    cout << h << endl;

}

