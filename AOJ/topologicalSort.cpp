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

struct edge{
    int to;
    bool f;
};

vector<vector<edge>> G;

int main()
{
    int v, e;
    cin >> v >> e;
    G.resize(v);
    vector<int> iri(v, 0);

    rep(i, e){
        int from, to; cin >> from >> to;
        G[from].push_back({to, true});
        iri[to]++;
    }

    queue<int> que;
    rep(i, v) if(iri[i]==0) que.push(i);
    vector<int> res;

    while(!que.empty()){
        int a = que.front(); que.pop();
        res.push_back(a);

        for(auto ed: G[a]){
            iri[ed.to]--;
            if(iri[ed.to]==0) que.push(ed.to);
        }
    }

    rep(i, v){
        cout << res[i] << endl;
    }
    // prvec(res
    return 0;}