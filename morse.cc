#include <iostream>

using namespace std;

void morse(char c, int& n){
    if(c == 'a') {
        cout << ".-";
        n += 2;
    }
    else if (c == 'e') {
        cout << ".";
        ++n;
    }
    else if (c == 'i') {
        cout << "..";
        n += 2;
    }
    else if (c == 'o') {
        cout << "---";
        n += 3;
    }
    else if (c == 'u') {
        cout << "..-";
        n += 3;
    }
}

int main() {
    int n;
    char c;
    cin >> n;
    int i = 0;
    while(cin >> c) {
        morse(c,i);
        if (i >= n) {
            cout << endl;
            i = 0;
        }
    }
    if (i != 0 and i < n) cout << endl;
    cout << "STOP" << endl;
}
