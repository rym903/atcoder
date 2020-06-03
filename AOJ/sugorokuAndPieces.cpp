#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n, m; cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    cin >> m;
    vector<bool> p(2020, false);
    rep(i, n) p[x[i]] = true;
    
    int a;
    rep(i, m){
        cin >> a;
        a--;
        if(x[a]==2019) continue;
        if(p[x[a]+1]) continue;
        swap(p[x[a]], p[x[a]+1]);
        x[a]++;
    }

    FOR(i, 0, n) cout << x[i] << endl;
    return 0;
}