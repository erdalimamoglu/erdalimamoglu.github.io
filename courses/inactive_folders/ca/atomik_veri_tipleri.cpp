//Asagidaki program bazi atomik veri tipleri icin bir ornektir

#include <iostream>
using namespace std;

int main(){
	char h;
	int x;
	float y;
	double z;

	cout << "Bir karakter (harf) giriniz h = ";
	cin >> h;

	cout << "Bir tam sayi giriniz x = ";
	cin >> x;
	
	cout << "Bir kayan-noktali sayi (float ondalikli sayi) giriniz y = ";
	cin >> y;

	cout << "Bir kayan-noktali sayi (double ondalikli sayi) giriniz z = ";
	cin >> z;

	cout << "Girdiginiz veriler asagidadir\n";
	cout << "Harf: " << h << endl;
	cout << "Tam sayi: " << x << endl;
	cout << "Kayan-noktali sayi (float): " << y << endl;
	cout << "Kayan-noktali sayi (double): " << z << endl;

	return 0;
}

