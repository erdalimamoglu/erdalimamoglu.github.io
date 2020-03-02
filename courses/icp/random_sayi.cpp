#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
    int r, tahmin, n;

    cout << "--\nmerhaba, kucuk bir oyun oynayalim\n";
    cout << "1 ile n arasinda bir sayi uretecegim, arzu ettiginiz n sayisini giriniz\n";
    cout << "n: ";
    cin >> n;

    srand(time(0));
    r = rand() % n + 1;
    cout << "random bir sayi urettim, bu sayiyi bulabilir misiniz?\n";

    do {
      cout << "tahmininiz: ";
      cin >> tahmin;
      if (r < tahmin)
        cout << "yanlis tahmin, daha kucuk bir sayi deneyiniz\n";
      if (r > tahmin)
        cout << "yanlis tahmin, daha buyuk bir sayi deneyiniz\n";
    } while (r != tahmin);

    cout << "random sayiyi buldunuz, tebrikler :)\n";
    cout << "urettigim random sayi " << r << " sayisi idi\n";
    cout << "hoscakalin!\n--\n";

    return 0;
}
