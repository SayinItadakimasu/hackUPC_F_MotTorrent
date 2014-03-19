#include <iostream>

using namespace std;


int main() {

    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char k;
            cin >> k;
            k = k - '0';

            if (i == j or i+j == n-1) {
                sum += k;
            }
        }
    }
    cout << sum << endl;
}
