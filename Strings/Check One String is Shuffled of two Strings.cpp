#include<bits/stdc++.h>
using namespace std;

bool checkLength(string first, string second, string result) {
    if(first.length() + second.length() == result.length()) {
        return true;
    }
    return false;

}

string sortStr(string str) {
    // c_str() -> Function or a Library to convert string to character array
    int n = str.length();
    char char_array[n];
    str = "";
    strcpy(char_array, str.c_str());
    sort(char_array, char_array+1);
    
    for(int i=0;i<n;i++) {
        str = str + char_array[i];
    }
    return str;
}

bool shuffleString(string first, string second, string result) {
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    sort(result.begin(), result.end());

    int i=0, j=0, k=0;
    while(k < result.length()) {
        if(i < first.length() && first[i] == result[k]) {
            
            i++;
        }
        else if(j < second.length() && second[j] == result[k]) {
            j++;
        }
        else{
            return false;
        }
        k++;
    }
    if(i < first.length() || j < second.length()) {
      return false;
    }
    return true;
}

int main() {

    /*
    we have a string array named results. It contains three strings: 1XY2, Y1X2, and Y21XX.
    We are checking if these three strings are valid shuffle of strings first(XY) and second(12).
    */

    string first;
    cout<<"First : "<<endl;
    getline(cin, first);

    string second;
    cout<<"second : "<<endl;
    getline(cin, second);
    
    int k;
    cout<<"Enter total Strings : "<<endl;
    cin>>k;
    string results[k];
    cout<<"result : "<<endl;
    for(int i=0;i<k;i++) {
        cin>>results[i];
    }
    for(auto result : results) {
        if(checkLength(first, second, result) && shuffleString(first, second, result)) {
            cout << result << " is a valid shuffle of " << first << " and " << second<<endl;
        }
        else {
            cout << result << " is not a valid shuffle of " << first << " and " << second<<endl;
        }
    }
}