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
 
int main()
{
    int n, m; cin >> n >> m;
    int x, y;
    bool g[n][n];
    rep(i, n) rep(j, n) g[i][j] = false;
    rep(mi, m){
        cin >> x >> y;
        x--; y--;
        g[x][y] = true;
    }

    ll dp[(1<<n)];
    rep(i, 1<<n) dp[i] = 0;
    dp[0] = 1;
    rep(bit, 1<<n){
        rep(j, n){
            if((bit>>j)&1) continue;
            bool f = true;
            rep(k, n) {
                if(((bit>>k) & 1) && g[j][k]) f = false;
            }
            if(f) dp[bit|(1<<j)] += dp[bit];
        }
    }
    pr(dp[(1<<n) - 1]);
    return 0;}