#include <iostream>
#include <vector>
#include <string>
using namespace std;

int evaluate(const vector<int>& p, int x) {

    int i = p.size() - 1;
    int sum = p[i];
    --i;
    while (i >= 0) {
        sum = (sum*x +p[i]);
        --i;
    }
    return sum;
}

int main() {
    int x;
    cin >> x;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << evaluate(A,x) << endl;


}
