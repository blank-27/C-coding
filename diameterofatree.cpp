#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int; // use cpp_int as data type for large numbers 
using namespace std;

#define ll long long
#define pb push_back
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<long long>
#define log2(X) (63ll - __builtin_clzll(X))
#define test ll t; cin>>t; while(t--)
#define modInv(n) po(n,mod-2)%mod
#define ncr(n,r) (((fact[n]*modInv(fact[r]))%mod)*modInv(fact[n-r]))%mod
#define fo(i,n) for(i=1;i<n;i++)
// use endl for interactive problems

ll po(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return res%mod;
}

ll n;
vll adj[2*100005];
ll visited[2*100005];
ll res;
ll coun,max_count;
ll dfs(ll i)
{
    coun++;
    if(coun>=max_count)
    {
        max_count=coun;
        res=i;
    }
    visited[i]=1;
    for(auto v: adj[i])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
    coun--;
    return max_count;
}

int main() 
{
    fast()
    //test
    {
       cin>>n;
       ll u,v;
       int i;
       fo(i,n)
       {
           cin>>u>>v;
           adj[u].pb(v);
           adj[v].pb(u);
       }
       dfs(1ll);
       memset(visited,0ll,sizeof(visited));
       coun=0,max_count=0;
       ll ans=dfs(res)-1;
       cout<<ans<<"\n";
    }
    return 0;
}
