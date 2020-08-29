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
int dist_from_neighbor(vector<int>& a, int v){
    int t = lower_bound(ALL(a), v) - a.begin();
    if(a[t]==v) return 0;
    if(t==0) return abs(v-a[t]);
    if(t==a.size()) return abs(v - a[t-1]);
    return min(abs(v-a[t-1]), abs(v-a[t]));
}

int main()
{
    vector<int> linex = {0} ,liney={0,3}, x = {1, 3}, y = {2, 3};
    int dx=INF, dy=INF;
    rep(i, 2){
    rep(i, linex.size()){
        chmin(dx, (int)abs(linex[i]-x[i])); 
    }
    rep(i, liney.size()){
        chmin(dy, (int)abs(liney[i]-y[i])); 
    }
    printf("%d, %d, %d, %d\n", x[i], dx, y[i], dy);
    }
    return 0;}