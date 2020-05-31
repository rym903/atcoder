#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void print(T x){cout << x << endl;}
template<class T>void printvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n; cin>>n;
    vector<vector<int>> a(3, vector<int>(n));
    rep(i, n) cin >> a[0][i] >> a[1][i] >> a[2][i];

    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    rep(i, 3) dp[0][i]=0;

    FOR(i, 1, n+1){
        rep(j, 3){
            rep(k, 3){
                if(j==k) continue;
                chmax(dp[i][j], dp[i-1][k]+a[j][i-1]);
            }
        }
    }

    print(max(dp[n][0], max(dp[n][1], dp[n][2])));
    return 0;
}