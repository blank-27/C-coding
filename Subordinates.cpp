// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.hi(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << "=" << a << ", ";
    err(++it, args...);
}

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> template <typename T> \
                    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fastIO()                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

#define rep(a, b, c) for (int a = b; a < c; ++a)
#define repn(a, b, c) for (int a = b; a <= c; ++a)
#define repr(a, b, c) for (int a = b; a >= c; --a)
#define repeach(itr, data_st) for (auto itr : data_st)
#define MAX(a, b, c) max(a, max(b, c))
#define MIN(a, b, c) min(a, min(b, c))

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)

#define sq(x) ((ll)(x) * (x))
#define gcd(a, b) __gcd(a, b)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert
#define vecsize(v) v.size()
#define arrsize(arr) (sizeof(arr) / sizeof(arr[0]))
#define init(arr, val) memset(arr, val, sizeof(arr))
#define vecsort(v) sort(v.begin(), v.hi())
#define vecrev(v) reverse(v.begin(), v.hi())
#define arrsort(arr, len) sort(arr, arr + len)
#define w(t) while (t--)
#define nl "\n"
#define mod 1000000007

const lli inf = 1e17;
const lli infll = LLONG_MAX;
const lli infi = INT_MAX;

#define dug(a) cout << a << " ";
#define dugp(a, b) cout << a << " " << b << " ";

inline string getString(void)
{
    char x[1000005];
    scanf("%s", x);
    return (string)x;
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

void dnl()
{
    cout << nl;
}

// for graph///////////////////////////////////////////////////////////////////////////////
vector<int> g[200010];
vector<int> vis(100005, 0);
vector<int> dist(200010, 0);

void gsolve(lli test)
{
    lli n, ans;
    // cin >> n;
    see(n);
    // cout << "Case #" << test << ": " << ans << nl;
}


int dfs(int x){
    if(g[x].size()==0)return 1;
    for(auto it:g[x]){
        dist[x]+=dfs(it);
        // dist[x]+=dist[it];
    }

    return dist[x]+1;
}

void solve()
{
    lli n;
    see(n);

    // vector<int> g[n+1];
    rep(i,0,n-1 ){
        int x;
        cin>>x;
        g[x].pb(i+2);
    }

    dist[1] = dfs(1)-1;
    // dist[]
    rep(i,1,n+1){
        cout<<dist[i]<<" ";
    }


}

int main()
{
    // fastIO();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #hiif

    int test = 1;
    // cin >> test;
    w(test)
    {
        solve();
    }
    // repn(i,1,test){
    //     gsolve(i);
    // }
}

// void dpsolve(){
//     lli n,x;
//     cin>>n>>x;
//     lli a[n];
//     rep(i,0,n){
//         cin>>a[i];
//     }
//     int t[n+1][x+1];

//     rep(i,0,n){
//         rep(j,0,x){
//             if(i==0||j==0)t[i][j]=;
//             else {
//                 if(j>=a[i]){
//                     t[i][j]=t[i][j-a[i-1]];
//                 }else{
//                     t[i][j]=t[i-1][j];
//                 }
//             }
//         }
//     }

//     cout<<t[n][j]<<nl;

// }

/*
void make_graph1(int m){
    rep(i,0,m){
        lli a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
}

void bfs1(int i){
    queue<int> q;
    q.push(i);
    vis[i]=1;

    // dug(i);

    while(!q.empty()){
        auto ii= q.front();
        q.pop();
        dug(ii);

        repeach(it,g[ii]){
            if(vis[it]!=1){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

////////////////DFS////////////////////

void dfs(int x){
    vis[x]=1;
    dug(x);
    repeach(it,g[x]){
        if(vis[it]!=1){
            dfs(it);
        }
    }
}
*/
/////////////////////////////////////////////////////////////////////////////////////////
///////////SEgement treee//////////////////
/*
void build(lli i,lli l,lli r){
    if(l==r){
        lli tp=2*i + 1;
        seg[i]=a[l];
        return ;
    }
    lli mid = l + (r-l)/2;
    // put(mid);
    lli tp = 2*i;
    build(tp + 1, l, mid);
    build(tp + 2, mid+1, r);

    seg[i]=min(seg[2*i +1],seg[2*i +2]);

}




lli segmentTree(lli i,lli l,lli r,lli x,lli y){
    if(l>=x && r<=y){
        return seg[i];
    }

    if(l>y || x>r ) return INT_MAX;
    lli mid = l + (r-l)/2;
    lli left = segmentTree(2*i +1,l,mid,x,y);
    lli right = segmentTree(2*i + 2, mid+1,r,x,y);

    return min(left,right);
}








*/
/////////////////////////////////////