#include <iostream>
using namespace std;

double factorial(double n) {
    if (n == 0) return 1;
    else return n * factorial(n-1);
}

double taylor(double n) {
    cout.setf(ios::fixed);
    cout.precision(10);

    double result = 0;
    for (int i = 0; i < n; ++i) {
        result = result + 1/(factorial(i));
    }
    return result;
}

int main() {

    int n;
    while (cin >> n) {
       cout << "With " << n << " term(s) we get " << taylor(n) << "." << endl;
    }
}
