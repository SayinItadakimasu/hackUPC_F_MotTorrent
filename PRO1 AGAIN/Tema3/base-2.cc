#include <iostream>

using namespace std;

void binari(int n){
    int cont = 0;
    if (n < 0){
        while (n < 0){
            n = n + 2;
            ++cont;
        }
        binari(cont);
        cout << n;
    }
    else{
        if (n > 0){
            while (n > 1){
                n = n - 2;
                --cont;
            }
            binari(cont);
            cout << n;
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        cout << n << ": ";
        if (n == 0) cout << "0";
        else binari(n);
        cout << endl;
    }
}
