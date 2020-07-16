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
using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    arr<int> dist(h, vector<int>(w, INF));
    arr<int> c(h, vector<int>(w, 0));
    int sh, sw, gh, gw;
    rep(i, h) rep(j, w){ 
        if(s[i][j]=='s') {sh = i; sw = j; c[i][j]=0;}
        else if(s[i][j] == 'g') {gh = i; gw = j; c[i][j]=0;}
        else if(s[i][j] == '.') c[i][j] = 0;
        else c[i][j] = 1;
    } 
    dist[sh][sw] = 0;
    queue<P> que;
    que.push({sh, sw});
    while(!que.empty()){
        int x, y; tie(x, y) = que.front(); que.pop();
        int d = dist[x][y];
        rep(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny] <= dist[x][y] + c[nx][ny]) continue;
            dist[nx][ny] = dist[x][y] + c[nx][ny];
            que.push({nx, ny});
        }
    }
    // prarr(dist);
    if(dist[gh][gw] > 2) pr("NO");
    else pr("YES");
    return 0;}