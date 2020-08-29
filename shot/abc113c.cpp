#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
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

using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

struct C{
    int pref;
    int num;
};

using PP = pair<int, C>;
int main()
{
    int n, m; cin >> n >> m;
    arr<P> G(n);
    rep(i, m){
        int p, y; cin >> p >> y;
        p--;
        G[p].push_back({y, i});
    }  
    rep(i, n) sort(ALL(G[i]));

    vector<PP> ans;

    rep(i, n) rep(j, G[i].size()){
        P p = G[i][j];
        PP pp;
        pp.first = p.second;

        pp.second.pref = i+1;
        pp.second.num =  j+1;
        ans.push_back(pp);
    }
    sort(ALL(ans), [](const PP &a, const PP &b){
        return a.first < b.first; 
    });

    rep(i, m){
        printf("%06d%06d\n", ans[i].second.pref, ans[i].second.num);
    }
    return 0;}