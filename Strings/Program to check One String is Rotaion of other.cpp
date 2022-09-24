#include<iostream>
#include<string>
#include<queue>
using namespace std;

bool concatenate(string s1, string s2) {

    if(s1.length() < s2.length() && s1.length() > s2.length()){
        return false;
    }
    string check = s1+s2;
    return (check.find(s2) != string::npos);
}

bool TwoSpace(string s1, string s2) {

    queue<char> q1;
    for(int i=0;i<s1.length();i++) {
        q1.push(s1[i]);
    }

    queue<char> q2;
    for(int i=0;i<s2.length();i++) {
        q2.push(s2[i]);
    }

    int k=s2.length();
    while(k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if(q1==q2) {
            return true;
        }
    }
    return false;


}

int main() {
    string str1;
    getline(cin, str1);

    string str2;
    getline(cin, str2);

    //Approach 1
    if(concatenate(str1, str2)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False" <<endl;
    }
    

    //Approach 2
    cout<<"Using Queue" <<endl;
    if(TwoSpace(str1, str2)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False" <<endl;
    }
}