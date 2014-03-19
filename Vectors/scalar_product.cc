#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v) {

    int n = u.size();
    double product = 0;
    for (int i = 0; i < n; ++i) {
        product += u[i]*v[i];
    }
    return product;

}

int main() {
    int n;
    vector<double> u(n);
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i] >> v[i];
    }
    cout << scalar_product(u,v) << endl;

}
