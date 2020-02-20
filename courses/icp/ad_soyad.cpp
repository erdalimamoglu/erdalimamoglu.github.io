#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
  string ad, soyad;
  long fav_sayi;

  cout << "Merhaba\n";
  cout << "Isminiz nedir?\n";
  cout << "Isim: ";
  cin >> ad;
  cout << "Soyisim: ";
  cin >> soyad;
  cout << "En sevdiginiz sayi kac?\n";
  cout << "n = ";
  cin >> fav_sayi;

  cout << "Tanistigima memnun oldum " << ad << " " << soyad << "!" << endl;
  cout << "En sevdiginiz sayinin 5. kuvveti = " << pow(fav_sayi,5) << endl;
  cout << "Hoscakalin";

  return 0;
}
