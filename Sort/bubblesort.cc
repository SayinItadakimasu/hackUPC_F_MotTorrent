#include <iostream>
#include <vector>
using namespace std;

void swap(int a, int b) {
    int aux = a;
    a = b;
    b = aux;
}

void bubble_sort(vector<double>& v) {
    bool sorted = false;
    int last = v.size()-1;
    while (not sorted) {
        sorted = true;
        for (int i = 0; i < last; ++i) {
            if (v[i] > v[i+1]) {
                swap (v[i], v[i+1]);
                sorted = false;
            }
        }
        --last;
    }
}
int main () {
    int n;
    cin >> n;
    vector <double> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    bubble_sort(v);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}
