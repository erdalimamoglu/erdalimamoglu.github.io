#include<iostream>
#include<cmath>

using namespace std;

int main() {
  int a,b,c;
  double delta, kok1, kok2;

  cout << "--------\nMerhaba\n--------\n";
  cout << "a*x^2 + b*x + c polinomunun katsayilarini giriniz:\n";
  cout << "ONEMLI NOT: Kompleks kokleri henuz hesaplayamiyoruz!\n";
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(6);

  delta = sqrt( pow(b,2) - 4*a*c );
  kok1 = (-b+delta)/(2*a);
  kok2 = (-b-delta)/(2*a);

  cout << "Birinci kok = " << kok1 << endl;
  cout << "Ikinci kok = " << kok2 << endl;
  cout << "--------\nHoscakalin\n--------\n";

  return 0;
}

/*
Ornek olarak
a = 1
b = 2
c = -100
girebilirsiniz
*/
