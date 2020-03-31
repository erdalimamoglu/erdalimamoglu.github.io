/*
Bu programda parametresiz fonksiyonlar ve void fonksiyonlar
hakkinda ornekler bulabilirsiniz
*/

#include<iostream>
using namespace std;

int sayi_iste();
void biraz_bekle();

int main() {
  int a,b,t;

  a = sayi_iste();
  b = sayi_iste();

  biraz_bekle();

  t = a + b;

  cout << "toplam = " << t << endl;

  return 0;
}

int sayi_iste(){
  int x;
  cout << "bir tam sayi giriniz: ";
  cin >> x;
  return x;
}

void biraz_bekle(){
  int i=0, y;
  cout << "merhaba, nasilsiniz, girdiginiz iki tam sayinin toplami birazdan yapilacak\n";
  cout << "sonuc birazdan yazdirilacak, lutfen bekleyiniz...\n";
  while(i<=2000000000){
    y = i*i*i;
    i++;
  }
}
