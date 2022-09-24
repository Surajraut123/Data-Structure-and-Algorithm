#include<iostream>
using namespace std;

int total(int nStairs) {
    if(nStairs < 0) {
        return 0;
    }
    if(nStairs == 0) {
        return 1;
    }

    int ans = total(nStairs -1) + total(nStairs - 2);
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout << " Aman Reach To top with "<<total(n)<<"Stairs";
}