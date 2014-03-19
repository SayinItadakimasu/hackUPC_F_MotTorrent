#include <iostream>
using namespace std;

int main() {
    int n, x, y = 0;
    while (cin >> n) {
        for (int i0=1; i0<=n; i0++) {
            y = y+i0;
        }
        for (int i1=1; i1<n; i1++) {
            cin >> x;
            y = y-x;
        }
        cout << y << endl;
        y = 0;
    }
}
