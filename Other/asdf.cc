#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

struct coordeante{
    char c;
    int n;
};

int main () {
    coordeante k;
    while (cin >> k.c >> k.n) {
        int i = k.c - 'a';
        int j = k.n;
        cout << i << " " << j << endl;
    }
}
