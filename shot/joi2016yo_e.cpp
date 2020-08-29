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

using P = pair<int, int>;
int V, E;
arr<P> G;
vector<ll> dist;
vector<bool> seen;
ll p, q;
vector<bool> zomb;
vector<bool> danger;
int n, m, k, s; 
void dijkstra(int st)
{
    priority_queue<P, vector<P>, greater<P>> min_heap;
    min_heap.push({0, st});
    rep(i, V) seen[i] = false;
    rep(i, V) dist[i] = INF;
    dist[st] = 0;

    int frm, d;
    while(!min_heap.empty()){
        tie(d, frm) = min_heap.top(); min_heap.pop();
        if(seen[frm]) continue;

        // printf("node=%d", frm);
        seen[frm] = true;
        dist[frm] = d;

        for(P e: G[frm]){
            if(zomb[e.second]) continue;

            int cost;
            if(danger[e.second]) cost = q;
            else cost = p;
            if(e.second==n-1) cost = 0;

            if(dist[e.second] > d+cost)
                min_heap.push({d+cost, e.second});
                // printf("(%d, %d) pushed", d+e.first, e.second);
        }
    }
}
vector<int> c;
arr<int> g;


int main()
{
    cin >> n >> m >> k >> s;
    cin >> p >> q;
    c.resize(k);
    danger.assign(n, false);
    zomb.assign(n, false);
    rep(i, k) {cin >> c[i]; c[i]--;}
    rep(i, k) zomb[c[i]] = true;
    // sort(ALL(c));

    g.resize(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // dangerを構成
    queue<int> que;
    rep(i, k) que.push(c[i]);
    rep(i, s){
        queue<int> q_n;
        while(!que.empty()){
            int t = que.front(); que.pop();
            for(int a: g[t]){
                if(danger[a]) continue;
                danger[a] = true;
                q_n.push(a);
            }
        }
        que = q_n;
    }

    // Gを構成
    V = n;
    E = m;
    dist.resize(n);
    seen.resize(n);
    G.resize(n);
    rep(i, n){
        for(int j: g[i]){
            G[i].push_back({1, j});
        }
    }

    dijkstra(0);

    pr(dist[n-1]);

    return 0;}