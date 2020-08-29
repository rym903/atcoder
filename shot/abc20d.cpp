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
void prp(P& p) {cout << p.first << " " << p.second << endl;}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int h, w, t;
vector<string> s;
arr<ll> dist;

bool is_reach(int c, int sx, int sy, int gx, int gy){
    rep(i, h) rep(j, w) dist[i][j] = INFL;
    dist[sx][sy] = 0;
    queue<P> que;
    que.push({sx, sy});

    while(!que.empty()){
        queue<P> n_que;
        while(!que.empty()){
            int x, y;
            tie(x, y) = que.front(); que.pop();
            rep(i, 4){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                int cost=1;
                if(s[nx][ny]=='#') cost = c;
                if(dist[nx][ny] > dist[x][y]+cost){
                    dist[nx][ny] = dist[x][y]+cost;
                    n_que.push({nx, ny});
                }
            }
        }
        que = n_que;
    }

    // cout << "c = " << c << endl;
    // rep(i, h){
    //     rep(j, w){
    //         cout << dist[i][j] << " ";
    //     }
    //     pr("");
    // }
    // pr("");

    if(dist[gx][gy] <= t) return true;
    else return false;
}

int main()
{
    cin >> h >> w >> t;
    s.resize(h);
    rep(i, h) cin >> s[i];
    int sx, sy, gx, gy;
    rep(i, h) rep(j, w){
        if(s[i][j]=='S') {sx=i; sy=j;}
        if(s[i][j]=='G') {gx=i; gy=j;}
    }
    dist.resize(h, vector<ll>(w));

    int left=0, right=t, mid = (left+right)/2;
    int ans = 0;
    while(left<=right){
        bool flg = is_reach(mid, sx, sy, gx, gy);
        if(flg){
            // pr(mid);
            ans = mid;
            left = mid+1;
            mid = (left+right)/2;
        }else{
            right = mid-1;
            mid = (left+right)/2;
        }
    }

    pr(ans);
    return 0;}