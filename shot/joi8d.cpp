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
int h, w;
arr<int> f;
int ans=0;
arr<bool> seen;

int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};

void dfs(int x, int y, int s, arr<bool> sn){
    chmax(ans, s);
    // printf("%d %d\n", x, y);
    sn[x][y] = true;
    rep(i, 4){
        int nx = x + dh[i], ny = y + dw[i];
        // printf("%d %d %d %d\n", nx, ny, h ,w);
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

        // printf("%d %d %d %d\n", nx, ny, h ,w);
        if(sn[nx][ny]) continue;
        if(f[nx][ny]==0) continue;
        
        dfs(nx, ny, s+1, sn);
    }
}

int main()
{
    cin >> h >> w;
    f.resize(h, vector<int>(w));
    seen.resize(h, vector<bool>(w, false));
    rep(i, h) rep(j, w){
        cin >> f[i][j];
    }
    // prarr(f);
    rep(i, h) rep(j, w){
        if(f[i][j]==0) continue;
        rep(a, h) rep(b, w) seen[a][b] = false;
        // pr("");
        dfs(i, j, 1, seen);
    }

    pr(ans);
    return 0;}