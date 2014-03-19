#include <iostream>
using namespace std;

int main() {

    cout.setf(ios::fixed);
    cout.precision(3);

    int a, b;
    cin >> a >> b;
    double c, d;
    c=a;
    d=b;

    if (b==0) {
        cout << "divisio per zero" << endl;
    }
    else {
        cout << c/d << " " << a/b << " " << a%b << endl;
    }


}
