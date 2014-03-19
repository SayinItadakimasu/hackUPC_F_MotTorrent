#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Pre: q is not empty and really squared with natural numbers

typedef vector<int> Row;
typedef vector<Row> Square;

bool is_latin(const Square& q) {

    int length = q.size();
    for (int i = 0; i < length; ++i) {
        vector<bool> v(length + 1, 0);
        for (int j = 0; j < length; ++j) {
            if (q[i][j] <= 0 or q[i][j] > length) return false;
            else if (v[q[i][j]]) return false;
            else v[q[i][j]] = true;
        }
    }
    return true;

}

int main() {
    int n;
    cin >> n;
    Square S(n, Row(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> S[i][j];
        }
    }

    cout << is_latin(S) << endl;

}
