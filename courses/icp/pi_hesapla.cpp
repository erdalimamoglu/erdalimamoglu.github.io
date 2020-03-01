#include<iostream>
using namespace std;
#include<cmath>

int main(){
  int t;
  long double k, sonuc;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(32);

  cout << "terim sayisi = ";
  cin >> t;

  sonuc = 0;
  for (k=0; k<=t; k++){
    sonuc = sonuc +
      1/pow(16,k)*(
        4/(8*k+1)-2/(8*k+4)-1/(8*k+5)-1/(8*k+6)
      );
  }
  cout << "pi = " << sonuc << endl;

  return 0;
}
