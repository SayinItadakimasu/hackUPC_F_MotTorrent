#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> sequence(n); //Read the vector
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }
    int last = sequence[n-1], count = 0;
    for (int j = 0; j < n-1; ++j) {
        if (sequence[j] == last) count += 1;
    }
    cout << count << endl;

}
