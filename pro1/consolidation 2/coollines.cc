#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    bool cool = false, not_cool = false;
    while (cin >> n and not (cool and not_cool)) {
        string first, middle, word;
        cin >> first;
        for (int i = 2; i <= n; ++i) {
            cin >> word;
            if (i == n/2 + 1) middle = word;
        }
        if ((first == middle and first == word) and (n%2 != 0 )) cool = true;
        else not_cool = true;
    }
    if (cool and not_cool) cout << "both types" << endl;
    if (cool and not not_cool) cout << "all cool" << endl;
    if (not cool and not_cool) cout << "none cool" << endl;
}
