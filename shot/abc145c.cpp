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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1) * (y2-y1));
}

int main()
{
    int n; cin >> n;
    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<int> a(n);
    rep(i, n) a[i] = i;
    int k=1;
    FOR(i, 1, n+1) k*=i; 
    double ans = 0;
    rep(i, k){
        double d = 0;
        rep(j, n-1) d += dist(x[a[j]], y[a[j]], x[a[j+1]], y[a[j+1]]);
        // pr(d);
        ans += d;
        next_permutation(ALL(a));
    }
    printf("%.10lf", ans/k);
    return 0;}