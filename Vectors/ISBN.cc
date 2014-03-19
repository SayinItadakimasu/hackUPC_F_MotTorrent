#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sum_isbn(const vector<char>& V) {
    int sum = 0, j = 10;
    for (int i = 0; i < 10; ++i) {
        if (V[i] == 'X') sum = sum+10;
        else if (V[i] == '?') sum = sum;
        else sum = sum + (V[i]-'0')*j;
        --j;
    }
    return sum;
}

int multiply_isbn(const vector<char>& V) {
    int result;
    for (int i = 0; i < 10; ++i) {
        if (V[i] == '?') result = 10-i;
    }
    return result;
}

int main() {

    vector<char> isbn(10);
    while (cin >> isbn[0]){
        for (int i = 1; i < 10; ++i) cin >> isbn[i];
        int sum = sum_isbn(isbn);
        int mul = multiply_isbn(isbn);
        int missing;
        for (int i = 0; i < 11; ++i) {
            if ((sum+mul*i)%11 == 0) missing = i;
        }
        if (missing == 10) cout << "X" << endl;
        else cout << missing << endl;
    }
}

