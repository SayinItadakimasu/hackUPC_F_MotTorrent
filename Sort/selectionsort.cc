#include <iostream>
#include <vector>
using namespace std;

void swap(int a, int b) {
    int aux = a;
    a = b;
    b = aux;
}

int minimum_pos(const vector<double>& v, int left, int right) {
    int pos = left;
    for (int i = left; i < right; ++i) {
        if (v[i] < v[pos]) pos = i;
    }
    return pos;
}

void selection_sort(vector<double>& v, int m){
    int last = m;
    for (int i = 0; i < last; ++i) {
        int k = minimum_pos(v, i, last);
        swap(v[k], v[i]);
    }
}
int main () {
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    selection_sort(v, m);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
}
