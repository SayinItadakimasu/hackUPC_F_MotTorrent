#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int max = v[0], min = v[0], sum = 0;
        for (int j = 0; j < n; ++j) {
            if (max < v[j]) max = v[j];
            if (min > v[j]) min = v[j];
            sum += v[j];
        }
        if (sum / 2 == max or sum / 2 == min) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
