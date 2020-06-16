#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e16
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
arr<int> land;
int ans;
int h, w;

void dfs(int x, int y){
    land[x][y] = 0;
    FOR(i, -1, 2){
        FOR(j, -1, 2){
            if(i==0 && j==0) continue;
            if(x+i < 0 || x+i >= h || y+j < 0 || y+j >= w) continue;
            if(land[x+i][y+j]==1){
                dfs(x+i, y+j);
            }
        }
    }
}

int main()
{
    while(1){
        cin >> w >> h;
        if(w==0 && h==0) break;
        land.resize(h);
        rep(i, h) land[i].resize(w);

        rep(i, h) rep(j, w) cin >> land[i][j];
        ans = 0;
        rep(i, h) rep(j, w){
            if(land[i][j]==0) continue;
            ans++;
            dfs(i, j);
        }
        pr(ans);
    }
    return 0;}