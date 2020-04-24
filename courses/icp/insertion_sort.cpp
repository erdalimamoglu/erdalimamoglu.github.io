//-------------------------------------------------------------------------//

#include<iostream>
using namespace std;

//-------------------------------------------------------------------------//

int main(){
  int n, i, j, t;

  cout << "Merhaba!\nKac tam sayi girilecek? n = ";
  cin >> n;

  int liste[n];

  cout << "Sayilari teker teker giriniz:\n";

  for (i=0; i<n; i++){
    cout << i+1 << ". sayi = ";
    cin >> liste[i];
  }

  for (i=1; i<n; i++){
    t = liste[i];
    j = i;
    while (liste[j-1] > t){
      liste[j] = liste[j-1];
      j--;
    }
    liste[j] = t;
  }

  cout << "Sayilari Siraladim:\n";

  for (i=0; i<n; i++){
    if (i==n-1){
      cout << liste[i];
    } else {
      cout << liste[i] << ", ";
    }
  }

  cout << "\nHoscakalin!\n";

  return 0;
}

//-------------------------------------------------------------------------//
