#include <iostream>
#include <vector>
using namespace std;

vector<double> fusio(const vector<double>& v1, const vector<double>& v2) {
  int t1 = v1.size();
  int t2 = v2.size();
  vector<double> aux(t1 + t2);
  int i, j, k;
  i = j = k = 0;
  while (i < t1 and j < t2) {
    if (v1[i] <= v2[j]) {aux[k] = v1[i]; ++i; ++k;}
    else {aux[k] = v2[j]; ++j; ++k;}
  }
  while (i < t1) {
    aux[k] = v1[i];
    ++i; ++k;
  }
  while (j < t2) {
    aux[k] = v2[j];
    ++j; ++k;
  }
  return aux;
}

void mergesort(vector<double>& v) {
  if (v.size() > 1) {
    int t1 = v.size() / 2;
    int t2 = v.size() - t1;
    vector<double> v1(t1);
    for (int i = 0; i < t1; ++i) v1[i] = v[i];
    vector<double> v2(t2);
    for (int i = t1; i < v.size(); ++i) v2[i - t1] = v[i];
    mergesort(v1);
    mergesort(v2);
    v = fusio(v1,v2);
  }
}

int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  mergesort(v);
  for (int i = 0; i < n; ++i) cout << v[i] << " ";
  cout << endl;
}

