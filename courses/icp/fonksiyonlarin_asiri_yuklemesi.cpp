// fonksiyonlarin asiti yuklamesi (function overloading)

#include<cmath>
#include<iostream>
using namespace std;

// asagida yazilan uc fonksyion birbirinden farklidir
// cunku bu fonksiyonlarin parametre tipleri farklidir
// bu ornegi dikkatlice inceleyiniz

// sayilari girdikten sonra hangi fonksiyonlarin cagirildigina dikkat ediniz

double hesapla(int, int);
double hesapla(int, double);
double hesapla(double, double);

int main(){
  int i1,i2;
  double d1,d2;

  cout << "merhaba\n";

  cout << "(int) i1 = ";
  cin >> i1;
  cout << "(int) i2 = ";
  cin >> i2;

  cout << "sonuc = " << hesapla(i1,i2) << endl;

  cout << "(int) i1 = ";
  cin >> i1;
  cout << "(double) d1 = ";
  cin >> d1;

  cout << "sonuc = " << hesapla(i1,d1) << endl;

  cout << "(double) d1 = ";
  cin >> d1;
  cout << "(double) d2 = ";
  cin >> d2;

  cout << "sonuc = " << hesapla(d1,d2) << endl;

  cout << "hoscakalin\n";

  return 0;
}


double hesapla(int x, int y){
  return pow(x,y);
}

double hesapla(int x, double y){
  return x - y;
}

double hesapla(double x, double y){
  return x * y;
}
