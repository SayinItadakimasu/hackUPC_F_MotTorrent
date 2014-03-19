#include <iostream>
using namespace std;

bool is_friend(int n, int m) {
    if (n == m) return false;
    else {
        int sum_n = 0;
        for (int i = 1; 2*i <= n; ++i) {
            if (n%i == 0) sum_n += i;
        }
        int sum_m = 0;
        for (int i = 1; 2*i <= m; ++i) {
            if (m%i == 0) sum_m += i;
        }

        if (sum_n == m and sum_m == n) return true;
        else return false;
    }
}

int main() {
    int f, s;
    if (cin >> f >> s) {
        while (not is_friend(f,s)) {
            cin >> f >> s;
        }
        cout << "(" << f << " " << s << ")";
        int n, m;
        while (cin >> n >> m) {
            if (is_friend(n,m)) cout << ",(" << n << " " << m << ")";
        }
        cout << endl;
    }
    else cout << endl;
}
