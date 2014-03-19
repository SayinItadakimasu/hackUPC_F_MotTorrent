#include <iostream>
#include <string>

using namespace std;


/*esquema:
 *(parameters part of the input, goes with the return)
 *  i=1 aaa 4
 *    2 bbb 3
 *    3 ccc 2
 *    4 ddd 1 = j
 *
 *1st half (i<j)
 *2nd half (j<i)
 *
 *i = index top-bottom, returns bottom-top
 *j = index bottom-top, returns top-bottom
 */
/*

int reverse(int i) {
    string s;
    while (cin >> s) {
        if (s != "end") {
            int j = reverse(i+1);
            cout << s << endl;
            return j+1;
        }
        //else return 1;
    }
}

int main() {
    reverse(1);
}*/

int reverse(int n,int i) {

}

int main() {
    int n;
    cin >> n;
    reverse(n,1);
}
