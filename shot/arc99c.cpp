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

int mod(int x, int d){
    if(x%d==0){
        return x/d;
    }else{
        return x/d + 1;
    }
}

int main()
{
    int n, k; cin >> n >> k;
    int l , r;
    rep(i, n){
        cin >> l;
        if(l==1) {l=i; break;}
    }

    int ans = INF;
    for(int i=l-k+1; i<=l; i++){
        if(i<0) continue;
        if(i+k-1>=n) continue;

        int left, right, t;
        left = i;
        right = n - i - k;
        chmin(ans, 1+mod(left, k-1) + mod(right, k-1));
    }   
    pr(ans);
    return 0;}