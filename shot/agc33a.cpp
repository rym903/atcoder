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
vector<string> a;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int h, w; 

bool is_allb(int i, int j){
    rep(k, 4){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x < 0 || x >= h || y < 0 || y >= w) continue;
        if(a[x][y]=='.') return false; 
    }
    return true;
}

int main()
{
    cin >> h >> w;
    a.resize(h);
    rep(i, h) cin >> a[i];
    queue<P> que;
    int black = 0;
    rep(i, h) rep(j, w) if(a[i][j]=='#'){
        black++;
        if(!is_allb(i, j)) que.push({i, j});
    } 

    int cnt = 0;
    while(black<h*w){
    // while(!que.empty()){
        queue<P> tque;
        cnt++;
        while(!que.empty()){
            P p = que.front(); que.pop();
            rep(k, 4){
                int x = p.first + dx[k];
                int y = p.second + dy[k];
                if(x < 0 || x >= h || y < 0 || y >= w) continue;
                if(a[x][y]=='.') {
                    a[x][y] = '#';
                    black++;
                    if(!is_allb(x,y)) tque.push({x, y});
                }
            }
        }
        que = tque;
    }
    pr(cnt);
    return 0;}