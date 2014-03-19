#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenation(const vector<int>& v1, const vector<int>& v2) {
    int a = v1.size();
    int b = v2.size();

    int n = a + b; //resulting vector size

    vector<int> result(n);
    for (int i = 0; i < a; ++i) { //read the first vector
        result[i] = v1[i];
    }
    int k = 0;
    for (int j = a; j < n; ++j) { //read the second vector starting from the end of the first
        result[j] = v2[k];
        ++k;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    int m;
    cin >> m;
    vector<int> v2(m);
    for (int j = 0; j < m; ++j) {
        cin >> v2[j];
    }


    vector<int> result = concatenation(v1,v2);
    int size = result.size();

    cout << result[0] << " ";
    for (int i = 1; i < size; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}
