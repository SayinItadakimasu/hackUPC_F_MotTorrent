#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Pre: A is not empty with natural numbers

typedef vector<int> Row;
typedef vector<Row> Matrix;

bool es_creixent(int f, int c, const Matrix& A) {

    int x = A[0][0] - 1;
    for (int i = 0; i < c; ++i) {
        if (i%2 == 0) {
            for (int j = 0; j < f; ++j) {
                if (A[j][i] <= x) return false;
                else x = A[j][i];
            }
        }
        else {
            for (int j = f-1; j >= 0; --j) {
                if (A[j][i] <= x) return false;
                else x = A[j][i];
            }
        }
    }
    return true;
}

int main() {
    int f, c, count = 1;
    while (cin >> f >> c) {
        Matrix A(f, Row(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> A[i][j];
            }
        }
        if (es_creixent(f,c,A)) cout << "matriu " << count << ": si" << endl;
        else cout << "matriu " << count << ": no" << endl;
        ++count;
    }
}
