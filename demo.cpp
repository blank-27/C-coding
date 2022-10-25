#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

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

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int lcs(char *s1,char *s2)
{
    int n1,n2;
    n1=strlen(s1);
    n2=strlen(s2);
    int dp[n1+2][n2+2];
    for (int i=0;i<=n1;i++)
    {
        for (int j=0;j<=n2;j++)
        {
            if (i==0 || j==0){
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}


int main(){
	int a;
	cin>>a;
	cout<<a;
	return 0;
}
