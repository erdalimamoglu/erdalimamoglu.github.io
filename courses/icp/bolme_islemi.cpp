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
  Burada x/y isleminin sonucu kusuratli olsa bile
  z degiskeni bir int olarak deklare edildiginden
  z degiskenine z/y isleminin sonucunun tam sayi kismi atanir.
  Ornek olarak x=3,y=2 deneyebilirsiniz.
  */

  cout << x << "/" << y << " = " << z << endl;

  return 0;
}
