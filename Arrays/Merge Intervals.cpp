

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void MergeOverlappingIntervals(vector<vector<int>> ans, int n) {
    sort(ans.begin(), ans.end());
    vector<vector<int>> result;

    int j=0;
    result.push_back(ans[0]);
    for(int i=1; i<n; i++) {
        if(result[j][1] >= ans[i][0]) {
            result[j][1] = max(result[j][1], ans[i][1]);
        }
        else{
            j++;
            result.push_back(ans[i]);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0;j<result[i].size();j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<int>> ans;
    cout<<"Enter the Number of Rows : "<<endl;
    int rows;
    cin>> rows;
    cout<<"Enter the Number of Cols : "<<endl;
    int cols;
    cin>> cols;
    int input;
    for(int i=0; i<rows; i++) {
        vector<int> take;
        for(int j=0;j<cols;j++) {
            cin>>input;
            take.push_back(input);
        }
        ans.push_back(take);
    }

    MergeOverlappingIntervals(ans, rows);

    
    

    return 0;
}
