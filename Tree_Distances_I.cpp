#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define fo(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define wt while(t--) 
#define vll vector<ll>
#define vls vector<string>
#define mp map<string,string>
#define INF 999999999999999999
#define endl "\n"
#define MOD 1000000007

int sol(string s, string s1){
   int n=s.size();
   vector<int> pref1(n),pref2(n);
   vector<int> suff1(n),suff2(n);
   pref1[0]=s[0]=='x'?1:0;
   pref2[0]=s1[0]=='x'?1:0;
   for(int i=1;i<n;i++)
   {
    if(s[i]=='x')
    {
      pref1[i]=pref1[i-1]+1;
    }
    else
    {
      pref1[i]=pref1[i-1];
    }
    if(s1[i]=='x')
    {
      pref2[i]=pref2[i-1]+1;
    }
    else
    {
      pref2[i]=pref2[i-1];
    }

   }

   suff1[n-1]=s[n-1]=='x'?1:0;
   suff2[n-1]=s1[n-1]=='x'?1:0;
   for(int i=n-2;i>=0;i--)
   {
    if(s[i]=='x')
    {
      suff1[i]=suff1[i+1]+1;
    }
    else
    {
      suff1[i]=suff1[i+1];
    }
    if(s1[i]=='x')
    {
      suff2[i]=suff2[i+1]+1;
    }
    else
    {
      suff2[i]=suff2[i+1];
    }
   }
   int sum=pref1[n-1]+pref2[n-1];

   int mx=INT_MAX;
   for(int i=0;i<n-1;i++)
   {
      mx=min({pref1[i]+suff1[i+1],pref1[i]+suff2[i+1],mx});
      mx=min({pref2[i]+suff1[i+1],pref2[i]+suff2[i+1],mx});
   }
   return sum-mx;
//    cout<<sum-mx<<endl;
}


void solve()
{
ll t=1;
//cin>>t;
wt
{
   string s,s1;
   cin>>s;
   cin>>s1;
   int ans = sol(s,s1);

   cout<<ans<<" ";
   
}
 
}
int main()
{
  ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);  
     

solve();
cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0;
}