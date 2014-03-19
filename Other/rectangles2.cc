#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Rectangle { int x_left, x_right, y_down, y_up; };

void read(Rectangle& r) {
    cin >> r.x_left >> r.x_right >> r.y_down >> r.y_up;
}

int relationship(const Rectangle& r1, const Rectangle& r2) {

    //Identical
    if (r1.x_left==r2.x_left and r1.x_right==r2.x_right and r1.y_down==r2.y_down and r1.y_up==r2.y_up) return 4;
    //1 inside 2
    else if (r1.x_left>=r2.x_left and r1.x_right<=r2.x_right and r1.y_down>=r2.y_down and r1.y_up<=r2.y_up) return 1;
    //2 inside 1
    else if (r2.x_left>=r1.x_left and r2.x_right<=r1.x_right and r2.y_down>=r1.y_down and r2.y_up<=r1.y_up) return 2;
    //no common points
    else if (r2.x_left>r1.x_right or r2.x_right<r1.x_left or r2.y_up<r1.y_down or r2.y_down>r1.y_up) return 0;
    //intersect
    else return 3;
}

void update(Rectangle& r1, const Rectangle& r2, bool& error) {
    int n = relationship(r1,r2);
    if (n == 2) { //change r2 for r1
        r1.x_left = r2.x_left;
        r1.x_right = r2.x_right;
        r1.y_down = r2.y_down;
        r1.y_up = r2.y_up;
    }
    if (n == 3) { //depends
        if (r1.x_left < r2.x_left) r1.x_left = r2.x_left;
        if (r1.x_right > r2.x_right) r1.x_right = r2.x_right;
        if (r1.y_down < r2.y_down) r1.y_down = r2.y_down;
        if (r1.y_up > r2.y_up) r1.y_up = r2.y_up;

    }
    if (n == 0) {
        error = true;
    }
}

int main() {
    int n;
    while (cin >> n and n!= 0) {
        Rectangle r1, r2;
        read(r1);
        bool error = false;
        for (int i = 1; i != n; ++i) {
            read(r2);
            update(r1,r2,error);
        }
        if ((((n == 1 or relationship(r1,r2) != 0) and not error) and r1.x_left != r1.x_right) and r1.y_up != r1.y_down) cout << "bottom left point = ("
                                                                     << r1.x_left << ", " << r1.y_down << "); top right point = ("
                                                                     << r1.x_right << ", " << r1.y_up << ")" << endl;
        else cout << "empty intersection" << endl;
    }
}
