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
using P = pair<ll, ll>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

ll n, m;
P G[15][15];
ll dp[1<<15][15];
ll cnt;
ll md;

ll dfs(int s, int v, ll d){
    if(dp[s][v]!=-1) return dp[s][v];

    if(s==(1<<n)-1 && v==0){
        if(d == md) cnt++;
        else if(d < md) {
            md = d;
            cnt = 1;
        }
        return 0;
    }

    ll a = INFL;
    rep(i, n){
        if(!(s>>i&1) && G[v][i].first!=INFL && d + G[v][i].first <= G[v][i].second){
            a = min(a, dfs(s|(1<<i), i, d+G[v][i].first) + G[v][i].first);
        }
    }

    return dp[s][v] = a;
}

int main()
{
    cin >> n >> m;
    if(n==1) {cout << 0 << " " << 1 << endl; return 0;}
    rep(i, 1<<15) rep(j, 15) dp[i][j] = -1;
    rep(i, 15) rep(j, 15) G[i][j] = {INFL, INFL};
    rep(i, m){
        ll a, b, d, t;
        cin >> a >> b >> d >> t;
        a--; b--;
        G[a][b] = {d, t};
        G[b][a] = {d, t};
    }
    cnt = 0;
    md = INFL;
    ll dist = dfs(0, 0, 0);
    if(dist==-1 || dist==INFL) pr("IMPOSSIBLE");
    else cout << dist << " " << cnt << endl;
    return 0;}