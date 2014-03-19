#include <iostream>
using namespace std;

int main() {
    int n, steps;

    while (cin >> n) {
        steps=0;
        while (n!=1) {
            if (n%2==0) {
                n=n/2;
                steps++;
            }
            else {
                n=n*3+1;
                steps++;
            }
        }
        cout << steps << endl;
    }

}

