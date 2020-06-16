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
template<class T>void prarr(vector<vector<T>>& a){
rep(i, a.size()){
rep(j, a[i].size()){
cout << a[i][j]; printf(" ");}
printf("\n");} printf("\n");}

vector<ll> row, col;
arr<ll> dp;
ll ans = INFL;
int n; 

ll dfs(int l, int r){
    // printf("%lld %lld\n", l, r);
    if(dp[l][r]!=INFL) return dp[l][r];
    if(l==r) return dp[l][r] = 0;
    if(r==l+1) return dp[l][r] = row[l] * col[l] * col[r];

    ll tmp = INFL;
    FOR(k, l, r){
        chmin(tmp, dfs(l, k) + dfs(k+1, r) + row[l] * col[k] * col[r]);
    }

    return dp[l][r] = tmp;
}

int main()
{
    cin >> n;
    row.resize(n); col.resize(n);
    rep(i, n){
        cin >> row[i] >> col[i];
    }
    dp.assign(n, vector<ll>(n, INFL));

    ans = dfs(0, n-1);
    
    prarr(dp);
    pr(ans);
    return 0;}