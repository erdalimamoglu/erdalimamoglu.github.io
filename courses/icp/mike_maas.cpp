/*
Bu program farkli sekilde de yazilabilir:
Donguleri ogrendikten sonra ayni isi yapan
ve daha az satir kaplayan bir program yazilabilir.
*/

#include <iostream>
using namespace std;

int main() {

  const int min_saat = 20;

  float h1_saat, h2_saat, h3_saat, h4_saat;
  float s_ucret, s_kesinti, s_mesai;
  float h1_maas, h2_maas, h3_maas, h4_maas, toplam_maas;
  float anlasilan_maas;

  cout << "-----------------------------\n";
  cout << "Ucret bilgileri giriniz!\n";
  cout << "Saatlik ucreti: ";
  cin >> s_ucret;
  cout << "Saatlik izin kesinti miktari: ";
  cin >> s_kesinti;
  cout << "Saatlik mesai ucreti: ";
  cin >> s_mesai;

  cout << "-----------------------------\n";
  cout << "Haftalik calisma saatlerini giriniz!\n";
  cout << "1. Hafta: ";
  cin >> h1_saat;
  cout << "2. Hafta: ";
  cin >> h2_saat;
  cout << "3. Hafta: ";
  cin >> h3_saat;
  cout << "4. Hafta: ";
  cin >> h4_saat;

  cout << "-----------------------------\n";

  anlasilan_maas = s_ucret * min_saat;

  if (h1_saat >= min_saat){
    h1_maas = anlasilan_maas + (h1_saat - min_saat)*s_mesai;
  }
  else{
    h1_maas = anlasilan_maas - (min_saat - h1_saat)*s_kesinti;
  }
  cout << "1. Hafta maas = " << h1_maas << endl;

  if (h2_saat >= min_saat){
    h2_maas = anlasilan_maas + (h2_saat - min_saat)*s_mesai;
  }
  else{
    h2_maas = anlasilan_maas - (min_saat - h2_saat)*s_kesinti;
  }
  cout << "2. Hafta maas = " << h2_maas << endl;

  if (h3_saat >= min_saat){
    h3_maas = anlasilan_maas + (h3_saat - min_saat)*s_mesai;
  }
  else{
    h3_maas = anlasilan_maas - (min_saat - h3_saat)*s_kesinti;
  }
  cout << "3. Hafta maas = " << h3_maas << endl;

  if (h4_saat >= min_saat){
    h4_maas = anlasilan_maas + (h4_saat - min_saat)*s_mesai;
  }
  else{
    h4_maas = anlasilan_maas - (min_saat - h4_saat)*s_kesinti;
  }
  cout << "4. Hafta maas = " << h4_maas << endl;

  toplam_maas = h1_maas + h2_maas + h3_maas + h4_maas;

  cout << "Aylik calisma saati = " << h1_saat+h2_saat+h3_saat+h4_saat << endl;
  cout << "Aylik maas = " << toplam_maas << endl;
  cout << "-----------------------------\n";

  return 0;
}
