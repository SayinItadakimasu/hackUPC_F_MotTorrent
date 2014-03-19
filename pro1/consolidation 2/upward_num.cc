#include <iostream>
using namespace std;

bool is_upward(int n) {
    int max;
    while (n > 9) {
        max = n%10;
        if (max == 0) max = 10;
        n /= 10;
        if (n%10 != (max - 1)) return false;
    }
    return true;
}

int main() {
    int n;
    bool primer, segon;
    primer = segon = false;
    while (cin >> n and not segon) {
        if (primer and is_upward(n)) segon = true;
        else if (is_upward(n)) primer = true;
        else primer = false;
    }
    if (segon) cout << "YES" << endl;
    else cout << "NO" << endl;
}
