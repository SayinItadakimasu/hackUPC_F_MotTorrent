#include <iostream>
using namespace std;

bool is_balanced(int n) {
    int even = 0;
    int odd = 0;
    while (n > 0) {
        odd += n%10;
        n /= 10;
        even += n%10;
        n /= 10;
    }
    if (odd - even == 0) return true;
    else return false;
}


int main() {
    int n;
    cin >> n;
    cout << is_balanced(n) << endl;
}
