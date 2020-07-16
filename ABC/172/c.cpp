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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    rep(i, n-1) a[i+1] += a[i];
    rep(i, m-1) b[i+1] += b[i];

    int ak=0, bk;
    // aが0冊の時、bから何冊取れるか
    bk = lower_bound(ALL(b), k) - b.begin();
    if(b[bk]!=k) bk--;

    int ans = bk+1;
    FOR(i, 0, n){
        if(a[i] > k) break;
        ak = i;
        for(int j=bk; j>=0; j--){
            if(a[i] + b[j] <= k){
                bk = j;
                break;
            }
            if(j==0) bk=-1;
        }
        // printf("%d, %d\n", ak+1, bk+1);
        chmax(ans, ak+bk+2);
    }
    pr(ans);
    return 0;}