#include<iostream>
using namespace std;
#include<cmath>

int main(){
  const double SONDEGER = 200;
  long double n, sonuc, k;
  
  cout << "bir reel sayi giriniz n = ";
  cin >> n;

  if( n<=0 || 2<n ){
    cout << "0'dan buyuk 2'den kucuk-esit bir sayi girmelisiniz!\n";
  }
  else{
    sonuc = 0;
    for (k=1; k<=SONDEGER; k++){
      sonuc += pow(-1,k-1)*(pow(n-1,k)/k);
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(12);

    cout << "ln(" << n << ") = " << sonuc << endl;
  }

  return 0;
}

