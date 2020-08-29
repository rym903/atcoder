#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dp[110][110] = {};
int main()
{
    int r, c; cin >> r >> c;
    int m[r+1][c+1] = {};
    rep(i, r){
        string s;cin >> s;
        rep(j, c){
            if(s[j]=='#') m[i][j]=1;
        }
    }
    rep(i, r) rep(j, c) dp[i][j] = INF;
    dp[0][0] = m[0][0];
    rep(i, r) rep(j, c){
        int cost = 0;
        if(m[i][j] == 0 && m[i+1][j] == 1) cost = 1;
        chmin(dp[i+1][j], dp[i][j]+cost);
        cost = 0;
        if(m[i][j] == 0 && m[i][j+1] == 1) cost = 1;
        chmin(dp[i][j+1], dp[i][j]+cost);
    }

    pr(dp[r-1][c-1]);
    return 0;}