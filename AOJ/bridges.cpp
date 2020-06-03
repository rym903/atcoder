// 橋を求める
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef pair<int, bool> edge;

int v, e;
vector<vector<edge>> G;
vector<int> ord, low;
set<pair<int, int>> ans;
vector<bool> seen;
int k;
int zero_degree;

void dfs(int u, int r){
    // pr(u);
    seen[u] = true;
    ord[u] = k; k++;
    low[u] = ord[u];
    for(edge &ed: G[u]){
        int v = ed.first;
        if(v==r) continue;
        if(!seen[v]){
            ed.second = true;
            dfs(v, u);
            chmin(low[u], low[v]);
            if(ord[u] < low[v]){
                if(u<=v) ans.insert({u, v});
                else ans.insert({v, u});
            }
        }else if(ed.second==false){
            chmin(low[u], ord[v]);
        }
    }
}
 
int main()
{
    cin >> v >> e;
    G.resize(v); ord.resize(v), low.resize(v); seen.resize(v);

    int a, b;
    rep(i, e){
        cin >> a >> b;
        G[a].push_back({b, false});
        G[b].push_back({a, false});
    }
    rep(i, v) seen[i]=false;
    int k = 0;

    dfs(0, 0 );

    // rep(i, v) seen[i] = false;
    // dfs_search(0);

    // int tmp=0;
    // for(edge ed: G[0]){
    //     if(ed.second) tmp++;
    // }
    // if(tmp>1) ans.insert(0);

    for(pair<int, int> c: ans){
        printf("%d %d\n", c.first, c.second);
    }
    return 0;
}