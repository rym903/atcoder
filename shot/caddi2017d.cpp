#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
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

int main()
{
    int n; cin >> n;
    int k; cin >> k;
    vint a(n), b(n), v;

    rep(i, n) cin >> a[i] >> b[i];
    rep(i, 32){
        if((k>>i)&1) v.push_back(i);
    }

    // cout << bitset<32>(k) << endl;

    ll ans = 0;
    rep(i, n){
        if((k|a[i]) == k) ans += b[i];
    }

    // cout << ans << endl;
    rep(i, v.size()){
        int x = k;
        // kのv[i]番目の1を0にする
        x ^= (1<<v[i]);
        // v[i]以下の桁を全て1にする
        x |= (1<<v[i])-1;

        // cout << bitset<32>(x) << endl;

        ll t = 0;
        rep(j, n){
            if((x|a[j]) == x)  t += b[j];
        }
        // cout << t << endl;

        chmax(ans, t);
    }

    pr(ans);
    return 0;}