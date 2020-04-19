#include<iostream>
using namespace std;

int main(){
    int i;
    long int a,b,eski_b;
    
    a=1;
    b=1;
    
    cout << "fibonacci[1] = " << a << endl;
    cout << "fibonacci[2] = " << b << endl;
    
    for(i=3; i<50; i++){
        cout << "fibonacci[" << i << "] = " << b+a << endl;
        eski_b = b;
        b = a + b;
        a = eski_b;
    }
    
  return 0;
}
