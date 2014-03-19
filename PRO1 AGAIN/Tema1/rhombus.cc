#include <iostream>

using namespace std;


int main() {

    int n;
    cin >> n;
    if (n == 1) cout << "*" << endl;
    else {
        int nstar = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 2; j <= (n-i); ++j) {
                cout << " ";
            }
            for (int k = 0; k < nstar; ++k) {
                cout << "*";
            }
            cout << endl;
            nstar = nstar+2;
        }
        nstar = nstar-2;
        for (int a = n-1; a != 0; --a) {
            nstar = nstar-2;
            for (int b = 1; b <= (n-a); ++b) {
                cout << " ";
            }
            for (int c = 0; c < nstar; ++c) {
                cout << "*";
            }
            cout << endl;

        }
    }
}
