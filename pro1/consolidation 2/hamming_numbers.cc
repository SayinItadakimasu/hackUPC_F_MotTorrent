#include <iostream>
using namespace std;

bool is_hamming(int n) {
    while (n != 1) {
        if (n%2 == 0) return is_hamming(n/2);
        else if (n%3 == 0) return is_hamming(n/3);
        else if (n%5 == 0) return is_hamming(n/5);
        else return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) cout << endl;
        else {
            cout << 1;
            int i = 1, j = 1;
            while (j != n) {
                ++i;
                if (is_hamming(i)) {
                    cout << "," << i;
                    ++j;
                }
            }
            cout << endl;
        }
    }
}
