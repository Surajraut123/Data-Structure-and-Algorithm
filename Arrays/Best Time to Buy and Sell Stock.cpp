#include <iostream>
using namespace std;

void SellBuy(int *arr, int n) {
    int curProfit = 0;
    int maxProfit = 0;
    int buy = arr[0];
    int sell = 0;
    int b = 0;
    for(int i=0; i<n ;i++) {
        if(arr[i] < buy) {
            buy = arr[i];
            b=i;
        }

        curProfit = arr[i] - buy;
        if(curProfit > maxProfit) {
            maxProfit = curProfit;
            sell = i;
        }
    }

    cout<<"Best Time of Buy at "<<b<<" day and Sell the Stock at "<<sell<<" day"<<endl;
    cout<<"Maximum Profit is : "<<maxProfit<<endl;
}

int main() {

    int n;
    cin>>n;
    int *arr = new int[n];

    cout<<"Days of selling and Buy Stock : ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    SellBuy(arr, n);

}