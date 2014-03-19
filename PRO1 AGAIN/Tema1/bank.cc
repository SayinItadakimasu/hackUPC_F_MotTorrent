#include <iostream>
using namespace std;

int main() {

int x, y, b500, b200, b100, b50, b20, b10, b5, e2, e1, c50, c20, c10, c5, c2, c1;
cin >> x >> y;

b500=x/500;
b200=(x%500)/200;
b100=((x%500)%200)/100;
b50=(((x%500)%200)%100)/50;
b20=((((x%500)%200)%100)%50)/20;
b10=(((((x%500)%200)%100)%50)%20)/10;
b5=((((((x%500)%200)%100)%50)%20)%10)/5;
e2=(((((((x%500)%200)%100)%50)%20)%10)%5)/2;
e1=((((((((x%500)%200)%100)%50)%20)%10)%5)%2)/1;

c50=y/50;
c20=(y%50)/20;
c10=((y%50)%20)/10;
c5=(((y%50)%20)%10)/5;
c2=((((y%50)%20)%10)%5)/2;
c1=(((((y%50)%20)%10)%5)%2)/1;

cout << "Banknotes of 500 euros: " << b500 << endl;
cout << "Banknotes of 200 euros: " << b200 << endl;
cout << "Banknotes of 100 euros: " << b100 << endl;
cout << "Banknotes of 50 euros: " << b50 << endl;
cout << "Banknotes of 20 euros: " << b20 << endl;
cout << "Banknotes of 10 euros: " << b10 << endl;
cout << "Banknotes of 5 euros: " << b5 << endl;
cout << "Coins of 2 euros: " << e2 << endl;
cout << "Coins of 1 euro: " << e1 << endl;
cout << "Coins of 50 cents: " << c50 << endl;
cout << "Coins of 20 cents: " << c20 << endl;
cout << "Coins of 10 cents: " << c10 << endl;
cout << "Coins of 5 cents: " << c5 << endl;
cout << "Coins of 2 cents: " << c2 << endl;
cout << "Coins of 1 cent: " << c1 << endl;

}
