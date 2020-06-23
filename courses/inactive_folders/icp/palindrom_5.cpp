#include<iostream>
using namespace std;

int main(){
    int x,a,b,c,d,e;

    cout << "bes basamakli bir sayi giriniz x = ";
    cin >> x;

    a = x/10000;
    b = (x-a*10000)/1000;
    c = (x-(a*10000+b*1000))/100;
    d = (x-(a*10000+b*1000+c*100))/10;
    e = x % 10;

    if (a==e && b==d){
        if (e % 2 ==0) {
            cout << "cift palindrom" << endl;
        }
        else {
            cout << "tek palindrom" << endl;
        }
    }
    else {
        cout << "palindrom degil" << endl;
    }

    return 0;
}
