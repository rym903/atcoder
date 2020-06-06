#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e17
#define MAXN (210)
#define WIDTH (421)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef pair<ll, int> edge;
typedef pair<int, int> P;

P xy(int num){
    return {num%MAXN, num/MAXN};
}

int toP(int x, int y){
    return (MAXN + y)*(2*MAXN + 1) + MAXN + x;
}

vector<int> G[WIDTH*WIDTH];
vector<bool> vis(WIDTH*WIDTH);
vector<ll> dist(WIDTH*WIDTH);
vector<bool> wall(WIDTH*WIDTH);

void dijkstra(vector<int> G[], int st)
{
    priority_queue<edge, vector<edge>, greater<edge>> min_heap;
    min_heap.push({0, st});
    rep(i, WIDTH*WIDTH) vis[i] = false;
    rep(i, WIDTH*WIDTH) dist[i] = INFL;
    dist[st] = 0;

    int frm;
    ll d;
    while(!min_heap.empty()){
        tie(d, frm) = min_heap.top(); min_heap.pop();
        if(vis[frm]) continue;

        vis[frm] = true;
        dist[frm] = d;

        for(int e: G[frm]){
            if(dist[e] > 1+d)
                min_heap.push({1+d, e});
        }
    }
}

int main()
{
    int N, X, Y; cin >> N >> X >> Y;
    int x = 0, y = 0;
    int xi, yi;

    rep(i, WIDTH*WIDTH) wall[i] = false;
    rep(i, N){
        cin >> xi >> yi;
        wall[toP(xi, yi)] = true;
    }

    FOR(xi, -MAXN, MAXN+1){
        FOR(yi, -MAXN, MAXN+1){
            FOR(x_, -1, 2){
                FOR(y_, -1, 2){
                    if(x_==0 && y_==0) continue;
                    if(y_==-1 && x_!=0) continue;
                    if(xi+x_ >= -MAXN && xi+x_ < MAXN && yi+y_>=-MAXN && yi+y_ < MAXN){
                        if(wall[toP(xi+x_, yi+y_)]) continue;
                        G[toP(xi, yi)].push_back(toP(xi + x_, yi + y_));
                    }
                }
            }
        }
    }

    dijkstra(G, toP(x, y));

    if(dist[toP(X, Y)] == INFL) printf("-1\n");
    else printf("%lld\n", dist[toP(X, Y)]);

    return 0;
}