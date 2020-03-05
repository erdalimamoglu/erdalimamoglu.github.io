#include<iostream>
using namespace std;
#include<cmath>

long double faktoriyel(int);
long double faktoriyel2(int);

int main(){
  const int N = 200;
  int i;
  long double x, sonuc;

  cout << "x = ";
  cin >> x;

  sonuc = 0;
  for (i=0; i<=N; i++){
    sonuc = sonuc + double(pow(x,i))/faktoriyel2(i);
  }
  cout << "exp(" << x << ") = " << sonuc << endl;

  return 0;
}

// faktoriyel fonksiyonu
long double faktoriyel(int x){
  int j = 1;
  long double f = 1;

  while (j <= x){
    f = f*j;
    j++;
  }

  return f;
}

// baska bir faktoriyel fonksiyonu
long double faktoriyel2(int x){
  return (x==0 ? 1 : x*faktoriyel2(x-1));
}
