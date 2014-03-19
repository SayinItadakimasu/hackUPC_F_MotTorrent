#include <iostream>
#include <vector>
using namespace std;

void swap(int a, int b) {
    int aux = a;
    a = b;
    b = aux;
}

void insertion_sort(vector<double>& v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        double x = v[i];
        int j = i;
        while (j > 0 and x < v[j-1]) {
            v[j] = v[j-1];
            --j;
        }
        v[j] = x;
    }
}
int main () {
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    insertion_sort(v);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
}
