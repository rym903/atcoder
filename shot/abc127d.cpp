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
using P = pair<ll, ll>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

int main()
{
    int n, m; cin >> n >> m;
    map<ll, ll> a;
    vector<ll> a_uniq;
    rep(i, n){
        ll t; cin >> t;
        a[t]++;
        if(a[t]==1) a_uniq.push_back(t);
    }
    sort(ALL(a_uniq));

    vector<P> b;
    rep(i, m){
        ll s, t; cin >> s >> t;
        b.push_back({t, s});
    }
    sort(b.rbegin(), b.rend());

    // rep(i, b.size()){
    //     printf("%ld, %ld\n", b[i].first, b[i].second);
    // }

    int ai=0, bi=0;
    while(ai < a_uniq.size() && bi < b.size()){
        if(b[bi].first <= a_uniq[ai]) break;

        ll anum, asize;
        ll bnum, bsize;
        anum = a_uniq[ai]; asize = a[anum];
        bnum = b[bi].first; bsize = b[bi].second;

        // cout << anum << " " << asize << "| " << bnum << " " << bsize << endl;
        if(asize > bsize){
            a[anum] -= bsize;
            a[bnum] += bsize;
            bi++;
        }else if(bsize > asize){
            a[anum] = 0;
            a[bnum] += asize;
            b[bi].second -= asize;
            ai++;
        }else{
            a[anum] = 0;
            a[bnum] += bsize;
            ai++;
            bi++;
        }

        // for(auto t: a) cout << t.first << "." << t.second << " ";
        // pr("");
    }

    ll ans = 0;
    for(auto t: a) ans += t.first*t.second;
    pr(ans);
    return 0;}