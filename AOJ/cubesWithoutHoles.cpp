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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

bool cub[500][500][500];
void solve(int n, int h){
    rep(i, n) rep(j, n) rep(k, n) cub[i][j][k] = true;

    string c;
    int a, b;
    rep(i, h){
        cin >> c >> a >> b;
        a--; b--;
        if(c == "xy") {
            rep(i, n) cub[a][b][i] = false;
        }else if(c == "xz"){
            rep(i, n) cub[a][i][b] = false;
        }else{
            rep(i, n) cub[i][a][b] = false;
        }
    }

    int ans = 0;
    rep(i, n) rep(j, n) rep(k, n) ans += cub[i][j][k];
    pr(ans);
    return;
}

int main()
{
    int n, h;
    while(cin >> n >> h){
        if(n==0 && h==0) break;
        solve(n, h);
    }
    return 0;}