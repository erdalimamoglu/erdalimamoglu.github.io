//girilen iki x, y tam sayisinin obeb'ini hesaplayan program
#include<iostream>
using namespace std;

int main(){
	int x, y, g, x1, y1, a, b, sonuc;
	// iki tam sayi kullanici tarafindan girilsin
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	// mutlak deger alalim
	// bu islem icin kosul operatorunu kullanalim
	x1 = (x<0 ? -x : x);
	y1 = (y<0 ? -y : y);
	// sayilardan buyuk ve kucuk olanini belirleyelim
	// bu islem icin de kosul operatorunu kullanalim
	a = (x1<y1 ? y1 : x1);
	b = (x1<y1 ? x1 : y1);
	// Euclid Algoritmasi'ni C++ ile kodlayalim
	g = b;
	while (g != 0){
		g = a % b;
		a = b;
		b = g;
	}
	sonuc = a;
	// ustteki while dongusu sonlandiginda
	// sonuc degiskenine obeb(x,y) atanmis olacaktir
	// cevabi ekrana yazdiralim
	cout << "obeb(" << x << "," << y << ") = " << sonuc << endl;
	return 0;
}
