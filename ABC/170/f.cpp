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
template<class T>void prarr(vector<vector<T>>& a){
rep(i, a.size()){
rep(j, a[i].size()){
cout << a[i][j]; printf(" ");}
printf("\n");} printf("\n");}

int dx[] = {-1, 1, 0 ,0};
int dy[] = {0, 0, -1, 1};
struct node{
    int c, x, y, d, dk;

    friend bool operator< (const node& nx, const node& ny){
        if(nx.c != ny.c) return nx.c < ny.c;
        else return nx.dk > ny.dk;
    }
};

arr<char> G;
arr<int> cost;
int h, w, k;

void dijkstra(int s, int t, int k){
    cost[s][t] = 0;

    priority_queue<node> min_heap;
    min_heap.push({0, s, t, 0, 0});

    while(!min_heap.empty()){
        node nd = min_heap.top(); min_heap.pop();
        if(nd.c > cost[nd.x][nd.y]) continue;

        // prarr(cost);
        // printf("x=%d y=%d c=%d selected\n\n", nd.x, nd.y, nd.c);

        rep(d, 4){
            int dir = 2*dx[d] + dy[d];
            // if(-dir==nd.d) continue;
            FOR(ki, 1, k+1){
                int tox = nd.x + ki*dx[d];
                int toy = nd.y + ki*dy[d];
                if(tox < 0 || tox >= h || toy < 0 || toy >= w) break;
                if(G[tox][toy]=='@') break;

                int new_cost = nd.c + 1;
                if(new_cost < cost[tox][toy]) {
                    cost[tox][toy] = new_cost;
                    // if(dir!=nd.d) 
                    min_heap.push({new_cost, tox, toy, dir, ki});
                    // else if(nd.dk == k) min_heap.push({new_cost, tox, toy, dir, ki});
                    // else min_heap.push({nd.c, tox, toy, dir, nd.dk+1});
                }
            }
        }
    }
}

int main()
{
    cin >> h >> w >> k;
    int s, t, x, y; cin >> s >> t >> x >> y;
    s--; t--; x--; y--;
    G.resize(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> G[i][j];

    cost.resize(h, vector<int>(w, INF));

    dijkstra(s, t, k);

    if(cost[x][y]==INF) pr(-1);
    else pr(cost[x][y]);
    return 0;}