#include<iostream>
using namespace std;

int main(){
  int a,b,c,en_buyuk;

  cout << "Bir tam sayi giriniz a = ";
  cin >> a;

  cout << "Bir tam sayi giriniz b = ";
  cin >> b;

  cout << "Bir tam sayi giriniz c = ";
  cin >> c;

  en_buyuk = a;

  if ( en_buyuk < b)
    en_buyuk = b;

  if (en_buyuk < c)
    en_buyuk = c;

  cout << "Girdiginiz sayilardan en buyuk olan = " << en_buyuk << endl;

  return 0;
}
