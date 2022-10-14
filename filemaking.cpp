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
