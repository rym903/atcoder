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
    set<int> s;
    int q; cin >> q;
    rep(i, q){
        int c, x, l ,r;
        cin >> c;
        if(c==0){
            cin >> x;
            s.insert(x);
            pr(s.size());
        }else if(c==1){
            cin >> x;
            if(s.find(x)!=s.end()) pr(1);
            else pr(0);
        }else if(c==2){
            cin >> x;
            s.erase(x);
        }else{
            cin >> l >> r;
            if(l<r){
                auto li = s.lower_bound(l);
                auto ri = s.lower_bound(r);
                for(; li!=ri; li++) pr(*li);
                if(*li==r) pr(*li);
            }if(l==r){
                if(s.find(x)!=s.end()) pr(l);
            }
        }
    }
    return 0;}