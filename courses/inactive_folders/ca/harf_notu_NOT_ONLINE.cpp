#include<iostream>
using namespace std;

int main(){
  int ogr_not;

  cout << "Ogrencinin notunu giriniz: ogr_not = ";
  cin >> ogr_not;

  if (ogr_not < 0 || ogr_not > 100){
    cout << "Yanlsi giris yaptiniz\nOgrenci notu 0 ile 100 arasinda olmalidir.\n";
  }
  else {

    if (90 <= ogr_not && ogr_not <= 100){
      cout << "Harf notu = A\n";
      cout << "Ogrenci dersi gecmistir.\n";
    }

    if (80 <= ogr_not && ogr_not < 90){
      cout << "Harf notu = B\n";
      cout << "Ogrenci dersi gecmistir.\n";
    }

    if (70 <= ogr_not && ogr_not < 80){
      cout << "Harf notu = C\n";
      cout << "Ogrenci dersi gecmistir.\n";
    }

    if (50 <= ogr_not && ogr_not < 70){
      cout << "Harf notu = D\n";
      cout << "Ogrenci dersten kalmistir.\n";
    }

    if (0 <= ogr_not && ogr_not < 50){
      cout << "Harf notu = F\n";
      cout << "Ogrenci dersten kalmistir.\n";
    }

  }

  return 0;
}
