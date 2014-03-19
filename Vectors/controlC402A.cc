#include <iostream>
#include <vector>
using namespace std;

int posicions_iguals(string s1, string s2) {
    int a = s1.size();
    int b = s2.size();
    int count = 0;

    int least_size;
    if (a > b) least_size = b;
    else least_size = a;

    for (int i = 0; i < least_size; ++i) {
        if (s1[i] == s2[i]) ++count;
    }
    return count;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << posicions_iguals(s1, s2) << endl;
    }

}
