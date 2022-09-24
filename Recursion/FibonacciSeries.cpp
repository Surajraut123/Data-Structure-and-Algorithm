#include <iostream>
#include <queue>
using namespace std;


void fib(int n) {
    if(n==0) {
        cout << "0";
    }
    if(n==1) {
        cout << "1";
    }
    
    int a=0,b=1,c=0;
    for(int i=0;i<n-1;i++) {
        c=a+b;
        a=b;
        b=c;
    }
    cout << "Nth Fibonacci Number is "<<c<<endl;
}

int main(){

    int n;
    cout<<"Size: ";
    cin>>n;
    

    cout<<"Fibonacci Series : ";
    int a=0;
    int b=1;
    cout<<a<< " "<<b<<" ";
    int c=0;
    for(int i=0;i<n-1;i++) {
        c = a+b;
        a=b;
        b=c;
        cout << c << " ";

    }
    cout<<endl;
    
    fib(n);
}    