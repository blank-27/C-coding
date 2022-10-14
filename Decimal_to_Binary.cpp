#include <iostream>
using namespace std;

int main(){
    long N;
    cin>>N;
    long ans=0;
    long p=1;
    while(N>0){
        long j=N%2;
        j=j*p;
        p=p*10;
        ans= ans+j;
        N=N/2;
    }
    cout<<ans;
}
