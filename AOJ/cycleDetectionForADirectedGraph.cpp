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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

arr<int> G;
vector<bool> seen;
bool flag;
int v, e;

void dfs(int s, int k, int n){
    // pr(s);
    if(n > 0 && s==k){
        flag = true;
        return;
    }
    if(seen[s]) return;
    seen[s] = true;
    for(int j: G[s]){
        dfs(j, k, n+1);
    }
}

int main()
{
    cin >> v >> e;
    G.resize(v);
    int s, t;
    rep(i, e){
        cin >> s >> t;
        G[s].push_back(t);
    }

    rep(i, v){
        flag = false;
        seen.assign(v, false);
        dfs(i, i, 0);
        if(flag) break;
    }

    pr(flag);
    return 0;}