#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n;
vector<ll> a;
arr<ll> dp;

enum Turn{
    JOI = 0,
    IOI = 1,
};

ll dfs_odd(int left, int right, Turn t){
    if(dp[left][right]!=INFL) return dp[left][right];
    if(t==IOI){
        if(left==right) return dp[left][right] = 0;
        if(a[left] < a[right]) {
            return dp[left][right] = dfs_odd(left, (right-1+n)%n, JOI);
        }else{
            return dp[left][right] = dfs_odd((left+1)%n, right, JOI);
        }
    }

    if(left==right) return dp[left][right] = a[left];

    int l, r;
    l = (left==n-1) ? 0 : left+1;
    r = (right==0) ? n-1 : right-1;
    ll k;
    // k = max(a[left] + dfs_odd((left+1)%n, right, IOI), a[right] + dfs_odd(left, (right-1+n)%n, IOI));
    k = max(a[left] + dfs_odd(l, right, IOI), a[right] + dfs_odd(left, r, IOI));
    return dp[left][right] = k;
}

int main()
{
    cin >> n;
    a.resize(n);
    dp.resize(n, vector<ll>(n, INFL));

    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n){
        rep(w, n) rep(j, n) dp[w][j] = INFL;
        ll k = a[i] + dfs_odd((i+1)%n, (i-1+n)%n, IOI);
        chmax(ans, k);
        // prarr(dp);
        // pr(k);
        // pr("");
    }
    pr(ans);
    return 0;}