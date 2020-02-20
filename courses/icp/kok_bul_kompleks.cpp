#include<iostream>
#include<cmath>

using namespace std;

int main() {
  int a,b,c;
  double delta, delta2, kok1, kok2, reel_kisim, imajiner_kisim;

  cout << "--------\nMerhaba\n--------\n";
  cout << "a*x^2 + b*x + c polinomunun katsayilarini giriniz:\n";
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(6);

  delta = pow(b,2) - 4*a*c;

  if (delta >= 0) {
    delta2 = sqrt(delta);
    kok1 = (-b+delta2)/(2*a);
    kok2 = (-b-delta2)/(2*a);
    cout << "Birinci kok = " << kok1 << endl;
    cout << "Ikinci kok = " << kok2 << endl;
  }
  else {
    // bu durumda diskriminant < 0
    // dolayisiyla kompleks kokler var
    delta2 = sqrt( abs(delta) );
    reel_kisim = b/(2*a);
    imajiner_kisim = delta2/(2*a);
    cout << "Birinci kok = (" << reel_kisim << ")" << " + i (" << imajiner_kisim << ")" << endl;
    cout << "Ikinci kok = (" << reel_kisim << ")" << " - i (" << imajiner_kisim << ")" << endl;
  }

  cout << "--------\nHoscakalin\n--------\n";

  return 0;
}

/*
Ornek olarak
a = 10
b = 20
c = 30
girebilirsiniz
*/
