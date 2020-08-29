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
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    arr<ll> dp(n-1, vector<ll>(21, 0));
    dp[0][a[0]]++;

    FOR(i, 1, n-1) rep(j, 21){
        if(dp[i-1][j]==0) continue;
        if(j + a[i] >= 0 && j + a[i] <= 20) dp[i][j+a[i]] += dp[i-1][j];
        if(j - a[i] >= 0 && j - a[i] <= 20) dp[i][j-a[i]] += dp[i-1][j];
    }

    pr(dp[n-2][a[n-1]]);
    return 0;}