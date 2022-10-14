#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int p=1;
    int ans=0;
    while(N>0){
        int j=N%10;
        j=j*p;
        p=p*2;
        ans =ans+j;
        N=N/10;
    }
    cout<<ans;
}
