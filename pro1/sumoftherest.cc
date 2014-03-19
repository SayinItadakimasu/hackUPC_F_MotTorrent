#include <iostream>
using namespace std;

int main() {
    int n, m;
    while (cin >> m) {
        int sum, max;
        sum = max = 0;
        for (int i = m; i > 0; i--) {
            cin >> n;
            if (max < n) max = n;
            sum += n;
        }
        if (sum-max == max) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
