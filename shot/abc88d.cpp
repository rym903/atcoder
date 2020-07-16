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
struct pt{
    int x, y, c;
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int h, w; 
vector<string> fld;

void bfs(){
    int blk = 0;
    rep(i, h) rep(j, w) if(fld[i][j]=='#') blk++;
    arr<bool> seen(h, vector<bool>(w, false));
    seen[0][0] = true;
    queue<pt> que;
    que.push({0,0,0});

    while(!que.empty()){
        pt p = que.front(); que.pop();
        rep(i, 4){
            int x = p.x + dx[i], y = p.y + dy[i];
            // printf("%d, %d, %d\n", x, y, p.c);
            if(x < 0 || x >= h || y < 0 || y >= w) continue;
            if(fld[x][y]=='#') continue;
            if(x == h-1 && y == w-1){
                int need = p.c + 2;
                // printf("%d %d %d\n", blk, need, h*w);
                pr(h*w - need - blk);
                return;
            }
            if(seen[x][y]) continue;
            seen[x][y] = true;
            que.push({x, y, p.c+1});
        }
    }
    pr(-1);
    return;
}

int main()
{
    cin >> h >> w;
    rep(i, h) {
        string s; cin >> s;
        fld.push_back(s);
    }
    // rep(i, h) pr(fld[i]);
    bfs();
    return 0;}