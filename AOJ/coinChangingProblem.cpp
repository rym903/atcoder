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
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    sort(ALL(a));

    if(n % a[m-1]==0){
        pr(n/a[m-1]);
        return 0;
    }

    arr<int> dp(m, vector<int>(n+1, 0));
    rep(i, m) rep(j, n+1) dp[i][j] = j;

    FOR(i, 1, m){
        // prarr(dp);
        // pr(a[i]);
        FOR(j, 1, n+1){
            // dp[i][j] = dp[i-1][j];
            int k = j/a[i];
            FOR(ki, 0, k+1) chmin(dp[i][j], dp[i-1][j - ki*a[i]]+ki);
        }
    }
    pr(dp[m-1][n]);
    return 0;}