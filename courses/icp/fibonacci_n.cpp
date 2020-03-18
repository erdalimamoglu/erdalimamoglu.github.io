#include <iostream>
using namespace std;

int main(){

    int i, n;
    
    cout << "n = ";
    cin >> n;
    
    float fibon[n];
    
    fibon[0]=0;
    fibon[1]=1;
    
    for(i=2; i<=n; i++)
        fibon[i]=fibon[i-1]+fibon[i-2];
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(0);
    
    cout << fibon[n] << endl;
    
    return 0;
}

