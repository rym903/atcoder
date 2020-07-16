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
    int h, w; cin >> h >> w;
    string s[h];
    vector<int> wallh[h], wallw[w];
    rep(i, h) cin >> s[i];

    rep(i, h) wallh[i].push_back(-1);
    rep(i, w) wallw[i].push_back(-1);
    rep(i, h) rep(j, w){
        if(s[i][j]=='#'){
            wallh[i].push_back(j);
            wallw[j].push_back(i);
        }
    }
    rep(i, h) wallh[i].push_back(w);
    rep(i, w) wallw[i].push_back(h);

    // rep(i, h) prvec(wallh[i]);
    // rep(i, w) prvec(wallw[i]);

    int ans = 0;
    rep(i, h) rep(j, w){
        if(s[i][j]=='#') continue;

        auto hp = upper_bound(ALL(wallh[i]), j);
        auto wp = upper_bound(ALL(wallw[j]), i);

        chmax(ans, *hp - *(hp-1) - 1 + *wp - *(wp-1) - 1 - 1);
    }
    pr(ans);
    return 0;}