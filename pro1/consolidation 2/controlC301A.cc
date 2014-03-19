#include <iostream>
using namespace std;

bool is_prime(int a) {
    for (int i = 2; i*i <= a; ++i) {
        if (a%i == 0) return false;
    }
    return true;
}

bool is_powerful(int n) {
    for (int j = 2; j <= n; ++j) {
        if (n%j == 0 and n%(j*j) != 0) {
            if (is_prime(j))return false;
        }
    }
    return true;
}

int main() {

    int m;
    bool numero1 = true;
    while(cin >> m) {
        if (numero1) {
            cout << 1;
            numero1 = false;
        }
        for(int i = 2; i <= m; ++i) {
            if (is_powerful(i) == true) cout << "," << i;
        }
        numero1 = true;
        cout << endl;
    }
}
