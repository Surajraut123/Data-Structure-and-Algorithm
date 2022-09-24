#include<iostream>

using namespace std;



void stockBuySell(int price[], int n) {
    int curProfit = 0;
    int maxProfit= 0;
    int buy = price[0];
    int start = 0;
    int end = 0;
    
    for(int i=0;i<n;i++) {
        if(price[i] < buy || price[i-1] > price[i]) {
            buy = price[i];
            start = i;
        }
        curProfit = price[i] - buy;
        if(curProfit > maxProfit) {
            maxProfit = curProfit;
            end = i;
        }
        
        if((price[i+1] < price[i] && start < end) || (i+1==n)) {
            cout<<"("<<start<<" "<<end<<")"<<" ";
            maxProfit = 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stockBuySell(arr,n);

    return 0;
}


/*
Input:
N = 7
A[] = { 100, 180, 260, 310, 40, 535, 695 }

Output:
(0 3) (4 6)

Explanation 1:
We can buy stock on day 0, 
and sell it on 3rd day, 
which will give us maximum profit.


Input:
N = 10
A[] = {23, 13, 25, 29, 33, 19, 34, 45, 65, 67}

Output:
(1 4) (5 9)
*/