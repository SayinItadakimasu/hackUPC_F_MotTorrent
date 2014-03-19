

#include <iostream>

using namespace std;

//Entrada: rep un enter i >= 0
//Sortida: retorna el nombre de digits de i
int nombre_digits(int i){
    int res = 0;
    if (i == 0) res = 1;

    while (i != 0){
        i /= 10;
        ++res;
    }

    return res;
}

//Entrada: rep un enter i >= 0
//Sortida: retorna true quan el nombre de digits de i és parell, i false quan és senar
bool nombre_digits_parell(int i){
    return (nombre_digits(i)%2 == 0);
}

//Entrada: rep un enter i >= 0 amb un nombre de digits senar
//Sortida: retorna el digit central
int digit_central(int i){
    int n = nombre_digits(i);
    int p = 1;
    for (int x=1; x <= n/2 ; ++x) p *= 10;
    return (i/p)%10;
}

int main(){
    int n;
    cin >> n;

    bool game_over = false;
    int torn = 1;
    int x,anterior;
    char guanyador;
    while (torn <= n*2 and not game_over and cin >> x){
        if (nombre_digits_parell(x)) {
            game_over = true;
        }
        else {
            x = digit_central(x);
            if (torn == 1)
                anterior = x;
            else if (x != anterior)
                game_over = true;
        }

        if (not game_over) ++torn;
    }

    if (game_over) {
        if (torn%2 != 0) guanyador = 'B';
        else guanyador = 'A';
    }
    else guanyador = '=';

    cout << guanyador << endl;
}

