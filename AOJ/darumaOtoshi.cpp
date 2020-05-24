#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
void print(int x){printf("%d\n", x);}
void print(ll x){printf("%lld\n", x);}
void printvec(vector<int> a){
rep(i, a.size()-1){
printf("%d ", a[i]);
}
printf("%d\n", a[a.size()-1]);
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
vector<vector<int>> dp;
vector<int> w;

int main()
{
    int n;

    while(1){
        cin >> n;
        if(n==0) break;

        dp.resize(n+1);
        rep(i, n+1) dp[i].resize(n);
        rep(i, n+1) rep(j, n) dp[i][j] = INT32_MIN;

        w.resize(n);
        rep(i, n) cin >> w[i];

        FOR(w_, 2, n+1){
            FOR(l, 0, n){
                int r = w_ - l;
                if(r>n) continue;

                if(abs(w[l]-w[r-1])<=1 && dp[l+1][r-1]==l-r-2){
                    dp[l][r] = l-r;
                }

                FOR(mid, l+1, r-1){
                    dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid][r]);
                }
            }
        }
        int ans=0;
        rep(i, n) ans = max(ans, dp[i][n-i]);
        printf("%d\n", ans);
    }
    
    return 0;
}