#include<iostream>
using namespace std;

int main(){
    int i;
    cin >> i;
    cout << i << endl;
    
    if (i==i%10) cout << "1 basamakli" << endl;
    else if (i==i%100) cout << "2 basamakli" << endl;
    else if (i==i%1000) cout << "3 basamakli" << endl;
    else if (i==i%10000) cout << "4 basamakli" << endl;
    else if (i==i%100000) cout << "5 basamakli" << endl;
    else if (i==i%1000000) cout << "1 basamakli" << endl;
    
    return 0;
}