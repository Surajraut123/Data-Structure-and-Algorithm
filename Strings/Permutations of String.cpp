#include<bits/stdc++.h>

using namespace std;
vector<string> findUnique(vector<string> ans) {
        unordered_map<string, bool> mp;
        for(int i=0; i<ans.size(); i++) {
            if(!mp[ans[i]]) {
                mp[ans[i]] = true;
            }
        }
        vector<string> tmp;
        for(auto i : mp) {
            if(i.second == true){
                tmp.push_back(i.first);
            }
        }
        return tmp;
        
        
    }

void solve(string str, vector<string>& ans , int index) {
    if(index>=str.length()) {
        ans.push_back(str);
        return;
    }

    for(int i=index; i<str.length();i++) {
        swap(str[index], str[i]);
        solve(str, ans, index+1);
        swap(str[index], str[i]);
    }
}
int main() {
    string str;
    getline(cin, str);

    vector<string> ans;
    int index=0;
    solve(str, ans, index);    
    ans = findUnique(ans);
    sort(ans.begin(), ans.end());
    for(auto i : ans ){
        cout<< i << " ";
    }
    
}