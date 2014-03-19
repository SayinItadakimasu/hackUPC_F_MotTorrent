#include <iostream>
using namespace std;

bool is_palindromic (int n) {
    int a=n, nd;
    int reversed=0;
    while (n!=0) {
        nd=n%10;
        n=n/10;
        reversed=reversed*10+nd;
    }
    if (reversed == a) return true;
    else return false;
}


int main() {
    int n;
    cin >> n;
    cout << is_palindromic(n) << endl;
}
