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
template<class T>void prvec(vector<T>& a){rep(i, a.s  ize()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

arr<int> G, rG;
int v, e;
vector<bool> seen;
vector<int> backed;
vector<int> setnum;

void dfs1(int n){
    seen[n] = true;
    for(auto i: G[n]){
        if(seen[i]) continue;
        dfs1(i);
    }
    backed.push_back(n);
}

void dfs2(int n, int g){
    seen[n] = true;
    setnum[n] = g;
    for(auto i: rG[n]){
        if(seen[i]) continue;
        dfs2(i, g);
    }
}

int main()
{
    cin >> v >> e;
    G.resize(v);
    rG.resize(v);
    seen.resize(v, false);
    setnum.resize(v);
    rep(i, e){
        int f, t; cin >> f >> t;
        G[f].push_back(t);
        rG[t].push_back(f);
    }
    rep(i, v){
        if(seen[i]) continue;
        dfs1(i);
    }
    prarr(G);
    // prvec(backed);

    seen.assign(v, false);
    int group=0;
    for(int i=v-1; i>=0; i--){
        if(seen[backed[i]]) continue;
        dfs2(backed[i], group++);
    }

    // prvec(setnum);

    int q; cin >> q;
    int s, t;
    rep(i, q){
        cin >> s >> t;
        if(setnum[s]==setnum[t]) pr(1);
        else pr(0);
    }
    return 0;}