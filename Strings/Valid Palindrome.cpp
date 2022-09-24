#include<iostream>
#include<string>
using namespace std;

//Given a string s, return true if the s can be palindrome 
//after deleting at most one character from it.
bool check(string str, int s, int e){
    while(s<=e){
        if(str[s]!=str[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
bool palindrome(string str) {
    int start = 0;
    int end = str.length()-1;
    while(start <= end) {
        if(str[start] == str[end]){
            start++;
            end--;
        }
        else if(check(str, start+1, end) || check(str, start, end-1)){
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}
int main() {
    string str;
    getline(cin, str);
    if(palindrome(str)){
        cout<<"It is Palindrome"<<endl;
    }
    else{
        cout<<"Not a Palindrome"<<endl;
    }
}