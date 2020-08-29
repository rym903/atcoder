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
struct C{
    int a, b, c;
};

int main()
{
    int d, n; cin >> d >> n;
    vector<int> t(d);
    vector<C> abc(n);
    rep(i, d) cin >> t[i];
    rep(i, n){
        int a, b, c; cin >> a >> b >> c;
        abc[i] = {a, b, c};
    }

    int dp[d][n];
    rep(i, d) rep(j, n) dp[i][j] = -INF;
    rep(i, n) if(!(t[0] < abc[i].a || abc[i].b < t[0])) dp[0][i]=0;

    // rep(j, n) printf("%d ", dp[0][j]);
    // pr(" ");

    FOR(i, 1, d){
        rep(j, n){
            if(t[i] < abc[j].a || abc[j].b < t[i]) continue;
            rep(k, n){
                chmax(dp[i][j], dp[i-1][k] + abs(abc[k].c - abc[j].c));
            }
        }
        // rep(j, n) printf("%d ", dp[i][j]);
        // pr(" ");
    }

    int ans = -INF;
    rep(i, n) chmax(ans, dp[d-1][i]);
    pr(ans);
    return 0;}