#include<iostream>
using namespace std;

int main(){
  int x,y,z;

  cout << "iki tam sayi giriniz\n";
  cout << "x = ";
  cin >> x;
  cout << "y = ";
  cin >> y;

  z = x/y;
  /*
  burada x/y isleminin sonucu kusuratli olsa bile
  z degiskeni bir int olarak deklare edildiginden
  z degiskene z/y isleminin sonucunun tam sayi kismi atanir

  Ornek olarak x=3,y=3 deneyebilirsiniz
  */

  cout << x << "/" << y << " = " << z << endl;

  return 0;
}
