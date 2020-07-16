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
    ll m = n;

    if(m%2==0){
        n /= 2;
        m /= 2;
        while(m!=1 && m%2==0){
            m /= 2;
        }
    }
    // pr(m);
    for(ll div=3; div*div<m; div+=2){
        if(m%div==0){
            // pr(div);
            n = n*(div-1)/div;
            m/=div;
            while(m!=1 && m%div==0) m/=div;
        }
    }

    if(m>1) n=n*(m-1)/m;

    pr(n);
    return 0;}