#include<iostream>
#include<vector>
using namespace std;



// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true


bool check(int a[26], int b[26]) {
    for(int i=0;i<26;i++) {
        if(a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

bool checkEquAL(string st1, string st2){
    int count1[26] = {0};
    for(int i=0;i<st1.length();i++) {
        int index = st1[i] - 'a';
        count1[index]++;
    }

    int i=0;
    int window = st1.length();
    int count2[26] = {0};

    while(i < window && i < st2.length()) {
        int index = st2[i]-'a';
        count2[index]++;
        i++;
    }

    if(check(count1, count2)) {
        return 1;
    }

    while(i < st2.length()) {
        char newChar = st2[i];
        int index = newChar - 'a'; 
        count2[index]++;

        char oldChar = st2[i - window];
        index = oldChar - 'a';
        count2[index]--;
        i++;

        if(check(count1, count2)) {
            return 1;
        } 
    }
    return 0;
}
int main() {
    cout<<"Enter the String "<<endl;
    string st1="";
    getline(cin,st1);

    string st2="";
    getline(cin,st2);

    if(checkEquAL(st1, st2)) {
        cout<<"Valid Palindrome";
    }
    else{
        cout<<"Invalid Palindrome";
    }
    
}