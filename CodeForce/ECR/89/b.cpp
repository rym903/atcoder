#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e12)
 
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
    int t; cin >> t;
    rep(ti, t){
        int n, m, x; cin >> n >> x >> m;
        int minx = x, maxx = x;
        rep(mi, m){
            if(maxx - minx + 1 == n) {
                int c, d; cin >> c >> d;
                continue;
            }
            int c, d; cin >> c >> d;
            // printf("%d %d %d %d\n", minx, maxx, c, d);
            if(d < minx || c > maxx) continue;
            if(c < minx && maxx < d){
                minx = c;
                maxx = d;
            }else if(c <= maxx && maxx < d){
                maxx = d;
            }else if(c < minx && minx <= d){
                minx = c;
            }
        }
        pr(maxx - minx + 1);
    }
    return 0;}