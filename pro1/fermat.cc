#include <iostream>
#include <math.h>
using namespace std;

// Input: four natural numbers, such that a<=b and c<=d
// Output: natural solution to x²+y² = z², in which
// a <= x <= b and c <= y <= d.

// NOTE: if there's more than one solution, print the smallest x and
// if there's a tie print the lowest y. If there's no solution, print
// No solution!


int main() {

    int a,b,c,d;
    int save1 = 0;//varaible per guardar x.
    int save2 = 0;//variable per guardar y.
    double z,s;
    cin >> a >> b >> c >> d;
    bool fermat = false;//boolea.
    int x = a;
    int y = c;
    while ( x <= b and not fermat ) {
        y = c;
        while ( y <= d and not fermat ) {
            z = sqrt ( x*x + y*y );
            s = int (z);
            if ( s - z == 0 ) { //si es 0 es cumplira el teorema de fermat.
                save2 = y;
                fermat = true;
            }
            ++y;
        }
        save1 = x;
        ++x;
    }
    if (fermat) cout << save1 << "^2 + " << save2 << "^2 = " << z << "^2" << endl;
    if (not fermat) cout << "No solution!" << endl;
}
