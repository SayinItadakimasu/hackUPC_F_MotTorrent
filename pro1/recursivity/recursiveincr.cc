#include <iostream>
using namespace std;

bool is_increasing(int n) {
    int previous = n%10, next = ((n%100)/10);
    n=n/10;
    if (n == 0) return 1;
    if (previous >= next) return is_increasing(n);
    else return 0;

}

int main() {
    int a;
    cin >> a;
    cout << is_increasing(a) << endl;

}

