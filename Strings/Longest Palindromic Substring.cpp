#include<iostream>
using namespace std;

string LongestPalindromicSubstring(string str) {

    int low=0;
    int high=0;

    int start=0;
    int end=1;

    for(int i=1; i<str.length(); i++) {
        low = i-1;
        high = i;
        while(low>=0 && high < str.length() && str[low] == str[high]) {
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }

        low = i-1;
        high = i+1;
        while(low>=0 && high < str.length() && str[low] == str[high]) {
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
    }
    string s="";
    for(int i=start; i<start+end; i++) {
        s = s + str[i];
    }
    return s;

}

int main() {
    string str;
    cout<<"Enter String : "<<endl;
    getline(cin, str);

    string s = LongestPalindromicSubstring(str);
    cout<<"Longest Palindromic Substring : "<<s<<endl;

    return 0;

}