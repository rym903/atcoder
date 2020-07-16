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
    ll n; cin >> n;
    ll k = 26;
    ll b = 26;
    int keta=1;
    string ans;
    // 桁数を求める。
    while(k < n) {
        b *= 26;
        k += b;
        keta++;
    }
    // pr(keta);
    // 各桁の数を求める。
    ll base = (ll)pow(26, keta-1);
    //最上位
    ll tmp = n/base;
    char c = 'a';
    if(tmp!=0) c += tmp -1;
    ans.push_back(c);
    n-=tmp*base;
    base /= 26;
    // pr(base);
    rep(i, keta-1){
        ll tmp = n/base;
        // printf("%lld, %lld, %lld\n", n, base, tmp);
        if(tmp>26) tmp = 26;
        char c = 'a';
        if(tmp!=0) c += tmp - 1;
        ans.push_back(c);
        n -= tmp*base;
        base /= 26;
    }
    pr(ans);
    // printf("%d\n", '`'-'a');
    return 0;}