#include <iostream>
#include <vector>
using namespace std;

string gira(string s) {
    int last = s.size() - 1;
    int middle = s.size()/2;
    for (int i = 0; i < middle; ++i) {
        int z = s[i];
        s[i] = s[last-i];
        s[last-i] = z;
    }
    return s;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1 == s2 or s1 == gira(s2)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
