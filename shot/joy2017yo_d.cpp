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

int sum[20][110000] = {};
int dp[1<<20] = {};
int sz[20]={};
int n, m;

int main()
{
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
        sum[p[i]][i]++;
        sz[p[i]]++;
    }

    rep(i, m) FOR(j, 1, n){
        sum[i][j] += sum[i][j-1];
    }
    // rep(i, m) pr(sum[i][n-1]);
    rep(i, 1<<20) dp[i] = INF;
    dp[0] = 0;

    rep(bit, 1<<m){
        int pos = 0;
        rep(i, m) if((bit>>i)&1) pos += sz[i];
        rep(i, m){
            if((bit>>i)&1) continue;
            chmin(dp[bit|(1<<i)], dp[bit] +  sz[i] - (sum[i][pos+sz[i]-1] - sum[i][pos-1]));
        }
    }

    pr(dp[(1<<m)-1]);
    return 0;}
