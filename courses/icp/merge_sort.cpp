//-------------------------------------------------------------------------//

#include<iostream>
using namespace std;

//-------------------------------------------------------------------------//

void merge_sort(int a[], int ilk_indis, int son_indis);
void merge(int a[], int ilk_indis, int orta_indis, int son_indis);

//-------------------------------------------------------------------------//

int main(){

  int uzunluk;
  cout << "Merhaba!\nKac tam sayi girilecek? uzunluk = ";
  cin >> uzunluk;

  int liste[uzunluk], i;

  cout << "Sayilari teker teker giriniz:\n";

  for(i=0; i<uzunluk; i++){
    cout << i+1 << ". sayi = ";
    cin >> liste[i];
  }

  merge_sort(liste, 0, uzunluk - 1);

  cout << "Sayilari Siraladim:\n";

  for (i=0; i<uzunluk; i++){
    if (i==uzunluk-1){
      cout << liste[i];
    }
    else {
      cout << liste[i] << ", ";
    }
  }

  cout << "\nHoscakalin!\n";

  return 0;
}

//-------------------------------------------------------------------------//

void merge_sort(int a[], int ilk_indis, int son_indis){
  if (ilk_indis < son_indis){

    int orta_indis = ilk_indis + (son_indis - ilk_indis)/2;

    merge_sort(a, ilk_indis, orta_indis);
    merge_sort(a, orta_indis+1, son_indis);

    merge(a, ilk_indis, orta_indis, son_indis);
  }
}

//-------------------------------------------------------------------------//

void merge(int a[], int ilk_indis, int orta_indis, int son_indis){

  int x;
  int y;
  int z;

  int s1 = orta_indis - ilk_indis + 1;
  int s2 =  son_indis - orta_indis;

  int ilk_yari[s1];
  int ikinci_yari[s2];

  for (x = 0; x < s1; x++){
    ilk_yari[x] = a[ilk_indis + x];
  }
  for (y = 0; y < s2; y++){
    ikinci_yari[y] = a[orta_indis + 1+ y];
  }

  x = 0;
  y = 0;
  z = ilk_indis;

  while (x < s1 && y < s2){
    if (ilk_yari[x] <= ikinci_yari[y]){
      a[z] = ilk_yari[x];
      x++;
    }
    else{
      a[z] = ikinci_yari[y];
      y++;
    }
    z++;
  }

  while (x < s1){
    a[z] = ilk_yari[x];
    x++;
    z++;
  }

  while (y < s2){
    a[z] = ikinci_yari[y];
    y++;
    z++;
  }

}

//-------------------------------------------------------------------------//
