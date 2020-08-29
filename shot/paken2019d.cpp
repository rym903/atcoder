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

int main()
{
    int n; cin >> n;
    vector<string> s(5);
    rep(i, 5) cin >> s[i];
    int col[n][4]={};
    
    rep(i, n){
        rep(j, 5){
            if(s[j][i]=='W') col[i][0]++;
            else if(s[j][i]=='R') col[i][1]++;
            else if(s[j][i]=='B') col[i][2]++;
            else col[i][3]++;
        }
    }

    // rep(i, n){
    //     rep(j, 4){
    //         printf("%d ", col[i][j]);
    //     }
    //     pr("");
    // }

    int dp[n][3] = {};
    FOR(i, 1, n) rep(j, 3) dp[i][j] = INF;

    rep(c, 3) {
        rep(d, 4){
            if(c==d) continue;
            dp[0][c] += col[0][d];
        }
    }


    FOR(i, 1, n){
        rep(c, 3){
            int k=0;
            rep(d, 4){
                if(c==d) continue;
                k += col[i][d];
            }

            rep(d, 3){
                if(c==d) continue;
                chmin(dp[i][c], dp[i-1][d] + k);
            }
        }
    }

    // rep(i, n){
    //     rep(j, 3){
    //         printf("%d ", dp[i][j]);
    //     }
    //     pr("");
    // }

    int ans=INF;
    rep(i, 3) chmin(ans, dp[n-1][i]);
    pr(ans);
    return 0;}