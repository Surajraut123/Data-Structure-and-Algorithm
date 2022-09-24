#include<bits/stdc++.h> 
#include<string>
#include<vector>
using namespace std ;


void solve(string str, int index, string output,vector<string>& ans) {
    if(index>=str.length()) {
        ans.push_back(output);
        return;
    }

    // Answer will come in random order
    // If want ans in Lexicographical order then use Bit Manipulation or Sort Method - 
    //sort(ans.begin(), ans.end());

    //exclude
    solve(str, index+1, output, ans);
    
    // include
    output.push_back(str[index]);
    solve(str, index+1, output, ans);
}

int main() {
    string str;
    getline(cin, str);

    int index=0;
    vector<string> ans;
    string output="";
    solve(str, index, output, ans);
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i] << " " ;
    }
}