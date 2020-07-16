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
    int n, W; cin >> n >> W;
    vector<int> v(n), w(n);
    rep(i, n){
        cin >> v[i] >> w[i];
    }

    arr<int> dp(n+1, vector<int>(W+1, 0));
    FOR(i, 0, n){
        FOR(j, 0, W+1) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j-w[i]>=0) chmax(dp[i+1][j], dp[i][j-w[i]] + v[i]);
        }
        // prarr(dp);
        // pr("");
    }
    pr(dp[n][W]);
    return 0;}