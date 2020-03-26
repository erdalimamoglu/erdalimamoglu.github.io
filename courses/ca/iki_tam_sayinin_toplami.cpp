/*
Asagidaki C++ programi bilgisayar ekranina
kullanicinin klavye ile girdigi iki tam sayiyinin toplamini yazdirir
*/

#include<iostream>
using namespace std;

int main(){

	int x, y, z;

	cout << "Iki tam sayi giriniz\n";

	cout << "x = ";
	cin >> x;

	cout << "y = ";
	cin >> y;

	z = x + y;
	cout << "Girdiginiz tam sayilarin toplami = " << z << endl;

	return 0;
}
