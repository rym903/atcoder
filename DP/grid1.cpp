#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void p(T x){cout << x << endl;}
template<class T>void pvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<class T>void parr(vector<vector<T>>& a){
rep(i, a.size()){
rep(j, a[i].size()){
cout << a[i][j]; printf(" ");}
printf("\n");} printf("\n");}
 
int main()
{
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    rep(i, h){
        rep(j, w) cin >> a[i][j];
    }

    vector<vector<ll>> dp(h, vector<ll>(w));
    rep(i, h) rep(j, w) dp[i][j]=0;
    if(a[0][1]=='.') dp[0][1]=1;
    if(a[1][0]=='.') dp[1][0]=1;
    // parr(dp);
    rep(i, h){
        rep(j, w){
            if(a[i][j]=='#') continue;
            if(i>0 && a[i-1][j]=='.') dp[i][j] += dp[i-1][j]%MOD;
            if(j>0 && a[i][j-1]=='.') dp[i][j] += dp[i][j-1]%MOD;
            dp[i][j] %= MOD; 
        }
    }

    p(dp[h-1][w-1]);
    return 0;
}