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
using P = pair<double, double>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

struct PWS{
    double p, w, s;
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<P> p(n);
    rep(i, n){
        cin >> p[i].second >> p[i].first;
    }

    vector<double> s(n);
    double left=0, right=100, mid=50.0;
    double ans = 0;

    rep(q, 500){
        rep(i, n) s[i] = p[i].second * (p[i].first - mid) / 100.0;
        sort(s.rbegin(), s.rend());
        double sum=0;
        rep(i, k) sum += s[i];
        if(sum>=0){
            ans = mid;
            left = mid;
        }else{
            right = mid;
        }
        mid = (left+right)/2.0;
    }
    printf("%.10lf\n", ans);

    return 0;}