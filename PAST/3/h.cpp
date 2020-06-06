#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> hardle(l+10, 0);
    

    int t[3];
    rep(i, 3) cin >> t[i];
    int act[3];
    act[0] = t[0];
    act[1] = t[0] + t[1];
    act[2] = t[0] + 3*t[1];
    rep(i, n) hardle[x[i]] = t[2];

    vector<int> dp(l+10);
    vector<int> acs(l+10);
    rep(i, l+10) dp[i] = INF;
    dp[0] = 0; acs[0]=0;
    int pos = 0;
    FOR(i, 1, l+10){
        int tmp=0;
        if(chmin(dp[i], dp[i-1] + act[0] + hardle[i-1])) acs[i] = 1;
        if(i-2 >= 0 && chmin(dp[i], dp[i-2] + act[1] + hardle[i-2])) acs[i] = 2;
        if(i-4 >= 0 && chmin(dp[i], dp[i-4] + act[2] + hardle[i-4])) acs[i] = 3;
    }

    int m = dp[l];
    if(dp[l] > dp[l-1]+t[0]) m = dp[l-1] + t[0];
    if(acs[l+1]==2 || acs[l+1]==3) chmin(m, dp[l+1] - act[1]/2);
    if(acs[l+2]==3) chmin(m, dp[l+2] - (t[1]*3 + t[0])/2);
    if(acs[l+3]==3) chmin(m, dp[l+3] - (t[1]*5 + t[0])/2);
    pr(m);

    return 0;
}