#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define sidha(i,x,n) for(ll i=(ll)(x);i<(ll)(n);++i)
#define ulta(i,x,n) for(ll i=(ll)(x);i>=(ll)(n);--i)
#define sab(a) a.begin(),a.end()
#define bas(a) a.rbegin(),a.rend()
#define test ll _;cin>>_;while(_--)
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF LLONG_MAX
//#define MAX 100005
#define PI (ld)3.141592653589793238
#define MOD INF
//#define MOD (ll)1000000007
//#define MOD (ll)998244353

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void bucket_sort(float a[],int n) 
{ 
    vector<float> arr[n+1]; 
  
    for(int i=0;i<n;i++)
     { 
        int bucket=n*a[i]; 
        arr[bucket].push_back(a[i]); 
    } 

    for (int i=0;i<n;i++)  sort(arr[i].begin(),arr[i].end()); 
      
    int ind=0; 
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<arr[i].size();j++) 
        {
            a[ind++]=arr[i][j]; 
        }      
    }         
}

void toh(int n, char from, char to, char aux){
    if(n==1)
	{   // single disc left
        cout<<"Transfer the disc 1 from "<<
        from<<" to "<<to; 
        cout<<endl;
	}
	else
	{
		toh(n-1,from,aux,to);
        cout<<"Transfer the disc "<<
        n<<" from "<<from<<" to "<<to;
        cout<<endl;
		toh(n-1,aux,to,from);
	}
}

int main()
{
    jaldi;
    
    freopen("best.txt", "w", stdout);
    
    cout << 1 << '\n';

    // cout << 100 << '\n';
    // sidha (i, 1, 101) cout << i << ' ';
    // cout << '\n';

    // cout << 1000 << '\n';
    // sidha (i, 1, 1001) cout << i << ' ';
    // cout << '\n';

    // cout << 5000 << '\n';
    // sidha (i, 1, 5001) cout << i << ' ';
    // cout << '\n';

    // cout << 10000 << '\n';
    // sidha (i, 1, 10001) cout << i << ' ';
    // cout << '\n';

    // cout << 30000 << '\n';
    // sidha (i, 1, 30001) cout << i << ' ';
    // cout << '\n';

    cout << 50000 << '\n';
    sidha (i, 1, 50001) cout << i << ' ';
    cout << '\n';

    // cout << 70000 << '\n';
    // sidha (i, 1, 70001) cout << i << ' ';
    // cout << '\n';

    // cout << 100000 << '\n';
    // sidha (i, 1, 100001) cout << i << ' ';
    // cout << '\n';

    // cout << 2000000 << '\n';
    // sidha (i, 1, 2000001) cout << i << ' ';
    // cout << '\n';

    return 0;
}
