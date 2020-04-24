#include<iostream>
using namespace std;

int main() {

  int a;

  cout << "Bir tam sayi giriniz: a = ";
  cin >> a;

  if (a % 2 == 0){
    cout << "Girdiginiz " << a << " sayisi cift sayidir\n";
  } else {
    cout << "Girdiginiz " << a << " sayisi tek sayidir\n";
  }

  return 0;

}
