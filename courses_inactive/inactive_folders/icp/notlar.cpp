//-------------------------------------------------------------------------//

#include<iostream>
using namespace std;

//-------------------------------------------------------------------------//

int main(){
  int n;

  cout << "Kac ogrencinin notu girilecek? n = ";
  cin >> n;

  int notlar[n-1];
  int i, toplam;
  float ortalama, kontrol_et;

  toplam = 0;
  for(i=1; i<=n; i++){
    cout << i << ". Ogrencinin Vize Notu = ";
    cin >> notlar[i-1];
    toplam += notlar[i-1];
  }

  ortalama = float(toplam)/n;

  cout << "Vize Ortalamasi = " << ortalama << endl;

  for(i=1; i<=n; i++){
    kontrol_et = notlar[i-1] - ortalama;
    if ( kontrol_et <= 0 )
    cout << i << ". Ogrencinin Vize Notu Ortalamadan " << kontrol_et << " dusuktur.\n";
    else
    cout << i << ". Ogrencinin Vize Notu Ortalamadan " << kontrol_et << " fazladir.\n";
  }

  return 0;
}

//-------------------------------------------------------------------------//
