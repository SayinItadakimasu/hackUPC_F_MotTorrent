#include <iostream>
using namespace std;

int main() {
    int x, y, count=0;
    cin >> x;
    cout << "nombres que acaben igual que " << x << ":" << endl;
    while (cin >> y) {
        if ((x%1000)==(y%1000)) {
            cout << y << endl;
            count=count+1;
        }
     }
    cout << "total: " << count << endl;

}
