/*
Asagidaki C++ programi bilgisayar ekranina
kullanicinin klavye ile girdigi tam sayiyi yazdirir
*/

#include<iostream>
using namespace std;

int main(){

	int x; // bu komut bir x (tam sayi) degiskeni tanimi yapar

	cout << "x = "; // bu komut ekrana "x = " yazdirir
	cin >> x; // bu komut kullanicidan bir tam sayi alip bu tam sayiyi x degiskenine atar

	cout << "Girdiginiz tam sayi = " << x << endl;

	return 0;
}
