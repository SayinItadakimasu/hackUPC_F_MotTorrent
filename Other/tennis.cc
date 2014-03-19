

#include <iostream>
#include <vector>

using namespace std;

string winner(const vector<string>& name, const vector<bool>& win){
    int m = name.size();

    int g = 0;
    int i = 0;
    while (m > 1){
        m = m/2;

        if (win[g]) g = 2*g + 1;
        else {
            g = 2*g + 2;
            i += m;
        }
    }

    return name[i];
}
/*
int main(){
    int m;
    cin >> m;
    vector<string> name(m);
    for (int k = 0; k < m; ++k) cin >> name[k];
    vector<bool> win(m-1,false);

    win[0] = true;
    win[3] = true;
    win[5] = true;
    win[6] = true;

    cout << winner(name,win) << endl;
}*/

