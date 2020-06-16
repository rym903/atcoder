#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e12)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll dp[410][410];
ll size[410];
ll a[410];

ll dfs(int l, int r){
    if(l==r) {
        printf("a\n");
        return 0;
    }
    if(dp[l][r] != INFL) {
        printf("b\n");
        return dp[l][r];
    }
    ll cost = size[r] - size[l-1];
    ll tot = INFL;
    FOR(k, l, r){
        chmin(tot, dfs(l, k) + dfs(k+1, r) + cost);
    }
    return dp[l][r] = tot;
}
 
int main()
{
    int n; cin >> n;
    rep(i, n){
        cin >> a[i];
        if(i==0) size[i] = a[i];
        else size[i] = size[i-1] + a[i];
    }
    rep(i, n) rep(j, n) dp[i][j] = INFL;
    pr(dfs(0, n-1));
    return 0;}