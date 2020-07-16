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
    vector<int> dp(n+1, INF);
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    dp[0] = -1;
    dp[1] = a[0];
    FOR(i, 1, n){
        int p = upper_bound(ALL(dp), a[i]) - dp.begin();
        dp[p] = a[i];
    }
    int ans=-1;
    rep(i, n+1){
        if(dp[i]==INF) {ans = i-1; break;}
    }
    if(ans == -1) ans = n;
    // prvec(dp);
    pr(ans);
    return 0;}