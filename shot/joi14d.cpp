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


int main()
{
    int n, m; cin >> n >> m;
    ll dp[m+1][n+1]={};
    FOR(i, 0, m+1) rep(j, n+1) dp[i][j] = INFL;
    dp[0][0] = 0;

    vector<ll> d(n), c(m);
    rep(i, n) cin >> d[i];
    rep(i, m) cin >> c[i];

    FOR(i, 1, m+1){
        rep(j, n+1){
            dp[i][j] = dp[i-1][j];
            if(j!=0) chmin(dp[i][j], dp[i-1][j-1] + d[j-1]*c[i-1]);
        }
    }

    pr(dp[m][n]);
    return 0;}