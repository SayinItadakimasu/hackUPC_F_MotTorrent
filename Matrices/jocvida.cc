#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool parar();

void propagacio(string& s, int k) {
    int n = s.size();
    //bool stop = false;
    for (int a = 0; a < k; ++a) {
        for (int i = 0; i < n; ++i) {
            if (i == 0) { //right
                if (s[0] == 'M') {
                    if (s[1] != 'M') s[0] = 'C';
                    s[1] = 'M';
                }
                else if (s[0] == 'C' and s[1] == 'S') s[0] = 'S';
                else if (s[1] == 'M') {
                    if (s[2] != 'M') s[1] = 'C';
                    s[0] = 'M';
                }
            }
            else if (i == n-1) { //left
                if (s[n-1] == 'M') {
                    if (s[n-2] != 'M') s[n-1] = 'C';
                    s[n-2] = 'M';
                }

                else if (s[n-1] == 'C' and s[n-2] == 'S') s[0] = 'S';
                else if (s[n-2] == 'M') {
                        if (s[n-3] != 'M') s[n-2] = 'C';
                        s[n-1] = 'M';
                    }
            }
            else { //middle;
                if (s[i] == 'M') {
                    if (s[i-1] != 'M' or s[i+1] != 'M') s[i] = 'C';
                    s[i-1] = 'M';
                    s[i+1] = 'M';
                }
                else if (s[i+1] == 'M' or s[i-1] == 'M') {
                    s[i] = 'M';
                }
                else if (s[i] == 'C' and (s[i-1] == 'S' or s[i+1] == 'S')) s[i] = 'S';

            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k; // dies
        cin >> k;
        string s; //estat inicial dels conills
        cin >> s;
        propagacio(s,k);
        cout << s << endl;
    }
}
