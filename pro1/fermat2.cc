#include <iostream>
#include <math.h>
using namespace std;

// Input: four natural numbers, such that a<=b and c<=d
// Output: natural solution to x³+y³ = z³, in which
// a <= x <= b and c <= y <= d.

// NOTE: The only natural solution is 0 + 0 = 0

void fermat (int a, int b, int c, int d, bool& sol) {
    int square;
    if (a == 0) {
        sol = true;
        square = b = c;
    }
    else if (c == 0) {
        sol = true;
        square = a = d;
    }
    if (sol) cout << a << "^3 + " << c << "^3 = " << square << "^3" << endl;

}

int main() {

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    bool end = false;
    while (not end and cin >> a >> b >> c >> d) fermat (a,b,c,d,end);
    if (not end) cout << "No solution!" << endl;
}
