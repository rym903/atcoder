#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (10007)
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

bool is_match(int bit, char c){
    int t;
    if(c=='J') t = 1<<2;
    else if(c=='O') t = 1<<1;
    else t = 1;
    // cout << bitset<32>(bit) << endl;
    // cout << bitset<32>(t) << endl;
    return bit&t;
}

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int dp[n][8] = {};

    rep(i, 8){
        char c = s[0];
        if(is_match(i, c) && is_match(i, 'J')) dp[0][i] = 1;
    }
    // pr(is_match(4, 'J'));

    FOR(i, 1, s.size()){
        char c = s[i];
        rep(bit, 8){
            if(!is_match(bit, c)) continue;
            rep(prev, 8){
                if(prev&bit) {
                    dp[i][bit] += dp[i-1][prev];
                    dp[i][bit] %= MOD;
                }
            }
        }
    }

    // rep(i, n){
    //     rep(j, 8){
    //         printf("%d ", dp[i][j]);
    //     }
    //     pr("");
    // }
    int ans = 0;
    rep(i, 8) ans += dp[n-1][i];
    pr(ans%MOD);
    return 0;}