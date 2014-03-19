#include <iostream>
using namespace std;

int sum_divisors(int n) {
    int sum = 0;
    for (int i = 1; 2*i <= n; ++i) {
        if (n%i == 0) sum = sum + i;
    }
    return sum;
}

int main() {
    int n, popiropis;
    while (cin >> n){
        popiropis = sum_divisors(n-2) + sum_divisors(n) + sum_divisors(n+2);
        if (popiropis == n) cout << n << ": popiropis" << endl;
        else if (popiropis % n == 0) cout << n << ": " << popiropis/n << "-popiropis" << endl;
        else cout << n << ": nothing" << endl;
    }
}
