#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    cin >> n;
    while (n > 0) {
        int m;
        cin >> m;
        double x, min, max, avarage;
        cin >> x;
        min = max = avarage = x;
        for (int i = 1; i < m; i++) {
            cin >> x;
            //mitjana
            avarage = avarage + x;
            //maxim
            if (max < x) max = x;
            //minim
            if (min > x) min = x;
        }
        cout << min << " " << max << " " << avarage/m << endl;
        n--;
    }
}
