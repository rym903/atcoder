#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void p(T x){cout << x << endl;}
template<class T>void pvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef pair<int, int> P;
vector<bool> vis(100, false);
int dist[100];
vector<P> G[100];

// void rec(int st, int r){
//     for(P ed: G[r]){
//         int cost=ed.first, to=ed.second;
//         if(dist[st][r]+cost == dist[st][to]){
//             printf("(%d %d %d) added\n", r, to, cost);
//             ans += cost;
//             rec(st, to);
//         }
//     }
// }

int main()
{
    int v, e, r; cin >> v >> e >> r;
    rep(i, v) dist[i]=INF;
    dist[r] = 0;
    int from, to, cost;
    vector<P> t(v);
    rep(i, v) t[i].first = INF;
    t[r].first = 0;

    rep(i, e){
        cin >> from >> to >> cost;
        G[from].push_back({cost, to});
    }

    rep(k, v){
        rep(i, v){
            for(P ed: G[i]){
                cost = ed.first; to = ed.second;
                if(to == i) continue;
                if(t[to].first > cost){
                    // dist[to] = dist[i] + cost;
                    t[to] = ed;
                }
            }
        }
    }

    // rep(i, v) cout << dist[i] << " ";
    // cout << endl;

    int ans=0;
    rep(i, v){
        // if(i==r) continue;
        cout << i << t[i].second << t[i].first << endl;
        ans += t[i].first;
    }
    cout << ans << endl;
    return 0;
}