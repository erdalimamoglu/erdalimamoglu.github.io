#include<iostream>
using namespace std;

int main(){
    const int N=50;
    int n;
    long int fibonacci[N];
    
    fibonacci[0]=1;
    fibonacci[1]=1;
    
    for(n=2; n<=49; n++){
        fibonacci[n] = fibonacci[n-1]+fibonacci[n-2];
    }

    for(n=0; n<=49; n++){
        cout << "fibonacci[" << n+1 << "] = " << fibonacci[n] << endl;
    }
    
  return 0;
}
