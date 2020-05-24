#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}


typedef pair<int, int> P;
 
int V, E, st;

void dijkstra(vector<P> G[], bool vis[], ll dist[], int st)
{
    priority_queue<P, vector<P>, greater<P>> min_heap;
    min_heap.push({0, st});
    rep(i, V) vis[i] = false;
    rep(i, V) dist[i] = INT64_MAX;
    dist[st] = 0;

    int frm, d;
    while(!min_heap.empty()){
        tie(d, frm) = min_heap.top(); min_heap.pop();
        if(vis[frm]) continue;

        // printf("node=%d\n", frm);
        vis[frm] = true;
        dist[frm] = d;

        for(P e: G[frm]){
            if(dist[e.second] > d+e.first)
                min_heap.push({d+e.first, e.second});
                // printf("(%d, %d) pushed\n", d+e.first, e.second);
        }
    }
}