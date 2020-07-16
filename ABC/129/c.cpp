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
 
int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n+1, 0);
    int k;
    rep(i, m){
        cin >> k;
        a[k] = -1;
    }
    if(a[0]!=-1) a[0] = 1;
    if(a[1]!=-1) a[1] = 1;
    FOR(i, 2, n+2){
        if(a[i]==-1) continue;
        FOR(j, 1, 3){
            a[i] += (a[i-j]==-1? 0 : a[i-j]);
        }
        a[i] %= MOD;
    }
    pr(a[n]);
    return 0;}