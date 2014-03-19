#include <iostream>
using namespace std;

void swap2(int& a, int& b) {
    int c=a;
    a=b;
    b=c;
}

int main() {
    int x, y;

    cin >> x >> y;
    swap(x,y);
    cout << x << y << endl;

}
