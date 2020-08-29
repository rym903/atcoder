#include <bits/stdc++.h>
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
    vint a(n);
    rep(i, n) cin >> a[i];

    int freq[2][100005] = {};
    for(int i=0; i<n; i+=2) freq[0][a[i]]++;
    for(int i=1; i<n; i+=2) freq[1][a[i]]++;

    int x1=0, x2=0, y1=0, y2=0;
    int nx, ny;
    rep(i, 100005) {
        if(x1 < freq[0][i]){
            x2 = x1;
            nx = i;
            x1 = freq[0][i];
        }else if(x2 < freq[0][i]){
            x2 = freq[0][i];
        }
    }
    rep(i, 100005) {
        if(y1 < freq[1][i]){
            y2 = y1;
            ny = i;
            y1 = freq[1][i];
        }else if(y2 < freq[1][i]){
            y2 = freq[1][i];
        }
    }

    if(nx != ny) pr(n - x1 - y1);
    else pr(min(n-x1-y2, n-x2-y1));
    return 0;}