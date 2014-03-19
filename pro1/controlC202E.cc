#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    for (i=0; i<n; i++) {
       for (j=2; j<=(n-i); j++) {
           cout << '+';
       }
           cout << '/';
       for (j=(n-i); j<n; j++) {
           cout << '*';
       }
       cout << endl;
    }
}
