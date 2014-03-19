#include <iostream>
using namespace std;

bool is_diabolic(int n) {
    int aux = n;
    int sum = 0;
    while (n > 0) {
        sum += n%4;
        n /= 4;
    }
    if (aux%(2*sum) == 0) return true;
    else return false;
}


int main() {
    int n, count = 0;
    while (cin >> n and n != -1) {
        if (is_diabolic(n)) ++count;
    }
    if (count < 10) cout << "00000" << count << endl;
    else if (count >= 10 and count < 100) cout << "0000" << count << endl;
    else if (count >= 100 and count < 1000) cout << "000" << count << endl;
    else if (count >= 1000 and count < 10000) cout << "00" << count << endl;
    else if (count >= 10000 and count < 100000) cout << "0" << count << endl;
    else cout << count << endl;
}
