#include<iostream>
#include<vector>
using namespace std;


// T.C = O(n), S.C = O(n);

void rearrange(int arr[], int n) {
	vector<int> pos;
	vector<int> neg;
	int k=0, j=0;
	for(int i=0;i<n;i++) {
		if(arr[i] < 0){
			neg.push_back(arr[i]);
		}
		else{
			pos.push_back(arr[i]);
		}
	}
	
	int i=0, p=0, x=0;
	while(x<neg.size() && p<pos.size()) {
		
		arr[i] = pos[p];
		i++;
		p++;
		arr[i] = neg[x];
		x++;
		i++;
	}
	
	while(p<pos.size()){
		arr[i] = pos[p];
		p++;
	}
	   
}

// T.C = O(n) , S.C = O(1);
void rightRotate(int *arr, int from, int to) {
	int tmp = arr[from];
	for(int i=to; i>from; i--) {
		arr[i] = arr[i-1];
	}
	arr[from] = tmp;
}

void reArrange(int arr[], int n) {
	int wrongIndex = -1;
	for(int i=0 ;i<n ;i++) {
		if (wrongIndex !=-1) {
			if((arr[wrongIndex]>=0 && arr[i] <0) || (arr[wrongIndex] < 0 && arr[i]>=0)) {
				rightRotate(arr,wrongIndex, i);
			}
			if(wrongIndex - i>=2){
				wrongIndex +=2;
			}
			else{
				wrongIndex = -1;
			}
		}
		else
		{
			if ((arr[i]<0 && i%2==1) || (arr[i]>=0 && i%2==0))
			{			
				wrongIndex = -1;
			}
			
		}
		
	}
}


int main() {
    int n,m;
    cout<<"Size ofArray : ";
    cin>>n;
    int arr[n];
    cout<<"Element in Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    rearrange(arr,n);
}