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

int main()
{
    int h, w; cin >> h >> w;
    vector<string> p(h);
    rep(i, h) cin >> p[i];

    //行iにあるOrbの累積和
    arr<ll> orb(h, vector<ll>(w, 0)); 
    //列jにあるIngotの累積和
    arr<ll> ingot(h, vector<ll>(w, 0));

    rep(i, h){
        if(p[i][0]=='O') orb[i][0]++;
    } 
    FOR(i, 0, h) FOR(j, 1 ,w){
        orb[i][j] += orb[i][j-1];
        if(p[i][j]=='O') orb[i][j]++;
    }

    rep(i, w){
        if(p[0][i]=='I') ingot[0][i]++;
    } 
    FOR(i, 1, h) FOR(j, 0 ,w){
        ingot[i][j] += ingot[i-1][j];
        if(p[i][j]=='I') ingot[i][j]++;
    }

    // prarr(orb);
    // prarr(ingot);

    ll ans = 0;
    rep(i, h) rep(j, w){
        // printf("%d, %d, %lld\n", i, j, ans);
        if(p[i][j]!='J') continue;
        ans += (orb[i][w-1] - orb[i][j]) * (ingot[h-1][j] - ingot[i][j]);
    }
    pr(ans);
    return 0;}