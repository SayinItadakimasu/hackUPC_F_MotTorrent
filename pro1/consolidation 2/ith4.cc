#include <iostream>
using namespace std;


int main() {

    int n;
    while (cin >> n) {
        int count = 1;
        int x;
        while (cin >> x and x != -1 and count < n) {
            ++count;
        }
        if (count < n or n <= 0 or x == -1) cout << "Incorrect position." << endl;
        else cout << "At the position " << n << " there is a(n) " << x << "." << endl;
        while (x != -1) cin >> x;
    }
}
