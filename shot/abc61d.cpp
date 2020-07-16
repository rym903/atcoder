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
using P = pair<ll, ll>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

// スタート地点からの最短距離を返す。不閉路がある場合はそれも検出できる
// P = pair<cost, to>
int V, E;
arr<P> G;
vector<ll> dist;
void BellmanFord(int st, bool& has_negative, int k){
    rep(i, V) dist[i]=INFL;
    dist[st] = 0;
    bool update=true;
    has_negative = false;

    int cnt=0;
    while(update){
        update = false;
        cnt++;
        if(cnt==k) {has_negative=true; return;}
        rep(i, V){
            if(dist[i]==INFL) continue;
            for(auto e: G[i]){
                if(dist[e.second] > dist[i]+e.first){
                    dist[e.second] = dist[i] + e.first;
                    update = true;
                }
            }
        }
    }

    return;
}
int main()
{
    cin >> V >> E;
    dist.resize(V);
    G.resize(V);
    rep(i, E){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({-c, b});
    }

    bool flag=false;
    BellmanFord(0, flag, V);
    ll ans = dist[V-1];
    BellmanFord(0, flag, V+1);
    if(ans != dist[V-1]) pr("inf");
    else pr(-ans);
    return 0;}