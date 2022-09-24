#include<iostream>
using namespace std;

char toLower(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return ch;
    }
    else{
        ch = ch - 'A' + 'a';
    }
    return ch;
}

int main() {
    cout<<"Enter the String "<<endl;
    string str="";
    getline(cin,str);

    int i=0;
    int j=str.length()-1;
    bool check = true;
    while(i<j) {
        if(toLower(str[i]) != toLower(str[j])) {
            check = false;
            i++;j--;
        }
        else{
            
        }
    }
    if(check) {
        cout<<"String is Palindrome"<<endl;
    }
    else{
        cout<<"Not A Palindrome"<<endl;
    }
}