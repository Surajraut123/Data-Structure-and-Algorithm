#include<iostream>
#include<vector>
using namespace std;

bool valid(char ch) {
    if(ch>='0' && ch<='9' || ch>='a' && ch<='z' || ch>='A' && ch<='Z') {
        return true;
    }
    return false;
}

char toLower(char ch) {
    if(ch>='0' && ch<='9' || ch>='a' && ch<='z') {
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
    string v;
    for(int i=0; i < str.length(); i++) {
        if(valid(str[i])){
            v.push_back(str[i]);
        }
    }
    cout<<v<<endl;
    int i=0;
    int j=v.length()-1;
    bool check = true;
    while(i<j) {
        if(v[i++]!=v[j--]) {
            check = false;
        }
        else{
            i++;j--;
        }
    }
    if(check) {
        cout<<"PalinDrome"<<endl;
    }
    else{
        cout<<"Not Palindrome "<<endl;
    }
}