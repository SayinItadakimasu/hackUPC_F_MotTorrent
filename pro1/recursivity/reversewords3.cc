#include <iostream>
using namespace std;

void reverse(int a) {
    string s;
    if (cin >> s and a != 0) {
        reverse (--a);
        cout << s << endl;
    }
}


int main() {
    int a;
    cin >> a;
    reverse(a);

}

