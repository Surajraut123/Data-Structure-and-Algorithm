#include<iostream> 
#include<string>
using namespace std;


/*
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

*/

string countandSay(int n) {
    if(n==1) return "1";
    if(n==2) return "11";

    //We have to see the previous string to take current string
    //To check the total number of count of an element in string
    string s = "11";
    for(int i=3; i<=n; i++) {
        //To update our counted string in each iteration till the user input of n
        string t = "";

        //To count the last element of string to check whether the last element is also common with previous element
        s = s + '$';

        //Is used, if our element is a repeated one.

        int c=1;
        for(int j=1; j<s.length();j++) {
            if(s[j] != s[j-1]) {
                t = t + to_string(c);
                t = t + s[j-1];
                c=1;     
            }

            //Element is common then we need to count that repeated element.
            else{
                c++;
            }
        }
        s=t;
    }
    return s;


}

int main() {
    int n;
    cout<<"Enter the Number : "<<endl;
    cin>>n;
    string s = countandSay(n);
    cout<<"Count and Say String : "<<endl;
    cout<<s;
    return 0;
}