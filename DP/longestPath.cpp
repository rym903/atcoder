#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void prt(T x){cout << x << endl;}
template<class T>void prtvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<vector<int>> G;
int dp[100100];

int rec(int v){
    if(dp[v]!=-1) return dp[v];
    
    int ans=0;
    for(auto nv: G[v]){
        chmax(ans, rec(nv)+1);
    }
    return dp[v]=ans;
}

int main()
{
    int n, m; cin>>n>>m;
    G.resize(n);
    {
        int x, y;
        rep(i, m){
            cin >> x >> y;
            x--; y--;
            G[x].push_back(y);
        }
    }

    rep(i, n) dp[i]=-1;

    int ans=0;
    rep(i, n) chmax(ans, rec(i));
    prt(ans);
    return 0;
}