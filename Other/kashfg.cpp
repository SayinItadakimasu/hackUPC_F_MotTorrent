#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main () {
    char c, n;
    while (cin >> c >> n) {
        int i = c - 'a';
        int j = n - '0';
        cout << i << " " << j << endl;
    }
}
