#include <iostream>
#include<vector>
#include<stack>

using namespace std;

bool knows( vector<vector<int> > M, int a, int b) {
    if(M[a][b]==1 ) {
        return true;
    }
    return false;
}
int celebrity( vector<vector<int> > M, int n) {
    stack<int> s;
    //step1 : insert candidate in stack
    for(int i=0;i<n;i++) {
        s.push(i);
    }

    //step2 : find who know's who
    while(s.size() > 1) {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }

    //Now this position One element is present in stack i.e Potential Celebrity
    //Step3 : Verify that celebrity

    //The potential Celebrity
    int celebrity = s.top();


    //Through Row
    bool rowCheck = false;
    int zeroCount=0;
    for(int i=0;i<n;i++) {
        if(M[celebrity][i] == 0) {
            zeroCount++;
        }
    }
    if(zeroCount==n) {
        rowCheck = true;
    }


    //Through Column
    bool colCheck = false;
    int oneCount=0;
    for(int i=0;i<n;i++) {
        if(M[i][celebrity] == 1) {
            oneCount++;
        }
    }
    if(colCount==n-1) {
        colCheck = true;
    }

    if(colCheck == true && rowCheck == true){
        return celebrity
    }
    return -1;



}

int main() {
    cout<<"Enter total Number of Candidate present in party : "<<endl;
    int n;
    cin>>n;

    vector<vector<int> > M;
    for(int i=0;i<n;i++) {
        vector<int> temp;
        for(int j=0;j<n;j++) {
            int p;
            cin>>p;
            temp.push_back(p);
        }
        M.push_back(temp);
    }
    int p = celebrity(M,n)
    cout<<"Celebrity is"<<p;
}