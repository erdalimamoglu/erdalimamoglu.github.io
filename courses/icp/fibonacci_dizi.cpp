#include <iostream>
using namespace std;

int main(){

    float fibon[50];
    int i;
    
    fibon[0]=0;
    fibon[1]=1;
    
    for(i=2; i<=49; i++)
        fibon[i]=fibon[i-1]+fibon[i-2];
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(0);
    
    for (i=0; i<=49; i++)
        cout << fibon[i] << ",";
    
    cout << endl;
    
    return 0;
}

