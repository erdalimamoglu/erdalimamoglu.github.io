#include <iostream>
using namespace std;

//----------------------------------------------------------------

void dizi_gir( double dizi[], int m );
void dizi_yazdir( double dizi[], int m );
void dizi_topla( double dizi_1[], double dizi_2[], double yeni_dizi[], int m );
double dizi_ortalama( double dizi[], int m );
void dizi_ters_cevir( double dizi[], int m );
void insertion_sort( double dizi[], int m);

//----------------------------------------------------------------

int main(){
  int n;
  cout << "\n\nMerhaba!\n\nKac elemanli diziler gireceksiniz? n = ";
  cin >> n;

  double arr_1[n], arr_2[n], top_arr[n];
  cout << "Birinci dizinizin elemanlariniz giriniz:\n";
  dizi_gir(arr_1, n);

  cout << "ikinci dizinizin elemanlariniz giriniz:\n";
  dizi_gir(arr_2, n);

  cout << "\n------------\n";

  cout << "Girdiginiz birinci dizi asagidaki dizidir:\n";
  dizi_yazdir(arr_1, n);

  cout << "Girdiginiz ikinci dizi asagidaki dizidir:\n";
  dizi_yazdir(arr_2, n);

  cout << "\n------------\n";

  cout << "Girdiginiz dizilerin toplami asagidaki dizidir:\n";
  dizi_topla(arr_1, arr_2, top_arr, n);
  dizi_yazdir(top_arr, n);

  cout << "\n------------\n";

  cout << "Girdiginiz birinci dizinin elemanlarinin ortalamasi = ";
  cout << dizi_ortalama(arr_1, n);
  cout << "\nGirdiginiz ikinci dizinin elemanlarinin ortalamasi = ";
  cout << dizi_ortalama(arr_2, n) << endl;

  cout << "\n------------\n";
  cout << "Girdiginiz birinci dizinin ters cevirlimisi olan dizi asagidadir:\n";
  dizi_ters_cevir(arr_1, n);
  dizi_yazdir(arr_1,n);
  cout << "Girdiginiz ikinci dizinin ters cevirlimisi olan dizi asagidadir:\n";
  dizi_ters_cevir(arr_2, n);
  dizi_yazdir(arr_2,n);

  // Bu satirdan sonra dizilerimiz ter cevrilmistir,
  // fakat ters cevirme islemi dizilerimizin en kucuk ve en buyuk
  // elemanlarini degistirmeyecegi icin bu degisikligi goz ardi edebiliriz.

  cout << "\n------------\n";
  cout << "Girdiginiz birinci dizinin kucukten buyuge sirali hali asagidadir:\n";
  insertion_sort(arr_1, n);
  dizi_yazdir(arr_1,n);
  cout << "Girdiginiz ikinci dizinin kucukten buyuge sirali hali asagidadir:\n";
  insertion_sort(arr_2, n);
  dizi_yazdir(arr_2, n);

  cout << "\n------------\n";
  cout << "Girdiginiz birinci dizinin en kucuk elemani = " << arr_1[0] << endl;
  cout << "Girdiginiz ikinci dizinin en kucuk elemani = " << arr_2[0] << endl;

  cout << "\nHoscakalin!\n\nGuz doneminde Pyhton Programlama dersimizde gorusmek uzere!\n\n";

  return 0;
}

//----------------------------------------------------------------

void dizi_gir( double dizi[], int m ){
  int i;
  for (i=0; i<m; i++){
    cout << i+1 << ". eleman = ";
    cin >> dizi[i];
  }
}

//----------------------------------------------------------------

void dizi_yazdir( double dizi[], int m ){
  int i;
  cout << "[";
  for (i=0; i<m; i++){
    if (i == m-1)
      cout << dizi[i] << "]\n";
    else
      cout << dizi[i] << ",";
  }
}

//----------------------------------------------------------------

void dizi_topla( double dizi_1[], double dizi_2[], double yeni_dizi[], int m ){
  int i;
  for (i=0; i<m; i++){
    yeni_dizi[i] = dizi_1[i] + dizi_2[i];
  }
}

//----------------------------------------------------------------

void dizi_ters_cevir( double dizi[], int m){
  double ortadaki_indis, gecici_degisken;
  int i;
  ortadaki_indis = double(m-1)/2;
  for (i=0; i<ortadaki_indis; i++){
    gecici_degisken = dizi[i];
    dizi[i] = dizi[m-1-i];
    dizi[m-1-i] = gecici_degisken;
  }
}

//----------------------------------------------------------------

double dizi_ortalama( double dizi[], int m){
  double ort, t;
  int i;
  t = 0;
  for (i=0; i<m; i++){
    t += dizi[i];
  }
  ort = t / (m);
  return ort;
}

//----------------------------------------------------------------

void insertion_sort( double dizi[], int m){
  int i=1,j=1;
  double t;
  for (i=1; i<m; i++){
    t = dizi[i];
    j = i-1;
    while ( j >=0 && dizi[j] > t ){
      dizi[j+1] = dizi[j];
      j--;
    }
    dizi[j+1] = t;
  }
}

//----------------------------------------------------------------
