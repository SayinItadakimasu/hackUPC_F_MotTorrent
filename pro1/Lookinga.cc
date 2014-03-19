#include <iostream>
using namespace std;

void contains_a(char c){
    while(c != 'a' and c != '.') {
        cin >> c;
    }
    if (c == '.') cout << "no" << endl;
    else cout << "yes" << endl;
}


int main() {

    char c;
    cin >> c;
    contains_a(c);
}
