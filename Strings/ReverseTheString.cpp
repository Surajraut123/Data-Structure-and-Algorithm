#include<iostream>
using namespace std;


int main() {
    cout<<"Enter the String "<<endl;
    string str="";
    getline(cin,str);

    int i=0, j=str.length()-1;
    while(i<j) {
        swap(str[i++], str[j--]);
    }
    cout<<"Reverse String "<<endl;
    cout<<str;
}