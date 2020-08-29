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
int n;
arr<int> G;
vector<int> x;
int q;
vector<bool> seen;

void dfs(int pp, int k, vector<int>& y){
    seen[k] = true;

    // cout << pp << " " << k << " ";
    // prvec(y);

    if(pp!=-1) y[k] += y[pp];
    y[k] += x[k];
    for(int m: G[k]){
        if(seen[m]) continue;
        dfs(k, m, y);
    }
}

int main()
{
    cin >> n >> q;
    G.resize(n);
    x.resize(n, 0);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, q){
        int p, t; cin >> p >> t;
        p--;
        x[p]+=t;
    }
    seen.assign(n, false);
    vector<int> y(n, 0);
    dfs(-1, 0, y);
    // prvec(x);
    prvec(y);
    return 0;}