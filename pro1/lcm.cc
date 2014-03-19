#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a!=0 and b!=0){
        if (a>=b) a = a%b;
        else b = b%a;
    }
    return (a+b);
}

int lcm(int a, int b) {
    int aux = a/gcd(a,b);
    return (aux*b);
}

int main() {
    int n;
    cin >> n;
    while (n!=0) {
        int p;
        cin >> p;
        int result = p;
        for (int i = 1; i<n; i++) {
            cin >> p;
            result = lcm(result, p);
        }
        cout << result << endl;
        cin >> n;
    }
}
