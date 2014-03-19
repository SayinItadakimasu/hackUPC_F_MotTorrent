#include <iostream>
#include <vector>

using namespace std;

bool contains(string s1, string s2) {

    int m = s1.size();
    int n = s2.size();
    int i = 0;
    int j = 0;

    while (i + n <= m and j < n) {
            if (s2[j] == s1[i + j]) ++j;
            else {
                j = 0;
                ++i;
            }
        }
        return j == n;
}

int main () {
    int casos;
    cin >> casos;
    vector<string> paraules(casos);
    for (int i = 0; i < casos; ++i) cin >> paraules[i];
    for (int k = 0; k < casos; ++k) {
        cout << paraules[k] << ":";
        for (int j = 0; j < casos; ++j) {
           if (contains(paraules[k],paraules[j])) cout << " " << paraules[j];
        }
        cout << endl;
    }
}
