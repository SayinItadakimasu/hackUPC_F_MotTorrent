#include <iostream>
#include <cmath>
using namespace std;


int sum_digits(int n) {
    if (n < 10) return n;
    else return n%10 + sum_digits(n/10);
}

bool is_prime(int n){
    if (n <= 1) return 0;
    for (int i = 2; i*i <= n; ++i){
        if (n % i == 0) return 0;
    }
    return 1;
}


bool is_perfect_prime(int n){
    if (n < 10 and is_prime(n)) return 1;
    else if (is_prime(n)) return is_perfect_prime(sum_digits(n));
    else return 0;
}


int main() {
    int a;
    cin >> a;
    cout << is_perfect_prime(a) << endl;

}

