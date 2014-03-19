#include <iostream>
using namespace std;

void converge(int n, int& k, int& far) {
    if (n > far) far = n;
    while (n != 1) {
        ++k;
        if (n%2 == 0) return converge(n/2,k,far);
        else return converge(3*n + 1,k,far);
    }
}

int main() {

    int m, p, far = m;
    cin >> m >> p;
    for (int i = 1; i <= m; i++) {
        int k = 0;
        converge(i,k,far);
        if (p <= k) cout << i << endl;
    }
    cout << "The greatest reached number is " << far << "." << endl;
}
