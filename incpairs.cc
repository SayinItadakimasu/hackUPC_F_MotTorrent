#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int first, next;
        int count = 0;
        cin >> first >> next;
        while(next != 0) {
            if (first < next) ++count;
            first = next;
            cin >> next;
        }
        cout << count << endl;

    }
}
