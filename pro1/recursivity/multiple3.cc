#include <iostream>
using namespace std;


int sum_digits(int n) {
    if (n < 10) return n;
    else {
       int suma = 0;
       suma = n%10 + sum_digits(n/10);
       return suma;
      }
}

bool is_multiple_3(int n){
    if (sum_digits(n)%3 == 0) return 1;
    else return 0;
}


int main() {
    int a;
    cin >> a;
    cout << is_multiple_3(a) << endl;

}

