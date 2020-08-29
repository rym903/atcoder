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

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n){
        cin >> v[i];
    }
    sort(ALL(v));

    ll ans = 0;
    rep(i, v.size()) FOR(j, i+1, v.size()){
        int l = upper_bound(ALL(v), v[j] - v[i]) - v.begin();
        int r = lower_bound(ALL(v), v[j] + v[i]) - v.begin();

        // FOR(k, l, r){
        //     printf("%d ", v[k]);
        // }
        // pr("");

        if(v[i] > v[j] - v[i] && v[i] < v[j] + v[i]) r--;
        if(v[j] > v[j] - v[i] && v[j] < v[j] + v[i]) r--;

        // printf("%d %d %d\n", v[i], v[j], r-l);
        // pr("");


        ans += max(r - l, 0);
        
    }
    pr(ans/3);
    return 0;}