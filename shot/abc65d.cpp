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
struct P {
    int x, y, i;
};

int dist(P c, P d){
    return min(abs(c.x - d.x), abs(c.y - d.y));
}

struct edge {
    int from, to;
    ll cost;
};

ll prim(vector<vector<edge>> &edges, int V) {
    using Pi = pair<ll, int>;

    ll res = 0;
    vector<bool> used(V, false);
    priority_queue<Pi, vector<Pi>, greater<>> priorityQueue;
    priorityQueue.emplace(0, 0);
    while (!priorityQueue.empty()) {
        Pi p = priorityQueue.top();
        priorityQueue.pop();
        if (used[p.second]) continue;
        used[p.second] = true;
        res += p.first;
        for (edge &e : edges[p.second]) {
            if (!used[e.to]) priorityQueue.push({e.cost, e.to});
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<P> a(n), b(n);
    rep(i, n){
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
        b[i] = a[i];
    }

    sort(ALL(a), [](const P &s, const P &t){
        return s.x < t.x;
    });
    sort(ALL(b), [](const P &s, const P &t){
        return s.y < t.y;
    });

    // rep(i, n){
    //     cout << "(" << a[i].x << ", " << a[i].y << ") " << a[i].i << endl; 
    // }
    // pr("");
    // rep(i, n){
    //     cout << "(" << b[i].x << ", " << b[i].y << ")" << b[i].i << endl; 
    // }

    vector<vector<edge>> edges(n);
    rep(i, n-1){
        P c, d;
        c = a[i];
        d = a[i+1];
        edges[c.i].push_back({c.i, d.i, dist(c, d)});
        edges[d.i].push_back({d.i, c.i, dist(c, d)});
        // printf("%d %d\n", c.i, d.i;
        c = b[i];
        d = b[i+1];
        edges[c.i].push_back({c.i, d.i, dist(c, d)});
        edges[d.i].push_back({d.i, c.i, dist(c, d)});
    }

    rep(i, n){
        // cout << i << ": ";
        rep(j, edges[i].size()){
            edge e = edges[i][j];
            // printf("%d ", e.to);
        }
        // pr("");
    }

    ll ans = prim(edges, n);

    pr(ans);
    return 0;
}