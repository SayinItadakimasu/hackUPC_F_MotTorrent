#include <iostream>
using namespace std;


int sum_of_digits(int x) {
    if (x < 10) return x;
    else {
       int suma = 0;
       suma = x%10 + sum_of_digits(x/10);
       return suma;
      }
}

int reduction_of_digits(int x){
    if (x < 10) return x;
    else return reduction_of_digits(sum_of_digits(x));
}


int main() {
    int a;
    cin >> a;
    cout << reduction_of_digits(a) << endl;

}

