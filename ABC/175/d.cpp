#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define FOR(i,x,n) for(ll i=x; i<(n); i++)
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
    ll n, k; cin >> n >> k;
    vector<ll> p(n);
    vector<ll> c(n);
    rep(i, n){
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) cin >> c[i];
    ll csum = 0;
    rep(i, n) csum += c[i];
 
    // pr(csum);
 
    ll ans = -INFL;
    rep(i, n){
        chmax(ans, c[i]);
    }
 
    // if(k==1 || ans==0) {pr(ans); return 0;}
    rep(i, n){
        vector<ll> q(n, 0);
        vector<ll> path;
        ll d = 0;
        ll pos = i;
        ll mid = 0;
        path.push_back(i);
        for(d; d<min(n, k); d++){
            pos = p[pos];
            path.push_back(pos);
            mid += c[pos];
            q[pos] = mid;
            printf("%d, %d\n", c[pos], mid);
            chmax(ans, mid);
            if(pos==i) {d++; break;}
        }
        // if(min(n, k) == k) continue;
        // if(mid <= 0) continue;
 
        // prvec(q);
 
        ll loop = k / d;
        ll md = k % d;
 
        if(loop>1){
            rep(j, d){
                q[path[j]] += (loop-1)*mid;
                chmax(ans, q[path[j]]);
            }
        }
        // printf("%d, %d\n", loop, ans);
        mid = q[i];
        pos = i;
        if(loop>1){
            rep(j, md){
                pos = p[pos];
                mid += c[pos];
                chmax(ans, mid);
            }
        }
    }
 
    pr(ans);
    return 0;}