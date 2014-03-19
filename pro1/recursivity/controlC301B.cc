#include <iostream>
using namespace std;


int valencia(int n) {
    int val = 0;
    for (int i = 1; n != 0; ++i) {
        if (i%2 == 0) val = val - n%10;
        else val = val + n%10;
        n = n/10;
    }
    return val;
}


int main() {
    int n;
    cin >> n;
    int max = valencia(n);
    while (valencia(n) != 0 and cin >> n) {
        valencia(n);
        if (max < valencia(n)) max = valencia(n);
        }
    if (valencia(n) != 0) cout << "The greatest valencia is " << max << "." << endl;
    else cout << "The first balanced number is " << n << "." << endl;
}
