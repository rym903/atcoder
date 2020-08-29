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

int v, e;
int dp[1<<15][15];
int G[15][15];

int dfs(int s, int t){
    // cout << bitset<3>(s) << ": " << t << ": " << dp[s][t] << endl;

    if(dp[s][t]>=0) return dp[s][t];
    
    if(s==(1<<v)-1 && t==0){
        return dp[s][t] = 0;
    } 

    int m = INF;
    // pr(v);
    rep(i, v){
        if(!((s>>i)&1) && G[t][i]!=INF){
            m = min(m, dfs(s|(1<<i), i) + G[t][i]);
        }
    }
    return dp[s][t] = m;
}

int main()
{
    cin >> v >> e;
    rep(i, 15) rep(j, 15) G[i][j] = INF;
    rep(i, 1<<15) rep(j, 15) dp[i][j] = -1;
    rep(i, e){
        int a, b, c;    
        cin >> a >> b >> c;
        G[a][b] = c; 
    }
    // rep(i, v){
    //     if(G[0][i]==INF) continue;
    //     dp[1<<i][i] = G[0][i];
    //     cout << "dp[" << bitset<3>(1<<i) << "][" << i << "]=" << G[0][i] << endl;
    // }
    int ans = dfs(0, 0);
    if(ans==INF) pr(-1);
    else pr(ans);
    return 0;}