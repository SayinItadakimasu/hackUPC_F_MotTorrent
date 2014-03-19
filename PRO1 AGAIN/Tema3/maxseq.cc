#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n){
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int max = V[0];
        for (int j = 0; j < n; ++j) {
            if (max < V[j]) max = V[j];
        }
        cout << max << endl;
    }
}
