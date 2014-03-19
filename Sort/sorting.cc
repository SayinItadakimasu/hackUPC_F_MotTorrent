#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool decreasing(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<int> u(n);
    for (int i = 0; i < n; ++i) u[i] = v[i];

    sort (v.begin(),v.end(),decreasing);
    for (int i = 0; i < n; ++i) cout << v[i] << " ";
    cout << endl;
}
