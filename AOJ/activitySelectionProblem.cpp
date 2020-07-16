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
using P = pair<int, int>;
int main()
{
    int n; cin >> n;
    vector<P> s(n);
    rep(i, n) cin >> s[i].second >> s[i].first;
    sort(ALL(s));

    int t=-1, cnt = 0;
    rep(i, n){
        // printf("%d %d\n", s[i].second, s[i].first);
        if(t < s[i].second){
            cnt++;
            t = s[i].first;
        }
    }
    pr(cnt);
    return 0;}