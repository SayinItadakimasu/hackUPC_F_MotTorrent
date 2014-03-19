#include <iostream>
using namespace std;

int valencia(int n) {
    int even = 0;
    int odd = 0;
    while (n > 0) {
        odd += n%10;
        n /= 10;
        even += n%10;
        n /= 10;
    }
    return odd - even;
}


int main() {
    int n, max = 0;
    bool found = false;
    while (not found and cin >> n) {
        int x = valencia(n);
        if (x == 0) {
            cout << "The first balanced number is " << n << "." << endl;
            found = true;
        }
        else if (x < 0) x = -x;
        if (max < x) max = x;
    }
    if (not found) cout << "The greatest valencia is " << max << "." << endl;
}
