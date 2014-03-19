#include <iostream>
using namespace std;

int main() {

    int a, b;
    cin >> a >> b;
    if (a <= b) {
        while (a <= b) {
            if (a != b) cout << a << ",";
            else cout << a << endl;
            ++a;
            }
        }
    else cout << endl;
    }
