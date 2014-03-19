#include <iostream>
using namespace std;

int number_of_digits (int n) {
    int count;
    for (count=1; n>9; count++) n=n/10;
    return count;
}


int main() {
    int n;
    cin >> n;
    cout << number_of_digits(n) << endl;
}
