#include <iostream>
using namespace std;


int intercalacio(int x, int y) {
    if (x < 10) return x*10 + y;
    else return intercalacio(x/10,y/10) * 100 + (x%10)*10 + y%10;

}


int main() {
    int x, y;
    while (cin >> x >> y) cout << intercalacio(x,y) << endl;

}

