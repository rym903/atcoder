#include <bits/stdc++.h>
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
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int na, nb; cin >> na >> nb;
    vector<int> a(na), b(nb);
    rep(i, na) cin >> a[i];
    rep(i, nb) cin >> b[i];
    sort(ALL(a)); sort(ALL(b));
    a.push_back(INF); b.push_back(INF);
    int ai=0, bi=0;
    int uni = 0, inter = 0;
    while(!(ai==na && bi==nb)){
        int at = a[ai];
        int bt = b[bi];
        if(at==bt){
            uni++;
            inter++;
            ai++;
            bi++;
        }else if(at > bt){
            uni++;
            bi++;
        }else{
            uni++;
            ai++;
        }
    }
    pr((int)2*(int)INF);
    printf("%.10lf\n", ((double)inter / (double)uni));
    return 0;}