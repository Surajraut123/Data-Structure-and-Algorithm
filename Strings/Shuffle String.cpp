#include<iostream>
#include<string>
using namespace std;

int main() {


    /*
        Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
        Output: "leetcode"
        Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
    */

    string str;
    getline(cin, str);

    int n=str.length();
    int indices[n];
    for(int i=0;i<n;i++) {
        cin>>indices[i];
    }

    string s=str;
    for(int i=0;i<n;i++) {
        s[indices[i]] = str[i];
    }
    cout<<s;
    
}