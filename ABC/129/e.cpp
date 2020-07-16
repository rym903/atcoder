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

const int MAX = 100005;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main()
{
    COMinit();
    string l; cin >> l;
    int n = l.length();
    vector<int> dp1(n+1, 0), dp2(n+1, 0);

    dp1[0] = 1; dp2[0] = 0;
    rep(i, n){
        if(l[n-1-i]=='1'){
            dp1[i+1] = (2*dp1[i])%MOD + (dp1[i] + dp2[i])%MOD;
            dp2[i+1] = 2*dp2[i];
        }else{
            dp1[i+1] = dp1[i];
            dp2[i+1] = ((2*dp1[i])%MOD + (2*dp2[i])%MOD)%MOD + dp2[i]; 
        }
        dp1[i+1] %= MOD;
        dp2[i+1] %= MOD;
    }
    pr(dp1[n]);
    return 0;}