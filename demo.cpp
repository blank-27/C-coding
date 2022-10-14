#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[]) {

    for(int i=1;i<n;i++) {
        int val=arr[i];     // we will find current accurate location of this value in sorted array
        int j=i-1;
        for( ;j>=0;j--) {
            if(val>=arr[j]){  // means previous element is not more than val so this is exact location of val
                break;
            }
            arr[j+1]=arr[j]; 
        }
        arr[j+1]=val;
    }

}

int main(){
	int a;
	cin>>a;
	cout<<a;
	return 0;
}
